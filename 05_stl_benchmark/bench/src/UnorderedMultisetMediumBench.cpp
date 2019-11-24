//
// Created by khamza on 16.11.2019.
//
#include "BenchIncludes.h"

//======================================UNORDERED MULTISET BENCHMARKS MEDIUM=======================================================

void UnorderedMediumMultisetEmpty(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Medium> unorderedMultiset{};
    unorderedMultiset.reserve(size);

    for( auto _ : state )
    {
        DoNotOptimize(unorderedMultiset.empty());
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMediumMultisetEmpty)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void UnorderedMediumMultisetSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Medium> unorderedMultiset{};
    unorderedMultiset.reserve(size);

    for ( auto _ : state )
    {
        DoNotOptimize(unorderedMultiset.size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMediumMultisetSize)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void UnorderedMediumMultisetMaxSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Medium> unorderedMultiset{};
    unorderedMultiset.reserve(size);

    for( auto _ : state )
    {
        DoNotOptimize(unorderedMultiset.max_size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMediumMultisetMaxSize)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void UnorderedMediumMultisetClear(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Medium m{};

    for( auto _ : state )
    {
        state.PauseTiming();
        std::unordered_multiset<Medium> unorderedMultiset{};

        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            unorderedMultiset.insert(m);
        }
        state.ResumeTiming();
        DoNotOptimize(unorderedMultiset);

        unorderedMultiset.clear();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMediumMultisetClear)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void UnorderedMediumMultisetInsert(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multiset<Medium> unorderedMultiset{};
    unorderedMultiset.reserve(size);
    Medium m{};

    for( auto _ : state )
    {
        m.randomize();
        DoNotOptimize(unorderedMultiset.insert(m));
        ClobberMemory();

        state.PauseTiming();
        unorderedMultiset.erase(m);
        state.ResumeTiming();
        DoNotOptimize(unorderedMultiset);
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMediumMultisetInsert)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void UnorderedMediumMultisetErase(State& state)
{
    //std::unordered_multiset<Medium> unorderedMultiset{};
    //std::unordered_multiset<Medium> unorderedMultiset{{{'a'}}, {{2}}, {{3}}};

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Medium> unorderedMultiset{};
    unorderedMultiset.reserve(size);
    Medium m{};

    for( auto _ : state )
    {
        state.PauseTiming();
        m.randomize();
        unorderedMultiset.insert(m);
        state.ResumeTiming();

        DoNotOptimize(unorderedMultiset.erase(m));
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMediumMultisetErase)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void UnorderedMediumMultisetSwap(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Medium> unorderedMultiset_1{};
    Medium m{};
    for(auto i = 0; i<size; i++)
    {
        m.randomize();
        unorderedMultiset_1.insert(m);
    }

    std::unordered_multiset<Medium> unorderedMultiset_2{};
    for(auto i = 0; i<size; i++)
    {
        m.randomize();
        unorderedMultiset_2.insert(m);
    }

    for( auto _ : state )
    {
        DoNotOptimize(unorderedMultiset_1); DoNotOptimize(unorderedMultiset_2);
        unorderedMultiset_2.swap(unorderedMultiset_1);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMediumMultisetSwap)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void UnorderedMediumMultisetCount(State& state)
{
    //std::unordered_multiset<Medium> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}};
    // std::unordered_multiset<Medium> unorderedMultiset{}; //bigger size == more time
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Medium m{};
    std::unordered_multiset<Medium> unorderedMultiset{};

    for(auto i = 0; i<size; i++)
    {
        m.randomize();
        unorderedMultiset.insert(m);
    }

    for( auto _ : state )
    {
        DoNotOptimize(unorderedMultiset.count(m));
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMediumMultisetCount)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void UnorderedMediumMultisetFind(State& state)
{
    //std::unordered_multiset<Medium> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}};
    // std::unordered_multiset<Medium> unorderedMultiset{}; //bigger size == more time
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Medium> unorderedMultiset{};
    unorderedMultiset.reserve(size);
    Medium m{};

    for( auto _ : state )
    {
        m.randomize();
        DoNotOptimize(unorderedMultiset.find(m));
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMediumMultisetFind)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void UnorderedMediumMultisetEqualRange(State& state)
{
    //std::unordered_multiset<Medium> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}};
    //std::unordered_multiset<Medium> unorderedMultiset{};
    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multiset<Medium> unorderedMultiset{};
    unorderedMultiset.reserve(size);
    Medium m{};

    for( auto _ : state )
    {
        m.randomize();
        DoNotOptimize(unorderedMultiset.equal_range(m));
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMediumMultisetEqualRange)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void UnorderedMediumMultisetRehash(State& state)
{
    //std::unordered_multiset<Medium> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}};
    //std::unordered_multiset<Medium> unorderedMultiset{};
    auto N = state.range(0);
    auto size = (std::size_t)N;

    for( auto _ : state )
    {
        state.PauseTiming();
        std::unordered_multiset<Medium> unorderedMultiset{};
        unorderedMultiset.reserve(size);
        auto value = rand()%size;
        state.ResumeTiming();
        DoNotOptimize(unorderedMultiset);

        unorderedMultiset.rehash(value);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMediumMultisetRehash)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();//patrzac na wyniki widac ze zlozonosc jest liniowa ale wynik jest "splycany" do stalego

void UnorderedMediumMultisetReserve(State& state)
{
    //std::unordered_multiset<Medium> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}, {{'d'}}};
    //std::unordered_multiset<Medium> unorderedMultiset{};
    auto N = state.range(0);
    auto size = (std::size_t)N;

    for( auto _ : state )
    {
        state.PauseTiming();
        std::unordered_multiset<Medium> unorderedMultiset{};
        unorderedMultiset.reserve(size);

        auto value = rand()%size;
        state.ResumeTiming();
        DoNotOptimize(unorderedMultiset);

        unorderedMultiset.reserve(value);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMediumMultisetReserve)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity(); //patrzac na wyniki widac ze zlozonosc jest liniowa ale wynik jest "splycany" do stalego