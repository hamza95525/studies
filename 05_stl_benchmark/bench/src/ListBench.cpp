//
// Created by khamza on 14.11.2019.
//
#include "BenchIncludes.h"

//======================================LIST BENCHMARKS=======================================================

void ListFront(State& state)
{
    std::list<Small> list{};

    for( auto _ : state){
        list.front();
    }
}
BENCHMARK(ListFront);

void ListBack(State& state)
{
    std::list<Small> list{};

    for( auto _ : state )
    {
        list.back();
    }
}
BENCHMARK(ListBack);

void ListEmpty(State& state)
{
    std::list<Small> list{};

    for( auto _ : state)
    {
        list.empty();
    }
}
BENCHMARK(ListEmpty);

void ListSize(State& state)
{
    std::list<Small> list{};

    for( auto _ : state)
    {
        list.size();
    }
}
BENCHMARK(ListSize);

void ListMaxSize(State& state)
{
    std::list<Small> list{};

    for( auto _ : state )
    {
        list.max_size();
    }
}
BENCHMARK(ListMaxSize);

void ListClear(State& state)
{
    std::list<Small> list{};

    for( auto _ : state )
    {
        list.clear();
    }
}
BENCHMARK(ListClear);

void ListInsert(State& state)
{
    std::list<Small> list{};
    auto iter = list.begin();

    for( auto _ : state )
    {
        list.insert(iter,{3});
    }
}
BENCHMARK(ListInsert);

void ListErase(State& state)
{
    std::list<Small> list{};
   // list.insert(list.begin(),{3});

    for( auto _ : state )
    {
        list.insert(list.begin(),{3}); //inserting element to have sth to erase, without that benchmark aborts due to, invalid pointer
        list.erase(list.begin());
    }
}
BENCHMARK(ListErase);

void ListPushBack(State& state)
{
    std::list<Small> list{};

    for( auto _ : state )
    {
        list.push_back({1});
    }
}
BENCHMARK(ListPushBack);

void ListPopBack(State& state)
{
    std::list<Small> list{};

    for( auto _ : state )
    {
        list.push_back({1}); //pushing element to have sth to pop
        list.pop_back();
    }
}
BENCHMARK(ListPopBack);

void ListPushFront(State& state)
{
    std::list<Small> list{};

    for( auto _ : state )
    {
        list.push_front({2});
    }
}
BENCHMARK(ListPushFront);

void ListPopFront(State& state)
{
    std::list<Small> list{};

    for( auto _ : state )
    {
        list.push_front({1}); //pushing front element to have sth to pop, otherwise "free(): invalid pointer" given
        list.pop_front();
    }
}
BENCHMARK(ListPopFront);

void ListResize(State& state)
{
    std::list<Small> list{};

    for( auto _ : state )
    {
        list.resize(10);
    }
}
BENCHMARK(ListResize);

void ListSwap(State& state)
{
    //creating two different lists with different elements, to swap later one list with another
    std::list<Small> list_1{};
    list_1.push_back({3});

    std::list<Small> list_2{};
    list_2.push_back({1});
    for( auto _ : state )
    {
        list_2.swap(list_1);
    }
}
BENCHMARK(ListSwap);

void ListMerge(State& state)
{
    std::list<Small> list_1{};
    list_1.push_back({1});

    std::list<Small> list_2{};
    list_2.push_back({2});

    for( auto _ : state )
    {
        list_2.merge(list_1);
    }
}
BENCHMARK(ListMerge);

void ListSplice(State& state)
{
    std::list<Small> list_1{};
    list_1.push_back({1});

    std::list<Small> list_2{};
    list_2.push_back({2});

    for( auto _ : state )
    {
        list_1.splice(list_1.begin(), list_2);
    }
}
BENCHMARK(ListSplice);

void ListRemove(State& state)
{
    std::list<Small> list{};
    list.push_back({1});

    for( auto _ : state )
    {
        list.remove({1});
    }
}
BENCHMARK(ListRemove);

void ListRemoveIf(State& state)
{
    std::list<Small> list{};
    list.push_back({6});

    for( auto _ : state )
    {
        list.remove_if([](Small d){ return d.data[0] > 5; });
    }
}
BENCHMARK(ListRemoveIf);

void ListReverse(State& state)
{
    std::list<Small> list{{1},{2}, {3}};// without element time is 4 ns, with 3 elements in it its 7.5ns, so it seems like it works correctly

    for( auto _ : state )
    {
        list.reverse();
    }
}
BENCHMARK(ListReverse);

void ListUnique(State& state)
{
    std::list<Small> list{{2},{2},{2}};

    for( auto _ : state )
    {
        list.unique();
    }
}
BENCHMARK(ListUnique);

void ListSort(State& state)
{
    std::list<Small> list{{1}, {2}, {1}, {3}, {11}, {4}}; //more elements takes more time to sort
    //std::list<Small> list{{1}, {2}, {1}};
    for( auto _ : state )
    {
        list.sort();
    }
}
BENCHMARK(ListSort);