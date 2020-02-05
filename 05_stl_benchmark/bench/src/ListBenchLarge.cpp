//
// Created by khamza on 21.11.2019.
//
#include "BenchIncludes.h"
//======================================LIST BENCHMARKS LARGE=======================================================
void ListLargeFront(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Large> list(size);
    for( auto _ : state){
        DoNotOptimize(list.front());
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListLargeFront)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();
void ListLargeBack(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Large> list(size);
    for( auto _ : state )
    {
        DoNotOptimize(list.back());
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListLargeBack)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();
void ListLargeEmpty(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Large> list(size);
    for( auto _ : state)
    {
        DoNotOptimize(list.empty());
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListLargeEmpty)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();
void ListLargeSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Large> list(size);
    for( auto _ : state)
    {
        DoNotOptimize(list.size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListLargeSize)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();
void ListLargeMaxSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Large> list(size);
    for( auto _ : state )
    {
        DoNotOptimize(list.max_size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListLargeMaxSize)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();
void ListLargeClear(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    for( auto _ : state )
    {
        state.PauseTiming();
        std::list<Large> list(size);
        state.ResumeTiming();
        DoNotOptimize(list);
        list.clear();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListLargeClear)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity(); //zgodnie z wynikami widac ze liniowe ale splyca do stalej
void ListLargeInsert(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Large> list(size);
    Large m{};
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
BENCHMARK(ListLargeInsert)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();
void ListLargeErase(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    // list.insert(list.begin(),{3});
    std::list<Large> list(size);
    Large m{};
    for( auto _ : state )
    {
        //state.PauseTiming();
        m.randomize();
        auto iter = list.begin();
        list.insert(iter,m); //inserting element to have sth to erase, without that benchmark aborts due to, invalid pointer
        //state.ResumeTiming();
        DoNotOptimize(list.erase(iter));
        ClobberMemory();
        iter++;
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListLargeErase)->RangeMultiplier(2)->Range(1, 2<<3)->Complexity();
void ListLargePushBack(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Large> list(size);
    Large m{};
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
BENCHMARK(ListLargePushBack)->RangeMultiplier(2)->Range(1, 2<<3)->Complexity();
void ListLargePopBack(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Large> list(size);
    Large m{};
    for( auto _ : state )
    {
        //state.PauseTiming();
        m.randomize();
        list.push_back(m);
        //state.ResumeTiming();
        list.pop_back();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListLargePopBack)->RangeMultiplier(2)->Range(1, 2<<3)->Complexity();
void ListLargePushFront(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Large> list(size);
    Large m{};
    for( auto _ : state )
    {
        //state.PauseTiming();
        m.randomize();
        list.pop_front();
        //state.ResumeTiming();
        list.push_front(m);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListLargePushFront)->RangeMultiplier(2)->Range(1, 2<<3)->Complexity();
void ListLargePopFront(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Large> list(size);
    Large m{};
    for( auto _ : state )
    {
        //state.PauseTiming();
        auto value = rand() % size;
        list.push_front(m);
        //state.ResumeTiming();
        list.pop_front();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListLargePopFront)->RangeMultiplier(2)->Range(1, 2<<3)->Complexity();
void ListLargeResize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    for( auto _ : state )
    {
        //state.PauseTiming();
        auto value = rand() % size;
        std::list<Large> list(size);
        //state.ResumeTiming();
        DoNotOptimize(list);
        list.resize(value);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListLargeResize)->RangeMultiplier(2)->Range(1, 2<<3)->Complexity();
void ListLargeSwap(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    //creating two different lists with different elements, to swap later one list with another
    std::list<Large> list_1{};
    Large m{};
    for(auto i = 0; i<size; i++)
    {
        m.randomize();
        list_1.push_back( m);
    }
    std::list<Large> list_2{};
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
BENCHMARK(ListLargeSwap)->RangeMultiplier(2)->Range(1, 2<<5)->Complexity();
void ListLargeMerge(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Large m{};
    for( auto _ : state )
    {
        std::list<Large> list_1{};
        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            list_1.push_back( m);
        }
        std::list<Large> list_2{};
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
BENCHMARK(ListLargeMerge)->RangeMultiplier(2)->Range(1, 2<<2)->Complexity();
void ListLargeSplice(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Large m{};
    std::list<Large> list_1{};
    for(auto i = 0; i<size; i++)
    {
        m.randomize();
        list_1.push_back( m);
    }
    for( auto _ : state )
    {
        //state.PauseTiming();
        list_1.clear();
        std::list<Large> list_2{};
        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            list_2.push_back( m);
        }
        //state.ResumeTiming();
        DoNotOptimize(list_1); DoNotOptimize(list_2);
        list_1.splice(list_1.begin(), list_2);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListLargeSplice)->RangeMultiplier(2)->Range(1, 2<<2)->Complexity();
void ListLargeRemove(State& state)
{
    auto N= state.range(0);
    auto size = (std::size_t)N;
    Large m{};
    for( auto _ : state )
    {
        //state.PauseTiming();
        std::list<Large> list{};
        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            list.push_back( m);
        }
        //state.ResumeTiming();
        DoNotOptimize(list);
        list.remove(m);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListLargeRemove)->RangeMultiplier(2)->Range(1, 2<<2)->Complexity();
void ListLargeRemoveIf(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Large m{};
    for( auto _ : state )
    {
        //state.PauseTiming();
        std::list<Large> list{};
        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            list.push_back( m);
        }
        //state.ResumeTiming();
        DoNotOptimize(list);
        list.remove_if([](Large d){ auto value = rand() % 256; return d.data[0] > value;});
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListLargeRemoveIf)->RangeMultiplier(2)->Range(1, 2<<2)->Complexity();
void ListLargeReverse(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Large m{};
    for( auto _ : state )
    {
        //state.PauseTiming();
        std::list<Large> list{};
        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            list.push_back( m);
        }
        //state.ResumeTiming();
        DoNotOptimize(list);
        list.reverse();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListLargeReverse)->RangeMultiplier(2)->Range(1, 2<<2)->Complexity();
void ListLargeUnique(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Large m{};
    for( auto _ : state )
    {
        //state.PauseTiming();
        std::list<Large> list{};
        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            list.push_back( m);
        }
        //state.ResumeTiming();
        DoNotOptimize(list);
        list.unique();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListLargeUnique)->RangeMultiplier(2)->Range(1, 2<<2)->Complexity(); //liniowa, ale splycone do stalej
void ListLargeSort(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Large m{};
    for( auto _ : state )
    {
        //state.PauseTiming();
        std::list<Large> list{};
        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            list.push_back( m);
        }
        //state.ResumeTiming();
        DoNotOptimize(list);
        list.sort();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListLargeSort)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();
