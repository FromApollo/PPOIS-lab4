#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab4\Project1\Project1\VertexIterator.h"

class VertexIteratorTest : public ::testing::Test {
protected:
    void SetUp() override {
        data = { 1, 2, 3, 4, 5 };
        beginIter = data.begin();
        endIter = data.end();
    }

    std::vector<int> data;
    std::vector<int>::iterator beginIter;
    std::vector<int>::iterator endIter;
};

TEST_F(VertexIteratorTest, DefaultConstructor) {
    VertexIterator<int> it;
    EXPECT_FALSE(it.is_valid());
}

TEST_F(VertexIteratorTest, IncrementOperator) {
    VertexIterator<int> it(beginIter, beginIter, endIter);
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
}

TEST_F(VertexIteratorTest, IncrementPastEndThrows) {
    VertexIterator<int> it(endIter, beginIter, endIter);
    EXPECT_THROW(++it, std::out_of_range);
}

TEST_F(VertexIteratorTest, DecrementOperator) {
    VertexIterator<int> it(endIter - 1, beginIter, endIter);
    EXPECT_EQ(*it, 5);
    --it;
    EXPECT_EQ(*it, 4);
}

TEST_F(VertexIteratorTest, DecrementPastBeginThrows) {
    VertexIterator<int> it(beginIter, beginIter, endIter);
    EXPECT_THROW(--it, std::out_of_range);
}

TEST_F(VertexIteratorTest, DereferenceOperator) {
    VertexIterator<int> it(beginIter, beginIter, endIter);
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
}

TEST_F(VertexIteratorTest, DereferenceInvalidIteratorThrows) {
    VertexIterator<int> it(endIter, beginIter, endIter);
    EXPECT_THROW(*it, std::out_of_range);
}

TEST_F(VertexIteratorTest, EqualityOperator) {
    VertexIterator<int> it1(beginIter, beginIter, endIter);
    VertexIterator<int> it2(beginIter, beginIter, endIter);
    EXPECT_TRUE(it1 == it2);

    ++it1;
    EXPECT_FALSE(it1 == it2);
}

TEST_F(VertexIteratorTest, InequalityOperator) {
    VertexIterator<int> it1(beginIter, beginIter, endIter);
    VertexIterator<int> it2(beginIter, beginIter, endIter);
    EXPECT_FALSE(it1 != it2);

    ++it1;
    EXPECT_TRUE(it1 != it2);
}

