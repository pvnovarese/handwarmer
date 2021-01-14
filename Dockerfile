FROM fedora:latest AS builder

WORKDIR /handwarmer
RUN dnf -y install gcc glibc-static
COPY ./handwarmer.c /handwarmer/handwarmer.c
RUN gcc -static handwarmer.c -o handwarmer

FROM scratch
MAINTAINER Paul Novarese pvn@novarese.net
LABEL maintainer="pvn@novarese.net"
LABEL name="handwarmer"
LABEL org.opencontainers.image.title="handwarmer"
LABEL org.opencontainers.image.source="https://gist.github.com/silentbicycle/8223201"
LABEL org.opencontainers.image.description="Code written by Scott Vokes \
 \
https://gist.github.com/silentbicycle/8223201 https://twitter.com/silentbicycle \
 \
Usage: docker run pvnovarese/handwarmer [N] \
N= number of cores, default for this image is 1."
COPY --from=builder /handwarmer/handwarmer /handwarmer
CMD ["1"]
ENTRYPOINT ["/handwarmer"]
