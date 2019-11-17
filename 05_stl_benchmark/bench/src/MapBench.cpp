//
// Created by khamza on 16.11.2019.
//
#include "BenchIncludes.h"

//======================================MAP BENCHMARKS=======================================================
void MapAt(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{{{'a'}, 1}};

    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map.insert({{(char)j}, i});
    }

    for( auto _ : state )
    {
        map.at({'a'});
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapAt)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void MapOperator(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{{{'a'}, 1}};

    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map.insert({{(char)j}, i});
    }

    for( auto _ : state)
    {
        map[{'a'}] = 2;
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapOperator)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void MapEmpty(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};

    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map.insert({{(char)j}, i});
    }

    for( auto _ : state )
    {
        map.empty();
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapEmpty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void MapSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};

    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map.insert({{(char)j}, i});
    }


    for( auto _ : state)
    {
        map.size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapSize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void MapMaxSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};

    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map.insert({{(char)j}, i});
    }

    for( auto _ : state )
    {
        map.max_size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapMaxSize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void MapClear(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map.insert({{(char)j}, i});
    }

    for( auto _ : state )
    {
        map.clear();
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapClear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void MapInsert(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};

    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map.insert({{(char)j}, i});
    }

    for( auto _ : state )
    {
        map.insert({{'d'}, 4});
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapInsert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void MapErase(State& state)
{
    auto N = state.range();
    auto size = (std::size_t)N;
    //std::map<Small, int> map{{{'a'}, 1}, {{'b'}, 2 }, {{'c'}, 3}};
    std::map<Small, int> map{};

    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map.insert({{(char)j}, i});
    }

    for( auto _ : state )
    {
        map.erase({'a'});
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapErase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void MapSwap(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map_1{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map_1.insert({{(char)j}, i});
    }

    std::map<Small, int> map_2{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map_2.insert({{(char)j}, i});
    }

    for( auto _ : state )
    {
        map_1.swap(map_2);
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapSwap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void MapCount(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};

    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map.insert({{(char)j}, i});
    }

    for( auto _ : state )
    {
        map.count({'a'});
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapCount)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void MapFind(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};

    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map.insert({{(char)j}, i});
    }

    for( auto _ : state )
    {
        map.find({'c'});
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapFind)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void MapEqualRange(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};

    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map.insert({{(char)j}, i});
    }

    for( auto _ : state )
    {
        map.equal_range({'b'});
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapEqualRange)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void MapLowerBound(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};

    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map.insert({{(char)j}, i});
    }

    for( auto _ : state )
    {
        map.lower_bound({'c'});
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapLowerBound)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void MapUpperBound(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};

    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map.insert({{(char)j}, i});
    }

    for( auto _ : state )
    {
        map.upper_bound({'a'});
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapUpperBound)->RangeMultiplier(2)->Range(1, 1024)->Complexity();