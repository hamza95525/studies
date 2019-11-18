#include "TestIncludes.h"

/*
 *
 * struct Foo{};
 * struct FooComparator // a <b
 * {
 * bool operator()(const Foo& lhs, const Foo& rhs) constr {return false;}
 *
 * }
 * std::set<Foo, FooComparator> set{};
 *
 * struct FooHash //has
 * {
 * std::size_t operator() (const Foo& foo) const noexcept {return 0;}
 * };
 *
 * struct FooEqual // a==b
 * {
 * bool operator()(const Foo& lhs, const Foo& rhs) const {return false;};
 * };
 * std::unordered_set<Foo,FooHash,FooEqual> unordered_set{};
 * */


TEST(SetInt, RemoveElements) {

    // TODO: ....

    std::set<int> set{1,2,3};

    ASSERT_EQ(3u, set.size());
    EXPECT_EQ(1u, set.count(1));
    EXPECT_EQ(1u, set.count(2));
    EXPECT_EQ(1u, set.count(3));

    // TODO: ....
    auto it = set.begin();
    it++;
    set.erase(it);

    ASSERT_EQ(2u, set.size());
    EXPECT_EQ(1u, set.count(1));
    EXPECT_EQ(0u, set.count(2));
    EXPECT_EQ(1u, set.count(3));
}

TEST(SetDouble, ElementsSortedWhenIterating) {

    std::set<double> set;

    ASSERT_TRUE(set.empty());

    // TODO: ....

    set.insert(3.3);
    set.insert(2.2);

    ASSERT_EQ(2u, set.size());
    EXPECT_EQ(1u, set.count(3.3));
    EXPECT_EQ(1u, set.count(2.2));

    set.insert(4.4);
    set.insert(1.1);

    ASSERT_EQ(4u, set.size());
    EXPECT_EQ(1u, set.count(3.3));
    EXPECT_EQ(1u, set.count(2.2));
    EXPECT_EQ(1u, set.count(4.4));
    EXPECT_EQ(1u, set.count(1.1));

    set.insert(0.0);

    auto iter = set.begin();
    EXPECT_EQ(0.0, *iter++);
    EXPECT_EQ(1.1, *iter++);
    EXPECT_EQ(2.2, *iter++);
    EXPECT_EQ(3.3, *iter++);
    EXPECT_EQ(4.4, *iter++);
    EXPECT_EQ(set.end(), iter);
}

TEST(SetString, ElementsSortedInReversedAplhabeticalOrderWhenIterating) {

    struct Comparator {
        // TODO: ....
        //a<b
        bool operator()(const std::string& lhs, const std::string& rhs) const{
            return lhs > rhs;
        }
    };

    // TODO: ....

    std::set<std::string, Comparator> set{"Bb","Ba", "Ab", "Aa"};

    auto iter = set.begin();
    EXPECT_EQ("Bb", *iter++);
    EXPECT_EQ("Ba", *iter++);
    EXPECT_EQ("Ab", *iter++);
    EXPECT_EQ("Aa", *iter++);
    EXPECT_EQ(set.end(), iter);

    set.insert("Ca");

    iter = set.begin();
    EXPECT_EQ("Ca", *iter++);
    EXPECT_EQ("Bb", *iter++);
    EXPECT_EQ("Ba", *iter++);
    EXPECT_EQ("Ab", *iter++);
    EXPECT_EQ("Aa", *iter++);
    EXPECT_EQ(set.end(), iter);

}

TEST(SetInt, InvalidComparatorThatCausesOnlyOneElementToBeInserted) {

    struct Comparator {
        bool operator()(const int& lhs, const int& rhs) const{
            return (!(lhs>rhs)&&!(rhs>lhs));
        }
    };

    std::set<int, Comparator> set{};

    ASSERT_TRUE(set.empty());

    set.insert(1);

    ASSERT_EQ(1u, set.size());

    set.insert(2);

    ASSERT_EQ(1u, set.size());
}

TEST(SetInt, InvalidComparatorThatCausesMultipleCopiesOfTheSameElementToBeInserted) {

    struct Comparator {
        bool operator()(const int& lhs, const int& rhs) const{
            return lhs>=rhs;
        }
    };

    std::set<int, Comparator> set{};

    ASSERT_TRUE(set.empty());

    set.insert(4);
    ASSERT_EQ(1u, set.size());

    set.insert(4);

    ASSERT_EQ(2u, set.size());

    auto it = set.begin();
    std::cout<<*it<<std::endl;
    it++;
    std::cout<<*it<<std::endl;
}

TEST(SetValue, CustomTypeAndComparator) {

    struct Value {
        int n; int m;
    };

    struct Comparator {
        bool operator()(const Value& lhs, const Value& rhs) const{
            return (rhs.n > lhs.n) || (rhs.m > lhs.m);
        }
    };

    std::set<Value, Comparator> set{};

    ASSERT_TRUE(set.empty());

    set.insert({3,0});

    ASSERT_EQ(1u, set.size());
    EXPECT_EQ(1u, set.count(Value{3, 0}));

    set.insert({6,0});

    ASSERT_EQ(2u, set.size());
    EXPECT_EQ(1u, set.count(Value{3, 0}));
    EXPECT_EQ(1u, set.count(Value{6, 0}));

    set.insert({3,3});

    ASSERT_EQ(3u, set.size());
    EXPECT_EQ(1u, set.count(Value{3, 0}));
    EXPECT_EQ(1u, set.count(Value{6, 0}));
    EXPECT_EQ(1u, set.count(Value{3, 3}));

    set.insert({6,6});

    ASSERT_EQ(4u, set.size());
    EXPECT_EQ(1u, set.count(Value{3, 0}));
    EXPECT_EQ(1u, set.count(Value{6, 0}));
    EXPECT_EQ(1u, set.count(Value{3, 3}));
    EXPECT_EQ(1u, set.count(Value{6, 6}));
}

