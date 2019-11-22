//
// Created by khamza on 16.11.2019.
//
#include "BenchIncludes.h"

//======================================UNORDERED MULTISET BENCHMARKS SMALL=======================================================

void UnorderedMultisetEmpty(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Small> unorderedMultiset{};
    unorderedMultiset.reserve(size);

    for( auto _ : state )
    {
        DoNotOptimize(unorderedMultiset.empty());
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMultisetEmpty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void UnorderedMultisetSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Small> unorderedMultiset{};
    unorderedMultiset.reserve(size);

    for ( auto _ : state )
    {
        DoNotOptimize(unorderedMultiset.size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMultisetSize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void UnorderedMultisetMaxSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Small> unorderedMultiset{};
    unorderedMultiset.reserve(size);

    for( auto _ : state )
    {
        DoNotOptimize(unorderedMultiset.max_size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMultisetMaxSize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void UnorderedMultisetClear(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Small m{};

    for( auto _ : state )
    {
        state.PauseTiming();
            std::unordered_multiset<Small> unorderedMultiset{};

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
BENCHMARK(UnorderedMultisetClear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void UnorderedMultisetInsert(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multiset<Small> unorderedMultiset{};
    unorderedMultiset.reserve(size);
    Small m{};

    for( auto _ : state )
    {
        m.randomize();
        unorderedMultiset.insert(m);
        ClobberMemory();

        state.PauseTiming();
            unorderedMultiset.erase(m);
        state.ResumeTiming();
        DoNotOptimize(unorderedMultiset);
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMultisetInsert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void UnorderedMultisetErase(State& state)
{
    //std::unordered_multiset<Small> unorderedMultiset{};
    //std::unordered_multiset<Small> unorderedMultiset{{{'a'}}, {{2}}, {{3}}};

    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Small> unorderedMultiset{};
    unorderedMultiset.reserve(size);
    Small m{};

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
BENCHMARK(UnorderedMultisetErase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void UnorderedMultisetSwap(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Small> unorderedMultiset_1{};
    Small m{};
    for(auto i = 0; i<size; i++)
    {
        m.randomize();
        unorderedMultiset_1.insert(m);
    }

    std::unordered_multiset<Small> unorderedMultiset_2{};
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
BENCHMARK(UnorderedMultisetSwap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void UnorderedMultisetCount(State& state)
{
    //std::unordered_multiset<Small> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}};
   // std::unordered_multiset<Small> unorderedMultiset{}; //bigger size == more time
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Small m{};
    std::unordered_multiset<Small> unorderedMultiset{};

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
BENCHMARK(UnorderedMultisetCount)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void UnorderedMultisetFind(State& state)
{
    //std::unordered_multiset<Small> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}};
   // std::unordered_multiset<Small> unorderedMultiset{}; //bigger size == more time
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Small> unorderedMultiset{};
    unorderedMultiset.reserve(size);
    Small m{};

    for( auto _ : state )
    {
        m.randomize();
        DoNotOptimize(unorderedMultiset.find(m));
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMultisetFind)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void UnorderedMultisetEqualRange(State& state)
{
    //std::unordered_multiset<Small> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}};
    //std::unordered_multiset<Small> unorderedMultiset{};
    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multiset<Small> unorderedMultiset{};
    unorderedMultiset.reserve(size);
    Small m{};

    for( auto _ : state )
    {
        m.randomize();
        DoNotOptimize(unorderedMultiset.equal_range(m));
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMultisetEqualRange)->RangeMultiplier(2)->Range(1, 256)->Complexity();

void UnorderedMultisetRehash(State& state)
{
    //std::unordered_multiset<Small> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}};
    //std::unordered_multiset<Small> unorderedMultiset{};
    auto N = state.range(0);
    auto size = (std::size_t)N;

    for( auto _ : state )
    {
        state.PauseTiming();
            std::unordered_multiset<Small> unorderedMultiset{};
            unorderedMultiset.reserve(size);
            auto value = rand()%size;
        state.ResumeTiming();
        DoNotOptimize(unorderedMultiset);

        unorderedMultiset.rehash(value);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMultisetRehash)->RangeMultiplier(2)->Range(1, 2<<11)->Complexity();//patrzac na wyniki widac ze zlozonosc jest liniowa ale wynik jest "splycany" do stalego

void UnorderedMultisetReserve(State& state)
{
    //std::unordered_multiset<Small> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}, {{'d'}}};
    //std::unordered_multiset<Small> unorderedMultiset{};
    auto N = state.range(0);
    auto size = (std::size_t)N;

    for( auto _ : state )
    {
        state.PauseTiming();
            std::unordered_multiset<Small> unorderedMultiset{};
            unorderedMultiset.reserve(size);

            auto value = rand()%size;
        state.ResumeTiming();
        DoNotOptimize(unorderedMultiset);

        unorderedMultiset.reserve(value);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMultisetReserve)->RangeMultiplier(2)->Range(1, 2<<11)->Complexity(); //patrzac na wyniki widac ze zlozonosc jest liniowa ale wynik jest "splycany" do stalego