#include "Small.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash
void SmallLessThan(State& state){
   // auto N = state.range(0);
    Small small_1{};
    Small small_2{};
    small_1.randomize(); //giving random values to object of Small class//
    small_2.randomize();


    for( auto _ : state){
        auto result = small_1 < small_2;
        DoNotOptimize( result );
    }

    //state.SetComplexityN(N);
}
BENCHMARK(SmallLessThan);

void SmallEqual(State& state){
    Small small_1{};
    Small small_2{};

    small_1.randomize();
    small_2.randomize();

    for( auto _ : state){
        auto result = small_1 == small_2;
        DoNotOptimize( result );
    }
}
BENCHMARK(SmallEqual);

void SmallHash(State& state){
    Small small{};
    std::hash<Small> hashVal;

    small.randomize();

    for( auto _ : state){
        auto result = hashVal(small);
        DoNotOptimize( result );
    }
}
BENCHMARK(SmallHash);