# SD-E2 Benchmark and Optimize

This exercise focuses on using microbenchmarks to identify slow code paths and then applying targeted optimizations.

## Goals

- Learn the basics of Google Benchmark
- Identify expensive operations (e.g., `std::pow`)
- Improve code through refactoring and compiler-friendly loops

## Where to work

Go to:

- `exercises/SD-E2-benchmark-and-optimize/starter/`

## Expected tasks

- Replace `std::pow(x, 2)` with `x*x`
- Reduce unnecessary temporary allocations
- Improve data layout and loop structure
- Compare benchmark results before vs after

