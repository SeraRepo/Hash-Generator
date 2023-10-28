FROM gcc:latest

COPY . ./

WORKDIR /

RUN apt install libssl-dev

RUN make

ENTRYPOINT [ "./src/main" ]