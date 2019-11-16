//
// Created by khamza on 16.11.2019.
//
#include "BenchIncludes.h"

//======================================UNORDERED MULTISET BENCHMARKS=======================================================

void UnorderedMultisetEmpty(State& state)
{
    std::unordered_multiset<Small> unorderedMultiset{};

    for( auto _ : state )
    {
        unorderedMultiset.empty();
    }
}
BENCHMARK(UnorderedMultisetEmpty);

void UnorderedMultisetSize(State& state)
{
    std::unordered_multiset<Small> unorderedMultiset{};

    for ( auto _ : state )
    {
        unorderedMultiset.size();
    }
}
BENCHMARK(UnorderedMultisetSize);

void UnorderedMultisetMaxSize(State& state)
{
    std::unordered_multiset<Small> unorderedMultiset{};

    for( auto _ : state )
    {
        unorderedMultiset.max_size();
    }
}
BENCHMARK(UnorderedMultisetMaxSize);

void UnorderedMultisetClear(State& state)
{
    std::unordered_multiset<Small> unorderedMultiset{{{1}}, {{2}}, {{3}}};
    //std::unordered_multiset<Small> unorderedMultiset{};

    for( auto _ : state )
    {
        unorderedMultiset.clear();
    }
}
BENCHMARK(UnorderedMultisetClear);

void UnorderedMultisetInsert(State& state)
{
    std::unordered_multiset<Small> unorderedMultiset{};

    for( auto _ : state )
    {
        unorderedMultiset.insert({'a'});
    }
}
BENCHMARK(UnorderedMultisetInsert);

void UnorderedMultisetErase(State& state)
{
    //std::unordered_multiset<Small> unorderedMultiset{};
    std::unordered_multiset<Small> unorderedMultiset{{{'a'}}, {{2}}, {{3}}};

    for( auto _ : state )
    {
        unorderedMultiset.erase({{'a'}});
    }
}
BENCHMARK(UnorderedMultisetErase);

void UnorderedMultisetSwap(State& state)
{
    std::unordered_multiset<Small> unorderedMultiset_1{{{'a'}}, {{2}}, {{3}}};
    std::unordered_multiset<Small> unorderedMultiset_2{};

    for( auto _ : state )
    {
        unorderedMultiset_2.swap(unorderedMultiset_1);
    }
}
BENCHMARK(UnorderedMultisetSwap);

void UnorderedMultisetCount(State& state)
{
    //std::unordered_multiset<Small> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}};
    std::unordered_multiset<Small> unorderedMultiset{}; //bigger size == more time

    for( auto _ : state )
    {
        unorderedMultiset.count({'a'});
    }
}
BENCHMARK(UnorderedMultisetCount);

void UnorderedMultisetFind(State& state)
{
    //std::unordered_multiset<Small> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}};
    std::unordered_multiset<Small> unorderedMultiset{}; //bigger size == more time

    for( auto _ : state )
    {
        unorderedMultiset.find({'b'});
    }
}
BENCHMARK(UnorderedMultisetFind);

void UnorderedMultisetEqualRange(State& state)
{
    //std::unordered_multiset<Small> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}};
    std::unordered_multiset<Small> unorderedMultiset{};

    for( auto _ : state )
    {
        unorderedMultiset.equal_range({{'b'}});
    }
}
BENCHMARK(UnorderedMultisetEqualRange);

void UnorderedMultisetRehash(State& state)
{
    std::unordered_multiset<Small> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}};
    //std::unordered_multiset<Small> unorderedMultiset{};

    for( auto _ : state )
    {
        unorderedMultiset.rehash(200);
    }
}
BENCHMARK(UnorderedMultisetRehash);

void UnorderedMultisetReserve(State& state)
{
    std::unordered_multiset<Small> unorderedMultiset{{{'a'}}, {{'a'}}, {{'a'}}, {{'b'}}, {{'d'}}};
    //std::unordered_multiset<Small> unorderedMultiset{};

    for( auto _ : state )
    {
        unorderedMultiset.reserve(2);
    }
}
BENCHMARK(UnorderedMultisetReserve);