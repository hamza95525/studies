//
// Created by khamza on 21.11.2019.
//
//
// Created by khamza on 16.11.2019.
//
#include "BenchIncludes.h"

//======================================MAP BENCHMARKS MEDIUM=======================================================
void MapMediumAt(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Medium, int> map{};
    Medium m{};
    m.randomize();

    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        m.randomize();
        map.insert({m, j});
    }


    for( auto _ : state)
    {
        m.randomize();
        DoNotOptimize(map.at(m));
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapMediumAt)->RangeMultiplier(2)->Range(1, 2<<13)->Complexity();

void MapMediumOperator(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Medium, int> map{};
    Medium m{};

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
BENCHMARK(MapMediumOperator)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void MapMediumEmpty(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Medium, int> map{};
    Medium m{};

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
BENCHMARK(MapMediumEmpty)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void MapMediumSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Medium, int> map{};
    Medium m{};
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
BENCHMARK(MapMediumSize)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void MapMediumMaxSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Medium, int> map{};
    Medium m{};

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
BENCHMARK(MapMediumMaxSize)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void MapMediumClear(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Medium m{};

    for( auto _ : state )
    {
        std::map<Medium, int> map{};

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
BENCHMARK(MapMediumClear)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();

void MapMediumInsert(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::map<Medium, int> map{};
    Medium m{};

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

        map.insert({m, t});
        ClobberMemory();

        state.PauseTiming();
        map.erase(m);
        state.ResumeTiming();
        DoNotOptimize(map);
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapMediumInsert)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void MapMediumErase(State& state)
{
    auto N = state.range();
    auto size = (std::size_t)N;

    std::map<Medium, int> map{};
    Medium m{};

    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        m.randomize();
        map.insert({m, j});
    }

    for( auto _ : state )
    {
        m.randomize();
        map.erase(m);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(MapMediumErase)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void MapMediumSwap(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::map<Medium, int> map_1{};
    Medium m{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        m.randomize();
        map_1.insert({m, j});
    }

    std::map<Medium, int> map_2{};
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
BENCHMARK(MapMediumSwap)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void MapMediumCount(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Medium, int> map{};
    Medium m{};

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
BENCHMARK(MapMediumCount)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void MapMediumFind(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Medium, int> map{};
    Medium m{};
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
BENCHMARK(MapMediumFind)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void MapMediumEqualRange(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Medium, int> map{};
    Medium m{};

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
BENCHMARK(MapMediumEqualRange)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void MapMediumLowerBound(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Medium, int> map{};
    Medium m{};
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
BENCHMARK(MapMediumLowerBound)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void MapMediumUpperBound(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Medium, int> map{};
    Medium m{};
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
BENCHMARK(MapMediumUpperBound)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();
