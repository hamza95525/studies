#include "Large.h"
#include "BenchIncludes.h"
// TODO: Add benchmarks for operator<. operator==, and hash
void LargeLessThan(State& state){
    Large large_1{};
    Large large_2{};
    large_1.randomize();
    large_2.randomize();
    for(auto _ : state){
        auto result = large_1 < large_2;
        DoNotOptimize(result);
    }
}
BENCHMARK(LargeLessThan);
void LargeEqual(State& state){
    Large large_1{};
    Large large_2{};
    large_1.randomize();
    large_2.randomize();
    for(auto _ : state){
        auto result = large_1 == large_2;
        DoNotOptimize(result);
    }
}
BENCHMARK(LargeEqual);
void LargeHash(State& state){
    Large large{};
    std::hash<Large> hashVal;
    large.randomize();
    for(auto _ : state){
        auto result = hashVal(large);
        DoNotOptimize(result);
    }
}
BENCHMARK(LargeHash);
