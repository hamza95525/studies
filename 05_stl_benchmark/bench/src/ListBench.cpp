//
// Created by khamza on 21.11.2019.
//
#include "BenchIncludes.h"
//======================================LIST BENCHMARKS SMALL=======================================================
void ListSmallFront(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);
    for( auto _ : state){
        DoNotOptimize(list.front());
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallFront)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallBack(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);
    for( auto _ : state )
    {
        DoNotOptimize(list.back());
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallBack)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallEmpty(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);
    for( auto _ : state)
    {
        DoNotOptimize(list.empty());
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallEmpty)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);
    for( auto _ : state)
    {
        DoNotOptimize(list.size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallSize)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallMaxSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);
    for( auto _ : state )
    {
        DoNotOptimize(list.max_size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallMaxSize)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallClear(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    for( auto _ : state )
    {
        state.PauseTiming();
        std::list<Small> list(size);
        state.ResumeTiming();
        DoNotOptimize(list);
        list.clear();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallClear)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallInsert(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);
    Small m{};
    for( auto _ : state )
    {
        auto iter = list.begin();
        m.randomize();
        DoNotOptimize(list.insert(iter++, m));
        ClobberMemory();
        state.PauseTiming();
        list.remove(m);
        state.ResumeTiming();
        DoNotOptimize(list);
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallInsert)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallErase(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    // list.insert(list.begin(),{3});
    std::list<Small> list(size);
    Small m{};
    for( auto _ : state )
    {
        state.PauseTiming();
        m.randomize();
        auto iter = list.begin();
        list.insert(iter,m); //inserting element to have sth to erase, without that benchmark aborts due to, invalid pointer
        state.ResumeTiming();
        DoNotOptimize(list.erase(iter));
        iter++;
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallErase)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallPushBack(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);
    Small m{};
    for( auto _ : state )
    {
        state.PauseTiming();
        m.randomize();
        list.pop_back();
        state.ResumeTiming();
        list.push_back(m);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallPushBack)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallPopBack(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);
    Small m{};
    for( auto _ : state )
    {
        state.PauseTiming();
        m.randomize();
        list.push_back(m);
        state.ResumeTiming();
        list.pop_back();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallPopBack)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallPushFront(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);
    Small m{};
    for( auto _ : state )
    {
        state.PauseTiming();
        m.randomize();
        list.pop_front();
        state.ResumeTiming();
        list.push_front(m);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallPushFront)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallPopFront(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Small> list(size);
    Small m{};
    for( auto _ : state )
    {
        state.PauseTiming();
        auto value = rand() % size;
        list.push_front(m);
        state.ResumeTiming();
        list.pop_front();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallPopFront)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallResize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    for( auto _ : state )
    {
        state.PauseTiming();
        auto value = rand() % size;
        std::list<Small> list(size);
        state.ResumeTiming();
        DoNotOptimize(list);
        list.resize(value);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallResize)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallSwap(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    //creating two different lists with different elements, to swap later one list with another
    std::list<Small> list_1{};
    Small m{};
    for(auto i = 0; i<size; i++)
    {
        m.randomize();
        list_1.push_back( m);
    }
    std::list<Small> list_2{};
    for(auto i = 0; i<size; i++)
    {
        m.randomize();
        list_2.push_back( m);
    }
    for( auto _ : state )
    {
        list_2.swap(list_1);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallSwap)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallMerge(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Small m{};
    for( auto _ : state )
    {
        std::list<Small> list_1{};
        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            list_1.push_back( m);
        }
        std::list<Small> list_2{};
        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            list_2.push_back( m);
        }
        DoNotOptimize(list_1); DoNotOptimize(list_2);
        list_2.merge(list_1);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallMerge)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallSplice(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Small m{};
    std::list<Small> list_1{};
    for(auto i = 0; i<size; i++)
    {
        m.randomize();
        list_1.push_back( m);
    }
    for( auto _ : state )
    {
        state.PauseTiming();
        list_1.clear();
        std::list<Small> list_2{};
        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            list_2.push_back( m);
        }
        state.ResumeTiming();
        DoNotOptimize(list_1); DoNotOptimize(list_2);
        list_1.splice(list_1.begin(), list_2);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallSplice)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallRemove(State& state)
{
    auto N= state.range(0);
    auto size = (std::size_t)N;
    Small m{};
    for( auto _ : state )
    {
        state.PauseTiming();
        std::list<Small> list{};
        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            list.push_back( m);
        }
        state.ResumeTiming();
        DoNotOptimize(list);
        list.remove(m);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallRemove)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallRemoveIf(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Small m{};
    for( auto _ : state )
    {
        state.PauseTiming();
        std::list<Small> list{};
        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            list.push_back( m);
        }
        state.ResumeTiming();
        DoNotOptimize(list);
        list.remove_if([](Small d){ auto value = rand() % 256; return d.data[0] > value;});
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallRemoveIf)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallReverse(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Small m{};
    for( auto _ : state )
    {
        state.PauseTiming();
        std::list<Small> list{};
        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            list.push_back( m);
        }
        state.ResumeTiming();
        DoNotOptimize(list);
        list.reverse();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallReverse)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity();
void ListSmallUnique(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Small m{};
    for( auto _ : state )
    {
        state.PauseTiming();
        std::list<Small> list{};
        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            list.push_back( m);
        }
        state.ResumeTiming();
        DoNotOptimize(list);
        list.unique();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallUnique)->RangeMultiplier(2)->Range(1, 2<<9)->Complexity(); //liniowa, ale splycone do stalej
void ListSmallSort(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Small m{};
    for( auto _ : state )
    {
        state.PauseTiming();
        std::list<Small> list{};
        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            list.push_back( m);
        }
        state.ResumeTiming();
        DoNotOptimize(list);
        list.sort();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListSmallSort)->RangeMultiplier(2)->Range(1, 2<<13)->Complexity();
