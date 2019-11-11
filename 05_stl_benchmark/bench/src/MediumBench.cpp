#include "Medium.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash
void MediumLessThan(State& state){
    Medium medium_1{};
    Medium medium_2{};

    medium_1.randomize();
    medium_2.randomize();

    for( auto _ : state){
        auto result = medium_1 < medium_2;
        DoNotOptimize(result);
    }
}
BENCHMARK(MediumLessThan);

void MediumEqual(State& state){
    Medium medium_1{};
    Medium medium_2{};

    medium_1.randomize();
    medium_2.randomize();

    for( auto _ : state){
        auto result = medium_1 == medium_2;
        DoNotOptimize(result);
    }
}
BENCHMARK(MediumEqual);


void MediumHash(State& state){
    Medium medium{};
    std::hash<Medium> hashVal;

    medium.randomize();

    for( auto _ : state){
        auto result = hashVal(medium);
        DoNotOptimize( result );
    }
}
BENCHMARK(MediumHash);
