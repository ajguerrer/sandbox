FROM ubuntu:18.04
RUN apt-get update && apt-get install -y curl gnupg ninja-build make git

RUN echo "deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic main\ 
deb-src http://apt.llvm.org/bionic/ llvm-toolchain-bionic main" >> /etc/apt/sources.list
RUN curl -ssL https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -
RUN apt-get update && apt-get install -y clang-9 clang-tidy-9 && rm -rf /var/lib/apt/lists/*
RUN update-alternatives --install /usr/bin/clang clang /usr/bin/clang-9 100
RUN update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-9 100
RUN update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-9 100

RUN curl -ssL https://github.com/Kitware/CMake/releases/download/v3.14.0/cmake-3.14.0-Linux-x86_64.tar.gz | tar --strip-components=1 -xz -C /usr/local

WORKDIR /workspace