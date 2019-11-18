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

    for(auto i = 0; i<size; i++)
    {
        auto value = rand()%size;
        list.push_back( {(char)value});
    }

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

    for(auto i = 0; i<size; i++)
    {
        auto value = rand()%size;
        list.push_back( {(char)value});
    }

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

    for(auto i = 0; i<size; i++)
    {
        auto value = rand()%size;
        list.push_back( {(char)value});
    }

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

    for(auto i = 0; i<size; i++)
    {
        auto value = rand()%size;
        list.push_back( {(char)value});
    }

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

    for(auto i = 0; i<size; i++)
    {
        auto value = rand()%size;
        list.push_back( {(char)value});
    }

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

    for( auto _ : state )
    {
        state.PauseTiming();
            std::list<Small> list(size);

            for(auto i = 0; i<size; i++)
            {
                auto value = rand()%size;
                list.push_back( {(char)value});
            }
        state.ResumeTiming();

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

    for(auto i = 0; i<size; i++)
    {
        auto value = rand()%size;
        list.push_back( {(char)value});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto iter = list.begin();
            auto value = rand() % size;
        state.ResumeTiming();

        list.insert(iter++, {(char)value});

        state.PauseTiming();
            list.remove({(char)value});
        state.ResumeTiming();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListInsert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListErase(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
   // list.insert(list.begin(),{3});
    std::list<Small> list(size);

    for(auto i = 0; i<size; i++)
    {
        auto value = rand()%size;
        list.push_back( {(char)value});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto value = rand() % size;
            auto iter = list.begin();
            list.insert(iter,{(char)value}); //inserting element to have sth to erase, without that benchmark aborts due to, invalid pointer
            iter++;
        state.ResumeTiming();

        list.erase(iter);
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListErase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListPushBack(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);
    for(auto i = 0; i<size; i++)
    {
        auto value = rand()%size;
        list.push_front( {(char)value});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto value = rand() % size;
            list.pop_back();
        state.ResumeTiming();

        list.push_back({{(char)value}});
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListPushBack)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListPopBack(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);

    for(auto i = 0; i<size; i++)
    {
        auto value = rand()%size;
        list.push_front( {(char)value});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto value = rand() % size;
            list.push_back({(char)value});
        state.ResumeTiming();

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

    for(auto i = 0; i<size; i++)
    {
        auto value = rand()%size;
        list.push_back( {(char)value});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto value = rand() % size;
            list.pop_front();
        state.ResumeTiming();

        list.push_front({{(char)value}});
    }

    state.SetComplexityN(N);
}
BENCHMARK(ListPushFront)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListPopFront(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Small> list(size);

    for(auto i = 0; i<size; i++)
    {
        auto value = rand()%size;
        list.push_back( {(char)value});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto value = rand() % size;
            list.pop_front();
        state.ResumeTiming();

        list.push_front({(char)value});
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListPopFront)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListResize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);

    for(auto i = 0; i<size; i++)
    {
        auto value = rand()%size;
        list.push_back( {(char)value});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto value = rand() % size;
        state.ResumeTiming();
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
    std::list<Small> list_2(size);

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

    for( auto _ : state )
    {
        state.PauseTiming();
            std::list<Small> list_1(size);
            for(auto i = 0; i<size; i++)
            {
                auto value = rand()%size;
                list_1.push_back( {(char)value});
            }
            std::list<Small> list_2(size);
            for(auto i = 0; i<size; i++)
            {
                auto value = rand()%size;
                list_2.push_back( {(char)value});
            }
        state.ResumeTiming();

        list_2.merge(list_1);
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListMerge)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListSplice(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;

    for( auto _ : state )
    {
        state.PauseTiming();
            std::list<Small> list_1(size);
            for(auto i = 0; i<size; i++)
            {
                auto value = rand()%size;
                list_1.push_back( {(char)value});
            }
            std::list<Small> list_2(size);
            for(auto i = 0; i<size; i++)
            {
                auto value = rand()%size;
                list_2.push_back( {(char)value});
            }
        state.ResumeTiming();

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

    for(auto i = 0; i<size; i++)
    {
        auto value = rand()%size;
        list.push_back( {(char)value});
    }

    for( auto _ : state )
    {
        state.PauseTiming();
            auto value = rand() % size;
        state.ResumeTiming();

        list.remove({(char)value});
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListRemove)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListRemoveIf(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);

    for(auto i = 0; i<size; i++)
    {
        auto value = rand()%size;
        list.push_back( {(char)value});
    }

    for( auto _ : state )
    {
        list.remove_if([](Small d){ auto value = rand() % 256; return d.data[0] > value;});
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListRemoveIf)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

void ListReverse(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;

    for( auto _ : state )
    {
        state.PauseTiming();
            std::list<Small> list(size);

            for(auto i = 0; i<size; i++)
            {
                auto value = rand()%size;
                list.push_back( {(char)value});
            }

        state.ResumeTiming();

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

    for(auto i = 0; i<size; i++)
    {
        auto value = rand()%size;
        list.push_back( {(char)value});
    }

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

    for( auto _ : state )
    {
        state.PauseTiming();
            std::list<Small> list(size);

            for(auto i = 0; i<size; i++)
            {
                auto value = rand()%size;
                list.push_back( {(char)value});
            }
        state.ResumeTiming();
        list.sort();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSort)->RangeMultiplier(2)->Range(1, 1024)->Complexity();