#include <queue>
#include "TestIncludes.h"
// TODO: ...
TEST(VectorInt, CreateInitialized) {
    std::vector<int> vector{1,2,3};
    ASSERT_EQ(3u, vector.size());
    EXPECT_EQ(1, vector[0]);
    EXPECT_EQ(2, vector[1]);
    EXPECT_EQ(3, vector[2]);
}
TEST(VectorDouble, CreateEmptyAndAddValuesAtTheEnd) {
    std::vector<int> vector;
    ASSERT_EQ(0u, vector.size());
    ASSERT_TRUE(vector.empty());
    vector.push_back(11);
    vector.push_back(13);
    vector.push_back(17);
    ASSERT_EQ(3u, vector.size());
    EXPECT_DOUBLE_EQ(11, vector[0]);
    EXPECT_DOUBLE_EQ(13, vector[1]);
    EXPECT_DOUBLE_EQ(17, vector[2]);
}
TEST(VectorFloat, CreateUsingInitializerList) {
    std::vector<int> vector{10,20,30};
    ASSERT_EQ(3u, vector.size());
    EXPECT_FLOAT_EQ(10, vector[0]);
    EXPECT_FLOAT_EQ(20, vector[1]);
    EXPECT_FLOAT_EQ(30, vector[2]);
}
TEST(VectorInt, SizeShouldBeLessThanOrEqualToCapacity) {
    std::vector<int> vector{1,2,3};
    vector.shrink_to_fit();
    ASSERT_EQ(3u, vector.size());
    EXPECT_FLOAT_EQ(1, vector[0]);
    EXPECT_FLOAT_EQ(2, vector[1]);
    EXPECT_FLOAT_EQ(3, vector[2]);
    EXPECT_EQ(vector.capacity(), vector.size());
    vector.insert(vector.begin(), 4);
    //vector.erase(vector.end());
    ASSERT_EQ(4u, vector.size());
    EXPECT_FLOAT_EQ(4, vector[0]);
    EXPECT_FLOAT_EQ(1, vector[1]);
    EXPECT_FLOAT_EQ(2, vector[2]);
    EXPECT_FLOAT_EQ(3, vector[3]);
    EXPECT_GE(vector.capacity(), vector.size());
    vector.shrink_to_fit();
    ASSERT_EQ(4u, vector.size());
    EXPECT_EQ(vector.capacity(), vector.size());
}
TEST(VectorFloat, CopyToOtherVectorUsingAssign) {
    std::vector<int> input{1,2,3};
    std::vector<int> output;
    ASSERT_EQ(3u, input.size());
    EXPECT_EQ(1, input[0]);
    EXPECT_EQ(2, input[1]);
    EXPECT_EQ(3, input[2]);
    ASSERT_TRUE(output.empty());
    output.assign(input.begin()+1, input.end());
    ASSERT_EQ(2u, output.size());
    EXPECT_EQ(2, output[0]);
    EXPECT_EQ(3, output[1]);
    ASSERT_EQ(3u, input.size());
    EXPECT_EQ(1, input[0]);
    EXPECT_EQ(2, input[1]);
    EXPECT_EQ(3, input[2]);
}
TEST(VectorFloat, EraseFrontValue) {
    std::vector<int> vector{1,2,3};
    ASSERT_EQ(3u, vector.size());
    EXPECT_FLOAT_EQ(1, vector[0]);
    EXPECT_FLOAT_EQ(2, vector[1]);
    EXPECT_FLOAT_EQ(3, vector[2]);
    vector.erase(vector.begin());
    ASSERT_EQ(2u, vector.size());
    EXPECT_FLOAT_EQ(2, vector[0]);
    EXPECT_FLOAT_EQ(3, vector[1]);
}
TEST(VectorVectorVectorFloat, ThreeDimensionalVector) {
    std::vector<std::vector<std::vector<int> > > vector (2,std::vector<std::vector<int> >(2));
    vector = {{{1,2},{3,4}},{{5,6},{7,8}}};
    ASSERT_EQ(2u, vector.size());
    ASSERT_EQ(2u, vector[0].size());
    ASSERT_EQ(2u, vector[1].size());
    ASSERT_EQ(2u, vector[0][0].size());
    ASSERT_EQ(2u, vector[0][1].size());
    ASSERT_EQ(2u, vector[1][0].size());
    ASSERT_EQ(2u, vector[1][1].size());
    EXPECT_FLOAT_EQ(1, vector[0][0][0]);
    EXPECT_FLOAT_EQ(2, vector[0][0][1]);
    EXPECT_FLOAT_EQ(3, vector[0][1][0]);
    EXPECT_FLOAT_EQ(4, vector[0][1][1]);
    EXPECT_FLOAT_EQ(5, vector[1][0][0]);
    EXPECT_FLOAT_EQ(6, vector[1][0][1]);
    EXPECT_FLOAT_EQ(7, vector[1][1][0]);
    EXPECT_FLOAT_EQ(8, vector[1][1][1]);
}
TEST(ArrayInt, FillWithTheSameValue) {
    std::array<int,1000> array;
    for(int i = 0; i< 1000; i++){
        array[i] = 0;
    }
    for (auto i = 0u; i < 1000; i++) {
        ASSERT_EQ(0, array[i]);
    }
    for(int i = 0; i< 1000; i++){
        array[i] = 7;
    }
    for (auto i = 0u; i < 1000; i++) {
        ASSERT_EQ(7, array[i]);
    }
}
TEST(ArrayInt, SizeDefinedAtCompileTime) {
    std::array<int, 4> array;
    static_assert(array.size() == 4, "Compilation error: wrong array size");
    for(int i=0; i<4; i++){
        array[i] = i+1;
    }
    ASSERT_EQ(1u, array[0]);
    ASSERT_EQ(2u, array[1]);
    ASSERT_EQ(3u, array[2]);
    ASSERT_EQ(4u, array[3]);
}
TEST(ArrayInt, Sort) {
    std::array<int, 5> array{5,3,4,1,2};
    EXPECT_EQ(5, array[0]);
    EXPECT_EQ(3, array[1]);
    EXPECT_EQ(4, array[2]);
    EXPECT_EQ(1, array[3]);
    EXPECT_EQ(2, array[4]);
    std::sort(array.begin(), array.end());
    EXPECT_EQ(1, array[0]);
    EXPECT_EQ(2, array[1]);
    EXPECT_EQ(3, array[2]);
    EXPECT_EQ(4, array[3]);
    EXPECT_EQ(5, array[4]);
}
TEST(ArrayChar, CreateCopy) {
    std::array<char, 5> arrayIn{'a', 'b', 'c', 'd', '\0'};
    ASSERT_EQ(5u, arrayIn.size());
    ASSERT_EQ('a', arrayIn[0]);
    ASSERT_EQ('b', arrayIn[1]);
    ASSERT_EQ('c', arrayIn[2]);
    ASSERT_EQ('d', arrayIn[3]);
    ASSERT_EQ('\0', arrayIn[4]);
    EXPECT_STREQ("abcd", arrayIn.data());
    std::array<char, 5> arrayOut = arrayIn;
    ASSERT_EQ(5u, arrayIn.size());
    EXPECT_STREQ("abcd", arrayIn.data());
    ASSERT_EQ(5u, arrayOut.size());
    EXPECT_STREQ("abcd", arrayOut.data());
}
TEST(ListFloat, Sort) {
    std::list<float> list(998, 1);
    list.push_front(255);
    list.push_back(13);
    ASSERT_EQ(1000, list.size());
    EXPECT_FALSE(std::is_sorted(list.begin(), list.end()));
    list.sort();
    ASSERT_EQ(1000, list.size());
    EXPECT_TRUE(std::is_sorted(list.begin(), list.end()));
}
TEST(ListInt, MergeSortedLists) {
    std::list<int> a{1,3,5};
    std::list<int> b{2,4,6};
    auto iter = a.begin();
    EXPECT_EQ(1, *(iter++));
    EXPECT_EQ(3, *(iter++));
    EXPECT_EQ(5, *(iter++));
    EXPECT_EQ(a.end(), iter);
    iter = b.begin();
    EXPECT_EQ(2, *(iter++));
    EXPECT_EQ(4, *(iter++));
    EXPECT_EQ(6, *(iter++));
    EXPECT_EQ(b.end(), iter);
    a.merge(b);
    a.sort();
    EXPECT_EQ(0, b.size());
    EXPECT_EQ(6, a.size());
    iter = a.begin();
    EXPECT_EQ(1, *(iter++));
    EXPECT_EQ(2, *(iter++));
    EXPECT_EQ(3, *(iter++));
    EXPECT_EQ(4, *(iter++));
    EXPECT_EQ(5, *(iter++));
    EXPECT_EQ(6, *(iter++));
    EXPECT_EQ(a.end(), iter);
}
TEST(ForwardListFloat, InsertElementAfterIndex) {
    std::forward_list<float> forwardList = {1,2,3,4};
    auto iter = forwardList.begin();
    EXPECT_EQ(1, *(iter++));
    EXPECT_EQ(2, *(iter++));
    EXPECT_EQ(3, *(iter++));
    EXPECT_EQ(4, *(iter++));
    EXPECT_EQ(forwardList.end(), iter);
    auto it = forwardList.begin();
    it++;
    forwardList.insert_after(it, 10);
    iter = forwardList.begin();
    EXPECT_EQ(1, *(iter++));
    EXPECT_EQ(2, *(iter++));
    EXPECT_EQ(10, *(iter++));
    EXPECT_EQ(3, *(iter++));
    EXPECT_EQ(4, *(iter++));
    EXPECT_EQ(forwardList.end(), iter);
}
TEST(DequeInt, RemoveFirstElement) {
    std::deque<int> deque = {1,2,3};
    ASSERT_EQ(3u, deque.size());
    EXPECT_FLOAT_EQ(1, deque[0]);
    EXPECT_FLOAT_EQ(2, deque[1]);
    EXPECT_FLOAT_EQ(3, deque[2]);
    deque.pop_front();
    ASSERT_EQ(2u, deque.size());
    EXPECT_FLOAT_EQ(2, deque[0]);
    EXPECT_FLOAT_EQ(3, deque[1]);
}
TEST(StackInt, PushAndPop) {
    std::stack<int> stack;
    EXPECT_TRUE(stack.empty());
    stack.push(1);
    stack.push(2);
    ASSERT_EQ(2u, stack.size());
    EXPECT_EQ(2, stack.top());
    stack.pop();
    ASSERT_EQ(1u, stack.size());
    EXPECT_EQ(1, stack.top());
    stack.pop();
    ASSERT_EQ(0u, stack.size());
}
TEST(PriorityQueueChar, PushAndPop) {
    std::priority_queue<char> priority_queue;
    ASSERT_TRUE(priority_queue.empty());
    priority_queue.push(1);
    priority_queue.push(3);
    ASSERT_EQ(2u, priority_queue.size());
    EXPECT_EQ(3, priority_queue.top());
    priority_queue.pop();
    priority_queue.push(2);
    priority_queue.push(3);
    priority_queue.push(4);
    ASSERT_EQ(4u, priority_queue.size());
    EXPECT_EQ(4, priority_queue.top());
    priority_queue.pop();
    ASSERT_EQ(3u, priority_queue.size());
    EXPECT_EQ(3, priority_queue.top());
    priority_queue.pop();
    ASSERT_EQ(2u, priority_queue.size());
    EXPECT_EQ(2, priority_queue.top());
    priority_queue.pop();
    ASSERT_EQ(1u, priority_queue.size());
    EXPECT_EQ(1, priority_queue.top());
    // TODO: ...
    priority_queue.pop();
    ASSERT_TRUE(priority_queue.empty());
}
