FROM grpchttp/common as tmp

FROM scratch
COPY --from=tmp /go/bin/server /
COPY --from=tmp /go/bin/client /
EXPOSE 9090
CMD ["/server"]
