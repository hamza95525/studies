#include "Universe.h"
#include "TestIncludes.h"

class Interface{
public:
    virtual int test() = 0;
};

class Implementation : public Interface{
public:
    int test() override {
        return 10;
    }
};

class MyMock : public Interface{
public:
    MOCK_METHOD0(test, int());
};

class Dummy{
    Interface &interface;
public:
    explicit Dummy(Interface &interface) : interface(interface) {
    }
    int execute(){return interface.test();}
};

TEST(Universe, Create)
{
    /*Space space{};
    TimeImpl time{};
    Observer observer{};
    // TODO: Test Universe class...
    Universe universe{time, space, observer};

    //universe.create();

    universe.simulate(1);*/

    //Implementation implementation{};
    /*StrictMock<MyMock> mymock{};
    Dummy dummy{mymock};
    EXPECT_EQ(10, dummy.execute());*/
    StrictMock<MyMock> mymock{};
    Dummy dummy{mymock};

    EXPECT_CALL(mymock, test()).WillOnce(Return(10)); //ta magiczna linijka powoduje ze test przechodzi
    EXPECT_EQ(10, dummy.execute());

}
