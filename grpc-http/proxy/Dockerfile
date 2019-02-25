FROM golang as builder
RUN apt-get -qq update && apt-get -qq install -y \
  unzip
RUN curl -sSL https://github.com/protocolbuffers/protobuf/releases/download/v3.6.1/\
protoc-3.6.1-linux-x86_64.zip -o /tmp/protoc.zip && \
  cd /tmp && \
  unzip -qq protoc.zip -d /usr/local

WORKDIR /root
RUN git clone https://github.com/ajguerrer/sandbox
RUN git clone https://github.com/googleapis/googleapis

WORKDIR /root/sandbox/grpc-http
RUN protoc -I /root/googleapis -I guestbook --include_imports --include_source_info \
  --descriptor_set_out=proto.pb guestbook/guestbook.proto

FROM envoyproxy/envoy
COPY --from=builder /root/sandbox/grpc-http/proxy/envoy.yaml /etc/envoy/envoy.yaml
COPY --from=builder /root/sandbox/grpc-http/proto.pb /tmp/envoy/proto.pb
CMD /usr/local/bin/envoy -c /etc/envoy/envoy.yaml -l trace --log-path /tmp/envoy_info.log