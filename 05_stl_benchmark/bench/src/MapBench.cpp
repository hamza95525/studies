//
// Created by khamza on 16.11.2019.
//
#include "BenchIncludes.h"

//======================================MAP BENCHMARKS=======================================================
void MapAt(State& state)
{
    std::map<Small, int> map{{{'a'}, 1}};
    //std::map<Small, int> map{};  //what() map::at when map is empty

    for( auto _ : state )
    {
        map.at({'a'});
    }
}
BENCHMARK(MapAt);

void MapOperator(State& state)
{
    std::map<Small, int> map{{{'a'}, 1}};

    for( auto _ : state)
    {
        map[{'a'}] = 2;
    }
}
BENCHMARK(MapOperator);

void MapEmpty(State& state)
{
    std::map<Small, int> map{};

    for( auto _ : state )
    {
        map.empty();
    }
}
BENCHMARK(MapEmpty);

void MapSize(State& state)
{
    //std::map<Small, int> map{};
    std::map<Small, int> map{{{'a'}, 1}, {{'b'}, 2 }, {{'c'}, 3}};

    for( auto _ : state)
    {
        map.size();
    }
}
BENCHMARK(MapSize);

void MapMaxSize(State& state)
{
    std::map<Small, int> map{{{'a'}, 1}, {{'b'}, 2 }, {{'c'}, 3}};

    for( auto _ : state )
    {
        map.max_size();
    }
}
BENCHMARK(MapMaxSize);

void MapClear(State& state)
{
    //std::map<Small, int> map{{{'a'}, 1}, {{'b'}, 2 }, {{'c'}, 3}};
    std::map<Small, int> map{};

    for( auto _ : state )
    {
        map.clear();
    }
}
BENCHMARK(MapClear);

void MapInsert(State& state)
{
    //std::map<Small, int> map{};
    std::map<Small, int> map{{{'a'}, 1}, {{'b'}, 2 }, {{'c'}, 3}};
    //as the size of map grows, time of inserting gets bigger

    for( auto _ : state )
    {
        map.insert({{'d'}, 4});
    }
}
BENCHMARK(MapInsert);

void MapErase(State& state)
{
    std::map<Small, int> map{{{'a'}, 1}, {{'b'}, 2 }, {{'c'}, 3}};
    //std::map<Small, int> map{};

    for( auto _ : state )
    {
        map.erase({'a'});
    }
}
BENCHMARK(MapErase);

void MapSwap(State& state)
{
    std::map<Small, int> map_1{{{'a'}, 1}, {{'b'}, 2 }, {{'c'}, 3}};
    std::map<Small, int> map_2{{{'f'}, 6}, {{'e'}, 5 }, {{'d'}, 4}};

    for( auto _ : state )
    {
        map_1.swap(map_2);
    }
}
BENCHMARK(MapSwap);

void MapCount(State& state)
{
    //std::map<Small, int> map{{{'a'}, 1}, {{'b'}, 2 }, {{'c'}, 3}}; //bigger size == more time
    std::map<Small, int> map{};

    for( auto _ : state )
    {
        map.count({'a'});
    }
}
BENCHMARK(MapCount);

void MapFind(State& state)
{
    std::map<Small, int> map{{{'a'}, 1}, {{'b'}, 2 }, {{'c'}, 3}};
    //std::map<Small, int> map{};

    for( auto _ : state )
    {
        map.find({'c'});
    }
}
BENCHMARK(MapFind);

void MapEqualRange(State& state)
{
    std::map<Small, int> map{{{'a'}, 1}, {{'b'}, 2 }, {{'c'}, 3}};
    //std::map<Small, int> map{};

    for( auto _ : state )
    {
        map.equal_range({'b'});
    }
}
BENCHMARK(MapEqualRange);

void MapLowerBound(State& state)
{
    std::map<Small, int> map{{{'a'}, 1}, {{'b'}, 2 }, {{'c'}, 3}};

    for( auto _ : state )
    {
        map.lower_bound({'c'});
    }
}
BENCHMARK(MapLowerBound);

void MapUpperBound(State& state)
{
    std::map<Small, int> map{{{'a'}, 1}, {{'b'}, 2 }, {{'c'}, 3}};

    for( auto _ : state )
    {
        map.upper_bound({'a'});
    }
}
BENCHMARK(MapUpperBound);