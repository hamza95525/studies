//
// Created by khamza on 16.11.2019.
//
#include "BenchIncludes.h"

//======================================UNORDERED MULTISET BENCHMARKS=======================================================

void UnorderedMultisetEmpty(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::unordered_multiset<Small> unorderedMultiset{};
    unorderedMultiset.reserve(size);

    for(auto i = 0; i<size; i++)
    {
        unorderedMultiset.insert({(char)i});
    }

    for( auto _ : state )
    {
        unorderedMultiset.empty();
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
    for(auto i = 0; i<size; i++)
    {
        unorderedMultiset.insert({(char)i});
    }

    for ( auto _ : state )
    {
        unorderedMultiset.size();
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
    for(auto i = 0; i<size; i++)
    {
        unorderedMultiset.insert({(char)i});
    }

    for( auto _ : state )
    {
        unorderedMultiset.max_size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMultisetMaxSize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void UnorderedMultisetClear(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;


    for( auto _ : state )
    {
        state.PauseTiming();
            std::unordered_multiset<Small> unorderedMultiset{};
            unorderedMultiset.reserve(size);
            for(auto i = 0; i<size; i++)
            {
                unorderedMultiset.insert({(char)i});
            }
        state.ResumeTiming();

        unorderedMultiset.clear();
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
    for(auto i = 0; i<size; i++)
    {
        unorderedMultiset.insert({(char)i});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto value = rand() % size;
        state.ResumeTiming();

        unorderedMultiset.insert({(char)value});

        state.PauseTiming();
            unorderedMultiset.erase({{(char)value}});
        state.ResumeTiming();
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
    for(auto i = 0; i<size; i++)
    {
        unorderedMultiset.insert({(char)i});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto value = rand() % size;
            unorderedMultiset.insert({(char)value});
        state.ResumeTiming();

        unorderedMultiset.erase({{(char)value}});
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMultisetErase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void UnorderedMultisetSwap(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::unordered_multiset<Small> unorderedMultiset_1{};
    unorderedMultiset_1.reserve(size);
    for(auto i = 0; i<size; i++)
    {
        unorderedMultiset_1.insert({(char)i});
    }

    std::unordered_multiset<Small> unorderedMultiset_2{};
    unorderedMultiset_2.reserve(size);
    for(auto i = 0; i<size; i++)
    {
        unorderedMultiset_2.insert({(char)i});
    }

    for( auto _ : state )
    {
        unorderedMultiset_2.swap(unorderedMultiset_1);
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

    std::unordered_multiset<Small> unorderedMultiset{};
    unorderedMultiset.reserve(size);
    for(auto i = 0; i<size; i++)
    {
        unorderedMultiset.insert({(char)i});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto value = rand() % size;
        state.ResumeTiming();
        unorderedMultiset.count({(char)value});
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
    for(auto i = 0; i<size; i++)
    {
        unorderedMultiset.insert({(char)i});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto value = rand() % size;
        state.ResumeTiming();

        unorderedMultiset.find({(char)value});
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

    for( auto _ : state )
    {
        state.PauseTiming();
            std::unordered_multiset<Small> unorderedMultiset{};
            unorderedMultiset.reserve(size);
            for(auto i = 0; i<size; i++)
            {
                unorderedMultiset.insert({(char)i});
            }
            auto value = rand() % size;
        state.ResumeTiming();

        unorderedMultiset.equal_range({{(char)value}});
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMultisetEqualRange)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

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
            for(auto i = 0; i<size; i++)
            {
                unorderedMultiset.insert({(char)i});
            }
            auto value = rand()%size;
        state.ResumeTiming();

        unorderedMultiset.rehash(value);
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMultisetRehash)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

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
            for(auto i = 0; i<size; i++)
            {
                unorderedMultiset.insert({(char)i});
            }
            auto value = rand()%size;
        state.ResumeTiming();
        unorderedMultiset.reserve(value);
    }
    state.SetComplexityN(N);
}
BENCHMARK(UnorderedMultisetReserve)->RangeMultiplier(2)->Range(1, 1024)->Complexity();