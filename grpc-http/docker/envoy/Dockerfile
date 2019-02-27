FROM grpchttp/common as tmp

FROM envoyproxy/envoy
COPY --from=tmp /root/proxy/envoy.yaml /etc/envoy/envoy.yaml
COPY --from=tmp /root/proto.pb /tmp/envoy/proto.pb