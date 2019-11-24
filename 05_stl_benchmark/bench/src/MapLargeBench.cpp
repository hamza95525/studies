//
// Created by khamza on 21.11.2019.
//
//
// Created by khamza on 16.11.2019.
//
#include "BenchIncludes.h"

//======================================MAP BENCHMARKS LARGE=======================================================
void MapLargeAt(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Large, int> map{};
    Large m{};
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
BENCHMARK(MapLargeAt)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();

void MapLargeOperator(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Large, int> map{};
    Large m{};

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
BENCHMARK(MapLargeOperator)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity(); //int przyjmuje tylko 256

void MapLargeEmpty(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Large, int> map{};
    Large m{};

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
BENCHMARK(MapLargeEmpty)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();

void MapLargeSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Large, int> map{};
    Large m{};
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
BENCHMARK(MapLargeSize)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();

void MapLargeMaxSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Large, int> map{};
    Large m{};

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
BENCHMARK(MapLargeMaxSize)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();

void MapLargeClear(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Large m{};

    for( auto _ : state )
    {
        std::map<Large, int> map{};

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
BENCHMARK(MapLargeClear)->RangeMultiplier(2)->Range(1, 2<<3)->Complexity();

void MapLargeInsert(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::map<Large, int> map{};
    Large m{};

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
BENCHMARK(MapLargeInsert)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();

void MapLargeErase(State& state)
{
    auto N = state.range();
    auto size = (std::size_t)N;

    std::map<Large, int> map{};
    Large m{};

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
BENCHMARK(MapLargeErase)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();

void MapLargeSwap(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::map<Large, int> map_1{};
    Large m{};
    for(size_t i = 0; i<size; i++)
    {
        auto j = rand()%size;
        m.randomize();
        map_1.insert({m, j});
    }

    std::map<Large, int> map_2{};
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
BENCHMARK(MapLargeSwap)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();

void MapLargeCount(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Large, int> map{};
    Large m{};

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
BENCHMARK(MapLargeCount)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();

void MapLargeFind(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Large, int> map{};
    Large m{};
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
BENCHMARK(MapLargeFind)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();

void MapLargeEqualRange(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Large, int> map{};
    Large m{};

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
BENCHMARK(MapLargeEqualRange)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();

void MapLargeLowerBound(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Large, int> map{};
    Large m{};
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
BENCHMARK(MapLargeLowerBound)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();

void MapLargeUpperBound(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::map<Large, int> map{};
    Large m{};
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
BENCHMARK(MapLargeUpperBound)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();
