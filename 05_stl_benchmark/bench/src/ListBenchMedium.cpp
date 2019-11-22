//
// Created by khamza on 21.11.2019.
//
#include "BenchIncludes.h"

//======================================LIST BENCHMARKS MEDIUM=======================================================

void ListMediumFront(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Medium> list(size);

    for( auto _ : state){
        DoNotOptimize(list.front());
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListMediumFront)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void ListMediumBack(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Medium> list(size);

    for( auto _ : state )
    {
        DoNotOptimize(list.back());
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListMediumBack)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void ListMediumEmpty(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Medium> list(size);

    for( auto _ : state)
    {
        DoNotOptimize(list.empty());
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListMediumEmpty)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void ListMediumSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Medium> list(size);

    for( auto _ : state)
    {
        DoNotOptimize(list.size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListMediumSize)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void ListMediumMaxSize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Medium> list(size);
    for( auto _ : state )
    {
        DoNotOptimize(list.max_size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListMediumMaxSize)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void ListMediumClear(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;

    for( auto _ : state )
    {
        state.PauseTiming();
        std::list<Medium> list(size);
        state.ResumeTiming();
        DoNotOptimize(list);

        list.clear();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListMediumClear)->RangeMultiplier(2)->Range(1, 2<<4)->Complexity(); //zgodnie z wynikami widac ze liniowe ale splyca do stalej

void ListMediumInsert(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Medium> list(size);
    Medium m{};

    for( auto _ : state )
    {
        auto iter = list.begin();
        m.randomize();

        list.insert(iter++, m);
        ClobberMemory();

        state.PauseTiming();
        list.remove(m);
        state.ResumeTiming();
        DoNotOptimize(list);
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListMediumInsert)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void ListMediumErase(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    // list.insert(list.begin(),{3});
    std::list<Medium> list(size);
    Medium m{};

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
BENCHMARK(ListMediumErase)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void ListMediumPushBack(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Medium> list(size);
    Medium m{};

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
BENCHMARK(ListMediumPushBack)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void ListMediumPopBack(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Medium> list(size);
    Medium m{};

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
BENCHMARK(ListMediumPopBack)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void ListMediumPushFront(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    std::list<Medium> list(size);
    Medium m{};

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
BENCHMARK(ListMediumPushFront)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void ListMediumPopFront(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;

    std::list<Medium> list(size);
    Medium m{};

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
BENCHMARK(ListMediumPopFront)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void ListMediumResize(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;

    for( auto _ : state )
    {
        state.PauseTiming();
        auto value = rand() % size;
        std::list<Medium> list(size);

        state.ResumeTiming();
        DoNotOptimize(list);

        list.resize(value);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListMediumResize)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void ListMediumSwap(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    //creating two different lists with different elements, to swap later one list with another

    std::list<Medium> list_1{};
    Medium m{};
    for(auto i = 0; i<size; i++)
    {
        m.randomize();
        list_1.push_back( m);
    }
    std::list<Medium> list_2{};
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
BENCHMARK(ListMediumSwap)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void ListMediumMerge(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Medium m{};

    for( auto _ : state )
    {
        std::list<Medium> list_1{};
        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            list_1.push_back( m);
        }
        std::list<Medium> list_2{};
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
BENCHMARK(ListMediumMerge)->RangeMultiplier(2)->Range(1, 2<<4)->Complexity();

void ListMediumSplice(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Medium m{};

    std::list<Medium> list_1{};
    for(auto i = 0; i<size; i++)
    {
        m.randomize();
        list_1.push_back( m);
    }

    for( auto _ : state )
    {
        state.PauseTiming();
        list_1.clear();
        std::list<Medium> list_2{};
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
BENCHMARK(ListMediumSplice)->RangeMultiplier(2)->Range(1, 2<<7)->Complexity();

void ListMediumRemove(State& state)
{
    auto N= state.range(0);
    auto size = (std::size_t)N;
    Medium m{};

    for( auto _ : state )
    {
        state.PauseTiming();
        auto value = rand() % size;
        std::list<Medium> list{};

        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            list.push_back( m);
        }
        state.ResumeTiming();
        DoNotOptimize(list);
        list.remove({(int)value});
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListMediumRemove)->RangeMultiplier(2)->Range(1, 2<<6)->Complexity();

void ListMediumRemoveIf(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Medium m{};

    for( auto _ : state )
    {
        state.PauseTiming();
        std::list<Medium> list{};

        for(auto i = 0; i<size; i++)
        {
            m.randomize();
            list.push_back( m);
        }
        state.ResumeTiming();
        DoNotOptimize(list);
        list.remove_if([](Medium d){ auto value = rand() % 256; return d.data[0] > value;});
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(ListMediumRemoveIf)->RangeMultiplier(2)->Range(1, 2<<6)->Complexity();

void ListMediumReverse(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Medium m{};

    for( auto _ : state )
    {
        state.PauseTiming();
        std::list<Medium> list{};

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
BENCHMARK(ListMediumReverse)->RangeMultiplier(2)->Range(1, 2<<6)->Complexity();

void ListMediumUnique(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Medium m{};


    for( auto _ : state )
    {
        state.PauseTiming();
        std::list<Medium> list{};

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
BENCHMARK(ListMediumUnique)->RangeMultiplier(2)->Range(1, 2<<4)->Complexity(); //liniowa, ale splycone do stalej

void ListMediumSort(State& state)
{
    auto N = state.range(0);
    auto size = (std::size_t)N;
    Medium m{};

    for( auto _ : state )
    {
        state.PauseTiming();
        std::list<Medium> list{};
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
BENCHMARK(ListMediumSort)->RangeMultiplier(2)->Range(1, 1024)->Complexity();
