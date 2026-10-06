FROM gcc:latest AS build

COPY . /usr/src/k
WORKDIR /usr/src/k

RUN echo -std=gnu99 >> /usr/src/k/opts && make c && make k libk.so

FROM debian

COPY --from=build /usr/src/k/k /usr/bin/k
COPY --from=build /usr/src/k/libk.so /usr/lib/libk.so

CMD ["/usr/bin/k"]