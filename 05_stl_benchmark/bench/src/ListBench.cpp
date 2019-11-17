//
// Created by khamza on 14.11.2019.
//
#include "BenchIncludes.h"

//======================================LIST BENCHMARKS=======================================================

void ListFront(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);

    for( auto _ : state){
        list.front();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListFront)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListBack(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);

    for( auto _ : state )
    {
        list.back();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListBack)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListEmpty(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);

    for( auto _ : state)
    {
        list.empty();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListEmpty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);

    for( auto _ : state)
    {
        list.size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListMaxSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);

    for( auto _ : state )
    {
        list.max_size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListMaxSize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListClear(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);

    for( auto _ : state )
    {
        list.clear();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListClear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListInsert(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);
    auto iter = list.begin();

    for( auto _ : state )
    {
        auto value = rand() % size;
        list.insert(iter,{(char)value});
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListInsert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListErase(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);
   // list.insert(list.begin(),{3});

    for( auto _ : state )
    {
        auto value = rand() % size;
        list.insert(list.begin(),{(char)value}); //inserting element to have sth to erase, without that benchmark aborts due to, invalid pointer
        list.erase(list.begin());
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListErase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListPushBack(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);

    for( auto _ : state )
    {
        auto value = rand() % size;
        list.push_back({(char)value});
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListPushBack)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListPopBack(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);

    for( auto _ : state )
    {
        auto value = rand() % size;
        list.push_back({(char) value}); //pushing element to have sth to pop
        list.pop_back();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListPopBack)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListPushFront(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);

    for( auto _ : state )
    {
        auto value = rand() % size;
        list.push_front({(char)value});
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListPushFront)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListPopFront(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);

    for( auto _ : state )
    {
        auto value = rand() % size;
        list.push_front({(char) value}); //pushing front element to have sth to pop, otherwise "free(): invalid pointer" given
        list.pop_front();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListPopFront)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListResize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);

    for( auto _ : state )
    {
        auto value = rand() % size;
        list.resize(value);
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListResize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListSwap(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    //creating two different lists with different elements, to swap later one list with another
    std::list<Small> list_1(size);
    list_1.push_back({3});

    std::list<Small> list_2(size);
    list_2.push_back({1});
    for( auto _ : state )
    {
        list_2.swap(list_1);
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSwap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListMerge(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list_1(size);
    list_1.push_back({1});

    std::list<Small> list_2(size);
    list_2.push_back({2});

    for( auto _ : state )
    {
        list_2.merge(list_1);
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListMerge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListSplice(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list_1(size);
    list_1.push_back({1});

    std::list<Small> list_2(size);
    list_2.push_back({2});

    for( auto _ : state )
    {
        list_1.splice(list_1.begin(), list_2);
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSplice)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListRemove(State& state)
{
    auto N= state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);
    list.push_back({1});

    for( auto _ : state )
    {
        list.remove({1});
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListRemove)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListRemoveIf(State& state)
{
    auto N = state.range(0);
    std::list<Small> list{};
    list.push_back({6});

    for( auto _ : state )
    {
        list.remove_if([](Small d){ return d.data[0] > 5; });
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListRemoveIf)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListReverse(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);

    for( auto _ : state )
    {
        list.reverse();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListReverse)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListUnique(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);

    for( auto _ : state )
    {
        list.unique();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListUnique)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListSort(State& state)
{
    auto N = state.range(0);
    //std::list<Small> list{{1}, {2}, {1}, {3}, {11}, {4}}; //more elements takes more time to sort
    auto size = (std::size_t)N;
    std::list<Small> list(size);
    for( auto _ : state )
    {
        list.sort();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSort)->RangeMultiplier(2)->Range(1, 1024)->Complexity();