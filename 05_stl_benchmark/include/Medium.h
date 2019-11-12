#pragma once

#include <random>

struct Medium {

    constexpr static unsigned SIZE = 256u;
    int data[SIZE];

    void clear() {
        std::fill_n(data, SIZE, 0);
    }

    void randomize() {
        static std::random_device rd{};
        static std::mt19937 gen{rd()};
        static std::uniform_int_distribution<int> dis{};

        for (int &i : data)
            i = dis(gen);
    }

    bool operator<(const Medium &rhs) const {

        // TODO: Implement me!
        /*if(this > &rhs)
            return false;*/
        for(unsigned int i = 0; i < SIZE; i++){
            if( data[i] < rhs.data[i] )
                return true;
        }

        return false;
    }

    bool operator==(const Medium &rhs) const {

        // TODO: Implement me!
        for(unsigned int i=0; i<SIZE; i++){
            if(data[i] != rhs.data[i])
                return false;
        }

        return true;
    }
};

namespace std {
    template<>
    struct hash<Medium> {
        std::size_t operator()(const Medium &d) const {
            // TODO: Implement me!
            int hash = 1;
            for(unsigned int i = 0; i< d.SIZE; i++){
                hash = hash * d.data[i] + d.SIZE;
            }
            return (std::hash<int>()(hash));
        }
    };
}