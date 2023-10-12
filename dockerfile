FROM gcc:latest

COPY . ./

WORKDIR /

RUN make

ENTRYPOINT [ "./src/main" ]