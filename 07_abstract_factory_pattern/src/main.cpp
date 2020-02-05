#include <iostream>
#include "GnomeWidgetFactory.h"
#include "KdeWidgetFactory.h"
#include "Dummy.h"
#include "Demo.h"
int main() {
    auto dummy = Dummy{};
    std::cout << "dummy.integrate(2, 4) = " << dummy.integrate(2, 4) << std::endl;
    std::shared_ptr<KdeWidgetFactory> implementation = std::make_shared<KdeWidgetFactory>(3);
    std::shared_ptr<GnomeWidgetFactory> implementation1 = std::make_shared<GnomeWidgetFactory>(4);
    Demo d(implementation);
    d.run("Button");
    Demo q(implementation1);
    q.run("Check");
    return 0;
}
