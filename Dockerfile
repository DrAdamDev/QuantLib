FROM ubuntu
RUN apt-get update && apt-get install -y g++ cmake
RUN apt-get update && apt-get install -y libboost-all-dev
COPY . /QuantLibExamples
WORKDIR /QuantLibExamples
RUN cmake -S . -B build
RUN cmake --build build
CMD	["./build/ExampleModels"]
