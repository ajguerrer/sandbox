package main

import (
	"context"
	"flag"
	"fmt"
	"log"
	"math"
	"net"

	"github.com/google/uuid"
	"google.golang.org/grpc"
	"google.golang.org/grpc/codes"
	"google.golang.org/grpc/status"

	pb "sandbox/grpc-http/guestbook"
)

var port = flag.Int("port", 8000, "The server port")

type guestbookServer struct {
	posts []*pb.Post
}

func main() {
	flag.Parse()
	lis, err := net.Listen("tcp", fmt.Sprintf("localhost:%d", *port))
	if err != nil {
		log.Fatalf("failed to listen: %v", err)
	}
	s := grpc.NewServer()
	pb.RegisterGuestBookServer(s, newServer())
	if err := s.Serve(lis); err != nil {
		log.Fatalf("failed to serve: %v", err)
	}
}

func newServer() *guestbookServer {
	return &guestbookServer{posts: []*pb.Post{
		{Title: "First post", Body: "This is the first post"},
		{Title: "Second post", Body: "This is the second post"},
	}}
}

func (s *guestbookServer) AddPost(ctx context.Context, req *pb.AddPostRequest) (*pb.AddPostResponse, error) {
	if req.Title == "" {
		return nil, status.Error(codes.InvalidArgument, "Title is required")
	}
	if req.Body == "" {
		return nil, status.Error(codes.InvalidArgument, "Body is required")
	}

	id := uuid.New().String()
	s.posts = append(s.posts, &pb.Post{
		Title: req.Title,
		Body:  req.Body,
		Id:    id,
	})
	return &pb.AddPostResponse{Id: id}, nil
}

func (s *guestbookServer) UpdatePost(ctx context.Context, req *pb.UpdatePostRequest) (*pb.UpdatePostResponse, error) {
	for _, post := range s.posts {
		if post.Id == req.Id {
			post.Title = req.Title
			post.Body = req.Body
			return &pb.UpdatePostResponse{}, nil
		}
	}
	return nil, status.Errorf(codes.NotFound, "Post with id %v not found", req.Id)
}

func (s *guestbookServer) ListPosts(ctx context.Context, req *pb.ListPostsRequest) (*pb.ListPostsResponse, error) {
	page := int(math.Abs(float64(req.Page)))
	pageSize := int(math.Abs(float64(req.PageSize)))
	if pageSize == 0 {
		pageSize = 10
	}
	start := page * pageSize
	if start > len(s.posts) {
		return &pb.ListPostsResponse{}, nil
	}
	end := (page + 1) * pageSize
	if end > len(s.posts) {
		end = len(s.posts)
	}

	return &pb.ListPostsResponse{Posts: s.posts[start:end]}, nil
}
