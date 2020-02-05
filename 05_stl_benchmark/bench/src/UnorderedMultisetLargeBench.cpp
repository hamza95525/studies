//
// Created by khamza on 16.11.2019.
//
#include "BenchIncludes.h"
//======================================UNORDERED MULTISET BENCHMARKS LARGE=======================================================
/*void UnorderedLargeMultisetEmpty(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Large> unorderedMultiset{};
    unorderedMultiset.reserve(size);
    for( auto _ : state )
    {
        DoNotOptimize(unorderedMultiset.empty());
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedLargeMultisetEmpty)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();
void UnorderedLargeMultisetSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Large> unorderedMultiset{};
    unorderedMultiset.reserve(size);
    for ( auto _ : state )
    {
        DoNotOptimize(unorderedMultiset.size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedLargeMultisetSize)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();
void UnorderedLargeMultisetMaxSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Large> unorderedMultiset{};
    unorderedMultiset.reserve(size);
    for( auto _ : state )
    {
        DoNotOptimize(unorderedMultiset.max_size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedLargeMultisetMaxSize)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();
*/
void UnorderedLargeMultisetClear(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Large m{};
    for( auto _ : state )
    {
        //state.PauseTiming();
        std::unordered_multiset<Large> unorderedMultiset{};
        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            unorderedMultiset.insert(m);
        }
        //state.ResumeTiming();
        DoNotOptimize(unorderedMultiset);
        unorderedMultiset.clear();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedLargeMultisetClear)->RangeMultiplier(2)->Range(1, 2<<3)->Complexity();
void UnorderedLargeMultisetInsert(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Large> unorderedMultiset{};
    unorderedMultiset.reserve(size);
    Large m{};
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
BENCHMARK(UnorderedLargeMultisetInsert)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();
void UnorderedLargeMultisetErase(State& state)
{
    //std::unordered_multiset<Large> unorderedMultiset{};
    //std::unordered_multiset<Large> unorderedMultiset{{{'a'}}, {{2}}, {{3}}};
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Large> unorderedMultiset{};
    unorderedMultiset.reserve(size);
    Large m{};
    for( auto _ : state )
    {
        //state.PauseTiming();
        m.randomize();
        unorderedMultiset.insert(m);
        //state.ResumeTiming();
        DoNotOptimize(unorderedMultiset.erase(m));
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedLargeMultisetErase)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();
void UnorderedLargeMultisetSwap(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Large> unorderedMultiset_1{};
    Large m{};
    for(auto i = 0; i<size; i++)
    {
        m.randomize();
        unorderedMultiset_1.insert(m);
    }
    std::unordered_multiset<Large> unorderedMultiset_2{};
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
BENCHMARK(UnorderedLargeMultisetSwap)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();
void UnorderedLargeMultisetCount(State& state)
{
    //std::unordered_multiset<Large> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}};
    // std::unordered_multiset<Large> unorderedMultiset{}; //bigger size == more time
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Large m{};
    std::unordered_multiset<Large> unorderedMultiset{};
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
BENCHMARK(UnorderedLargeMultisetCount)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();
void UnorderedLargeMultisetFind(State& state)
{
    //std::unordered_multiset<Large> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}};
    // std::unordered_multiset<Large> unorderedMultiset{}; //bigger size == more time
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Large> unorderedMultiset{};
    unorderedMultiset.reserve(size);
    Large m{};
    for( auto _ : state )
    {
        m.randomize();
        DoNotOptimize(unorderedMultiset.find(m));
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedLargeMultisetFind)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();
void UnorderedLargeMultisetEqualRange(State& state)
{
    //std::unordered_multiset<Large> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}};
    //std::unordered_multiset<Large> unorderedMultiset{};
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Large> unorderedMultiset{};
    unorderedMultiset.reserve(size);
    Large m{};
    for( auto _ : state )
    {
        m.randomize();
        DoNotOptimize(unorderedMultiset.equal_range(m));
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedLargeMultisetEqualRange)->RangeMultiplier(2)->Range(1, 256)->Complexity();
void UnorderedLargeMultisetRehash(State& state)
{
    //std::unordered_multiset<Large> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}};
    //std::unordered_multiset<Large> unorderedMultiset{};
    auto N = state.range(0);
    auto size = (std::size_t)N;
    for( auto _ : state )
    {
        //state.PauseTiming();
        std::unordered_multiset<Large> unorderedMultiset{};
        unorderedMultiset.reserve(size);
        auto value = rand()%size;
        //state.ResumeTiming();
        DoNotOptimize(unorderedMultiset);
        unorderedMultiset.rehash(value);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedLargeMultisetRehash)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();//patrzac na wyniki widac ze zlozonosc jest liniowa ale wynik jest "splycany" do stalego
void UnorderedLargeMultisetReserve(State& state)
{
    //std::unordered_multiset<Large> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}, {{'d'}}};
    //std::unordered_multiset<Large> unorderedMultiset{};
    auto N = state.range(0);
    auto size = (std::size_t)N;
    for( auto _ : state )
    {
     //   state.PauseTiming();
        std::unordered_multiset<Large> unorderedMultiset{};
        unorderedMultiset.reserve(size);
        auto value = rand()%size;
        //state.ResumeTiming();
        DoNotOptimize(unorderedMultiset);
        unorderedMultiset.reserve(value);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedLargeMultisetReserve)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity(); //patrzac na wyniki widac ze zlozonosc jest liniowa ale wynik jest "splycany" do stalego
