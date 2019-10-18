#include <iostream>
#include "Dummy.h"
#include "TextWrapper.h"

int main(int argc, char* argv[])
{
    auto dummy = Dummy{};
    std::cout << dummy.hello() << std::endl;

    std::cout << std::endl;

    std::string Argument = "RAZDWATRZ";
    auto wrap = TextWrapper(2, Argument);
    std::cout << wrap.wrapping() << std::endl;


    return 0;
}

/**/