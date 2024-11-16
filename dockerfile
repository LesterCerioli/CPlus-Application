# Use an official Ubuntu as a parent image
FROM ubuntu:20.04

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive
ENV CXX=g++

# Install dependencies
RUN apt-get update && \
    apt-get install -y build-essential libssl-dev zlib1g-dev \
    libncurses5-dev libncursesw5-dev libreadline-dev libsqlite3-dev \
    libgdbm-dev libdb5.3-dev libbz2-dev libexpat1-dev liblzma-dev \
    libffi-dev wget cmake libboost-all-dev libopencv-dev libcurl4-openssl-dev

# Create a directory for the application
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . /app

# Build the project
RUN mkdir build && cd build && cmake .. && make

# Make port 8080 available to the world outside this container
EXPOSE 8080

# Run the application
CMD ["./build/CPlus-Application"]
