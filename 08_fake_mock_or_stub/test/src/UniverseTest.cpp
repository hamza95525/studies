#include "Universe.h"
#include "TestIncludes.h"
#include "TimeMock.h"
#include "SpaceMock.h"
#include "ObserverMock.h"
TEST(Universe, Create)
{
    StrictMock<SpaceMock> space{};
    StrictMock<TimeMock> time{};
    StrictMock<ObserverMock> observer{};
    Universe universe(time, space, observer);
    EXPECT_CALL(time, create(true));
    EXPECT_CALL(space, create(11));
    EXPECT_CALL(observer, remember("How many dimensions there are?", std::to_string(11) ) ); //wstawiamy 11 na sztywno!
    EXPECT_CALL(space,  dimensions()).WillOnce(Return(11));
    universe.create();
}
TEST(Universe, Simulate)
{
    StrictMock<SpaceMock> space{};
    StrictMock<TimeMock> time{};
    StrictMock<ObserverMock> observer{};
    Universe universe{time, space, observer};
    EXPECT_CALL(time, now()).WillOnce(Return(9300000000)).WillOnce(Return(9900000000)).WillOnce(Return(13800000000)).WillOnce(Return(13800000001));
    EXPECT_CALL(observer, remember("Is there planet Earth?", "Yes!"));
    EXPECT_CALL(observer, remember("Does life exist?", "Yes!"));
    EXPECT_CALL(observer, remember("Have People evolved?", "Yes!"));
    EXPECT_CALL(time, flow()).WillRepeatedly(Return());
    universe.simulate(13800000001);
}
/*class Interface{
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
};*/
/*SpaceImpl space{};
TimeImpl time{};
ObserverImpl observer{};
// TODO: Test Universe class...
Universe universe{time, space, observer};
//universe.create();
universe.simulate(1);*/
//Implementation implementation{};
/*StrictMock<MyMock> mymock{};
Dummy dummy{mymock};
EXPECT_EQ(10, dummy.execute());*/
/*StrictMock<MyMock> mymock{};
Dummy dummy{mymock};
EXPECT_CALL(mymock, test()).WillOnce(Return(10)); //ta magiczna linijka powoduje ze test przechodzi
EXPECT_EQ(10, dummy.execute());*/
