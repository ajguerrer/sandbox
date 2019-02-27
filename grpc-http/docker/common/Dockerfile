FROM golang

RUN apt-get -qq update && apt-get -qq install -y unzip
RUN curl -sSL https://github.com/protocolbuffers/protobuf/releases/download/v3.6.1/protoc-3.6.1-linux-x86_64.zip\
  -o /tmp/protoc.zip && unzip -qq /tmp/protoc.zip -d /usr/local
RUN go get -u github.com/golang/protobuf/protoc-gen-go

WORKDIR /root
RUN git clone https://github.com/googleapis/googleapis
COPY . .
RUN protoc -I /root/googleapis -I guestbook --include_imports --include_source_info \
  --descriptor_set_out=proto.pb --go_out=plugins:guestbook guestbook/guestbook.proto
RUN CGO_ENABLED=0 GOOS=linux go install -a -installsuffix cgo ./...