# ROOT (CERN) base image
FROM rootproject/root:latest

# Install build tools
RUN apt-get update && apt-get install -y \
    cmake \
    ninja-build \
    g++ \
    clang \
    clang-tidy \
    gdb \
    valgrind \
    perf \
    python3 \
    python3-pip \
    git \
    && rm -rf /var/lib/apt/lists/*

# Install Python tooling (docs/tests)
RUN python3 -m pip install --break-system-packages \
    pytest \
    pytest-cov \
    mkdocs \
    mkdocs-material

# Default working directory
WORKDIR /work

