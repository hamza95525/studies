#include <iostream>
#include "Dummy.h"
#include "TextWrapper.h"
int main(int argc, char* argv[])
{
    auto dummy = Dummy{};
    std::cout << dummy.hello() << std::endl;
    std::cout << std::endl;
    std::string Argument = "hellohello";
    std::string Arg2 = "czesc czesc czesc oh hell nah";
    auto wrap = TextWrapper(3, Argument);
    std::cout << wrap.wrapping() << std::endl;
    auto wrap1 = TextWrapper(5, Arg2);
    std::cout << wrap1.wrapping()<<std::endl;
    return 0;
}
/**/
