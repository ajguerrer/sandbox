package main

import (
	"context"
	"flag"
	"log"
	"time"

	"google.golang.org/grpc"

	pb "sandbox/grpc-http/guestbook"
)

var serverAddr = flag.String("server_addr", "127.0.0.1:8000", "The server address in the format of host:port")

func main() {
	flag.Parse()
	conn, err := grpc.Dial(*serverAddr, grpc.WithInsecure())
	if err != nil {
		log.Fatalf("failed to dial: %v", err)
	}
	defer conn.Close()
	c := pb.NewGuestBookClient(conn)
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()
	res, err := c.ListPosts(ctx, &pb.ListPostsRequest{})
	if err != nil {
		log.Fatalf("failed to list posts: %v", err)
	}
	for _, post := range res.Posts {
		log.Printf("Post: %v", post)
	}
}
