FROM gcc:latest

COPY . ./

WORKDIR /

RUN make

CMD [ "./src/main" ]