FROM debian:trixie

RUN apt-get update && apt-get install -y g++ make libboost-all-dev && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN chmod +x launch.sh

CMD ["./launch.sh"]
