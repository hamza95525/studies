//
// Created by khamza on 16.11.2019.
//
#include "BenchIncludes.h"

//======================================MAP BENCHMARKS=======================================================
void MapAt(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};

    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map.insert({{(char)i}, j});
    }

    for( auto _ : state)
    {
        state.PauseTiming();
            auto value = rand() % size;
        state.ResumeTiming();

        map.at({(char)value});
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapAt)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void MapOperator(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Small, int> map{};

    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map.insert({{(char)i}, j});
    }

    for( auto _ : state)
    {
        state.PauseTiming();
            auto value = rand() % size;
            auto t = rand() % size;
        state.ResumeTiming();

        map[{(char)value}] = t;
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
        map.insert({{(char)i}, j});
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
        map.insert({{(char)i}, j});
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
        map.insert({{(char)i}, j});
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

    for( auto _ : state )
    {
        state.PauseTiming();
            std::map<Small, int> map{};
            for(size_t i = 0; i<size; i++)
            {
                auto j = rand()%size;
                map.insert({{(char)i}, j});
            }
        state.ResumeTiming();

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
        map.insert({{(char)i}, j});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto value = rand() % size;
            auto t = rand() % size;
        state.ResumeTiming();

        map.insert({{(char)value}, t});

    }
    state.SetComplexityN(N);
}
BENCHMARK(MapInsert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void MapErase(State& state)
{
    auto N = state.range();
    auto size = (std::size_t)N;

    std::map<Small, int> map{};

    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map.insert({{(char)i}, j});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto value = rand() % size;
        state.ResumeTiming();

        map.erase({(char)value});
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
        map_1.insert({{(char)i}, j});
    }

    std::map<Small, int> map_2{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        map_2.insert({{(char)i}, j});
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
        map.insert({{(char)i}, j});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto value = rand() % size;
        state.ResumeTiming();

        map.count({(char)value});
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
        map.insert({{(char)i}, j});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto value = rand() % size;
        state.ResumeTiming();

        map.find({(char)value});
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
        map.insert({{(char)i}, j});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto value = rand() % size;
        state.ResumeTiming();

        map.equal_range({(char)value});
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
        map.insert({{(char)i}, j});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto value = rand() % size;
        state.ResumeTiming();

        map.lower_bound({(char)value});
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
        map.insert({{(char)i}, j});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto value = rand() % size;
        state.ResumeTiming();

        map.upper_bound({(char)value});
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapUpperBound)->RangeMultiplier(2)->Range(1, 1024)->Complexity();