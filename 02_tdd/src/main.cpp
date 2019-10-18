#include <iostream>
#include "Dummy.h"
#include "TextWrapper.h"

int main(int argc, char* argv[])
{
    auto dummy = Dummy{};
    std::cout << dummy.hello() << std::endl;

    std::cout << std::endl; std::cout << std::endl;

    auto wrap = TextWrapper(1, "abcdefgh");
    std::cout << wrap.wrapping() << std::endl;


    return 0;
}

/**/