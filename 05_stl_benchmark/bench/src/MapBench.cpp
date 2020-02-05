//
// Created by khamza on 21.11.2019.
//
//
// Created by khamza on 16.11.2019.
//
#include "BenchIncludes.h"
//======================================MAP BENCHMARKS SMALL=======================================================
void MapSmallAt(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};
    Small m{};
    m.randomize();
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map.insert({{m}, j});
    }
    for( auto _ : state)
    {
        DoNotOptimize(map.at({m}));
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapSmallAt)->RangeMultiplier(2)->Range(1, 2<<13)->Complexity();
void MapSmallOperator(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};
    Small m{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        m.randomize();
        map.insert({m, j});
    }
    auto t = rand() % size;
    for( auto _ : state)
    {
        m.randomize();
        DoNotOptimize(map[m] = t);
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapSmallOperator)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();
void MapSmallEmpty(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};
    Small m{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        m.randomize();
        map.insert({m, j});
    }
    for( auto _ : state )
    {
        DoNotOptimize(map.empty());
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapSmallEmpty)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void MapSmallSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};
    Small m{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        m.randomize();
        map.insert({m, j});
    }
    for( auto _ : state)
    {
        DoNotOptimize(map.size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapSmallSize)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void MapSmallMaxSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};
    Small m{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        m.randomize();
        map.insert({m, j});
    }
    for( auto _ : state )
    {
        DoNotOptimize(map.max_size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapSmallMaxSize)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void MapSmallClear(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Small m{};
    for( auto _ : state )
    {
        std::map<Small, int> map{};
        for(size_t i = 0; i<size; i++)
        {
            auto j = rand()%size;
            m.randomize();
            map.insert({m, j});
        }
        DoNotOptimize(map);
        map.clear();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapSmallClear)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void MapSmallInsert(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};
    Small m{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        m.randomize();
        map.insert({m, j});
    }
    for( auto _ : state )
    {
        m.randomize();
        auto t = rand() % size;
        DoNotOptimize(map.insert({m, t}));
        ClobberMemory();
        state.PauseTiming();
        map.erase(m);
        state.ResumeTiming();
        DoNotOptimize(map);
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapSmallInsert)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void MapSmallErase(State& state)
{
    auto N = state.range();
    auto size = (std::size_t)N;
    std::map<Small, int> map{};
    Small m{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        m.randomize();
        map.insert({m, j});
    }
    for( auto _ : state )
    {
        m.randomize();
        DoNotOptimize(map.erase(m));
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapSmallErase)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void MapSmallSwap(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map_1{};
    Small m{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        m.randomize();
        map_1.insert({m, j});
    }
    std::map<Small, int> map_2{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map_2.insert({m, j});
    }
    for( auto _ : state )
    {
        map_1.swap(map_2);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapSmallSwap)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void MapSmallCount(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};
    Small m{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        m.randomize();
        map.insert({m, j});
    }
    for( auto _ : state )
    {
        m.randomize();
        DoNotOptimize(map.count(m));
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapSmallCount)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void MapSmallFind(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};
    Small m{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        m.randomize();
        map.insert({m, j});
    }
    for( auto _ : state )
    {
        m.randomize();
        DoNotOptimize(map.find(m));
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapSmallFind)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void MapSmallEqualRange(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};
    Small m{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        m.randomize();
        map.insert({m, j});
    }
    for( auto _ : state )
    {
        m.randomize();
        DoNotOptimize(map.equal_range(m));
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapSmallEqualRange)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void MapSmallLowerBound(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};
    Small m{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        m.randomize();
        map.insert({m, j});
    }
    for( auto _ : state )
    {
        m.randomize();
        DoNotOptimize(map.lower_bound(m));
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapSmallLowerBound)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void MapSmallUpperBound(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};
    Small m{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        m.randomize();
        map.insert({m, j});
    }
    for( auto _ : state )
    {
        m.randomize();
        DoNotOptimize(map.upper_bound(m));
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapSmallUpperBound)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