TEST(SetInt, ElementsGreaterThanGivenValue) {

    std::set<int> set{1,2,3,4,5};

    ASSERT_EQ(5u, set.size());
    EXPECT_EQ(1u, set.count(1));
    EXPECT_EQ(1u, set.count(2));
    EXPECT_EQ(1u, set.count(3));
    EXPECT_EQ(1u, set.count(4));
    EXPECT_EQ(1u, set.count(5));

    set.erase(1);
    set.erase(2);
    auto iter = set.begin();
    EXPECT_EQ(3, *iter++);
    EXPECT_EQ(4, *iter++);
    EXPECT_EQ(5, *iter++);
    EXPECT_EQ(set.end(), iter);
}

TEST(MapStringString, CreateUsingInitializerList) {

    std::map<std::string, std::string> map{{"CN", "China"}, {"GR", "Greece"}, {"FR", "France"}};

    ASSERT_EQ(3u, map.size());
    EXPECT_EQ("China", map["CN"]);
    EXPECT_EQ("Greece", map["GR"]);
    EXPECT_EQ("France", map["FR"]);
}


TEST(MapMapStringInt, NestedCollections) {

    std::map<std::string, std::map<std::string, int>> map;

    ASSERT_TRUE(map.empty());

    map.insert({ "count", {{"1", 12}} });

    ASSERT_EQ(1u, map.size());
    ASSERT_EQ(1u, map.count("count"));


    map["count"].insert({"2",4});
    map["count"].insert({"3",2});
    map["count"].insert({"4",7});

    ASSERT_EQ(4u, map["count"].size());
    EXPECT_EQ(12, map["count"]["1"]);
    EXPECT_EQ(4, map["count"]["2"]);
    EXPECT_EQ(2, map["count"]["3"]);
    EXPECT_EQ(7, map["count"]["4"]);
}

TEST(MultisetInt, RemoveRangeOfElements) {

    std::multiset<int> multiset{1,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3};

    ASSERT_EQ(16, multiset.size());
    EXPECT_EQ(1, multiset.count(1));
    EXPECT_EQ(12, multiset.count(2));
    EXPECT_EQ(3, multiset.count(3));

    // TODO: ....
    auto it = multiset.begin();
    it++;
    auto iter = multiset.end();
    iter--; iter--; iter--;
    multiset.erase(it, iter );


    ASSERT_EQ(4, multiset.size());
    EXPECT_EQ(1, multiset.count(1));
    EXPECT_EQ(3, multiset.count(3));
}

TEST(UnorderedSetValue, CustomTypeHashAndComparator) {

    struct Value {
        // TODO: ....
        int a;
        int b;
        int c;
    };

    struct Hash {
        // TODO: ....
        std::size_t operator() (const Value &foo) const noexcept {return 0;}
    };
    struct Equal {
        // TODO: ....
        bool operator()(const Value& lhs, const Value& rhs) const {
            return lhs.a>rhs.b;
        };
    };

    // TODO: ....

    ASSERT_TRUE(unordered_set.empty());

    // TODO: ....

    ASSERT_EQ(1u, unordered_set.size());
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1, 1}));

    // TODO: ....

    ASSERT_EQ(1u, unordered_set.size());
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1, 1}));

    // TODO: ....

    ASSERT_EQ(8u, unordered_set.size());
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{1, 2, 1}));
-    EXPECT_EQ(1u, unordered_set.count(Value{2, 1, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 2, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1, 2}));
    EXPECT_EQ(1u, unordered_set.count(Value{1, 2, 2}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 1, 2}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 2, 2}));
}

/*TEST(UnorderedSetInt, BucketsAndLoadFactor) {

    // TODO: ....

    ASSERT_EQ(1u, unordered_set.size());
    EXPECT_EQ(2u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(1.0 / 2.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    // TODO: ....

    ASSERT_EQ(2u, unordered_set.size());
    EXPECT_EQ(2u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    // TODO: ....

    ASSERT_EQ(3u, unordered_set.size());
    EXPECT_EQ(5u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(3.0 / 5.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    // TODO: ....-+++




































    ASSERT_EQ(4u, unordered_set.size());
    EXPECT_EQ(5u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(4.0 / 5.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    // TODO: ....

    ASSERT_EQ(5u, unordered_set.size());
    EXPECT_EQ(5u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    // TODO: ....

    ASSERT_EQ(10u, unordered_set.size());
    EXPECT_EQ(11u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(10.0 / 11.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    // TODO: ....

    ASSERT_EQ(11u, unordered_set.size());
    EXPECT_EQ(11u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(11.0 / 11.0, unordered_set.load_factor());
}
*/