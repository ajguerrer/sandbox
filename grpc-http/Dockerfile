FROM golang:alpine
RUN apk update && apk add git
COPY . /go/src/app
RUN go get -v app/server
RUN go install app/server
ENTRYPOINT ["/go/bin/server"]
