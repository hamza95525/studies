#include <iostream>
#include "Dummy.h"
#include "TextWrapper.h"

int main(int argc, char* argv[])
{
    auto dummy = Dummy{};
    std::cout << dummy.hello() << std::endl;

    auto wrap = TextWrapper(1, "abcdefgh");



    return 0;
}

/**/