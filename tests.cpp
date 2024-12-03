//
// Created by radamir on 03.12.24.
//
#include <stack>

#include "gtest/gtest.h"
#include "../Stack.h"
class StackTesting : public ::testing::Test {
protected:
    StackTesting() = default;
    Stack<long double> stack;
    Stack<long double> stack2;
};
TEST_F(StackTesting, test1) {
    stack<<(15);
    ASSERT_EQ(stack.top(), 15);
}
TEST_F(StackTesting, test2) {
    stack<<(15);
    stack<<(17);
    stack<<(21);
    EXPECT_EQ(stack.top(), 21);
}
TEST_F(StackTesting, test3) {
    EXPECT_THROW(stack.pop(),std::out_of_range);
}
TEST_F(StackTesting, test4) {
    long double t;
    EXPECT_THROW(stack>>(t),std::out_of_range);
}
TEST_F(StackTesting, test5) {
    ASSERT_EQ(stack.empty(), true);
}
TEST_F(StackTesting, test6) {
    stack<<(15);
    ASSERT_EQ(stack.empty(), false);
}
TEST_F(StackTesting, test7) {
    ASSERT_EQ(stack==stack2, true);
}
TEST_F(StackTesting, test8) {
    EXPECT_THROW(stack.top(),std::out_of_range);
}
TEST_F(StackTesting, test9) {
    stack<<(15);
    stack2<<(17);
    EXPECT_EQ(stack>stack2, false);
}
TEST_F(StackTesting, test10) {
    stack<<(17);
    stack2<<(15);
    EXPECT_EQ(stack>stack2, true);
}
TEST_F(StackTesting, test11) {
    stack<<(15);
    stack<<(17);
    stack<<(42);
    EXPECT_EQ(stack>stack2, true);
}
TEST_F(StackTesting, test12) {
    stack<<(15);
    stack<<(17);
    stack<<(42);
    EXPECT_EQ(stack2<stack, true);
}
TEST_F(StackTesting, test13) {
    stack<<(15);
    stack<<(17);
    stack<<(42);
    EXPECT_EQ(stack2>stack, false);
}
TEST_F(StackTesting, test14) {
    stack<<(15);
    stack<<(17);
    stack<<(42);
    stack2 = stack;
    EXPECT_EQ(stack2==stack, true);
}
TEST_F(StackTesting, test15) {
    stack<<(15);
    stack<<(17);
    stack<<(42);
    stack2 = stack;
    EXPECT_EQ(stack2!=stack, false);
}
TEST_F(StackTesting, test16) {
    EXPECT_THROW(stack[0231-57],std::out_of_range);
}
TEST_F(StackTesting, test17) {
    stack<<(15);
    EXPECT_EQ(stack[0],15);
}
TEST_F(StackTesting, test18) {
    ASSERT_EQ(stack.size(), 0);
}
TEST_F(StackTesting, test19) {
    stack<<(15);
    ASSERT_EQ(stack.size(), 1);
}
TEST_F(StackTesting, test20) {
    ASSERT_EQ(stack.capacity(), 16);
}
