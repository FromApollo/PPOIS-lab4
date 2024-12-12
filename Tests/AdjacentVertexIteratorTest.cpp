#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab4\Project1\Project1\AdjacentVertexIterator.h"

TEST(AdjacentVertexIteratorTest, DefaultConstructor) {
    AdjacentVertexIterator<int> it;
    EXPECT_FALSE(it.is_valid());
}

TEST(AdjacentVertexIteratorTest, ParameterizedConstructor) {
    std::vector<int> data = { 1, 2, 3 };
    AdjacentVertexIterator<int> it(data.begin(), data.begin(), data.end());
    EXPECT_TRUE(it.is_valid());
    EXPECT_EQ(*it, 1);
}

TEST(AdjacentVertexIteratorTest, CopyConstructor) {
    std::vector<int> data = { 1, 2, 3 };
    AdjacentVertexIterator<int> it1(data.begin(), data.begin(), data.end());
    AdjacentVertexIterator<int> it2(it1);
    EXPECT_TRUE(it2.is_valid());
    EXPECT_EQ(*it2, 1);
}

TEST(AdjacentVertexIteratorTest, PrefixIncrement) {
    std::vector<int> data = { 1, 2, 3 };
    AdjacentVertexIterator<int> it(data.begin(), data.begin(), data.end());
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
}

TEST(AdjacentVertexIteratorTest, PostfixIncrement) {
    std::vector<int> data = { 1, 2, 3 };
    AdjacentVertexIterator<int> it(data.begin(), data.begin(), data.end());
    AdjacentVertexIterator<int> oldIt = it++;
    EXPECT_EQ(*oldIt, 1);
    EXPECT_EQ(*it, 2);
    it++;
    EXPECT_EQ(*it, 3);
}

TEST(AdjacentVertexIteratorTest, PrefixDecrement) {
    std::vector<int> data = { 1, 2, 3 };
    AdjacentVertexIterator<int> it(data.begin() + 2, data.begin(), data.end());
    --it;
    EXPECT_EQ(*it, 2);
    --it;
    EXPECT_EQ(*it, 1);
    EXPECT_THROW(--it, std::out_of_range);
}

TEST(AdjacentVertexIteratorTest, PostfixDecrement) {
    std::vector<int> data = { 1, 2, 3 };
    AdjacentVertexIterator<int> it(data.begin() + 2, data.begin(), data.end());
    AdjacentVertexIterator<int> oldIt = it--;
    EXPECT_EQ(*oldIt, 3);
    EXPECT_EQ(*it, 2);
    it--;
    EXPECT_EQ(*it, 1);
    EXPECT_THROW(it--, std::out_of_range);
}

TEST(AdjacentVertexIteratorTest, EqualityOperators) {
    std::vector<int> data = { 1, 2, 3 };
    AdjacentVertexIterator<int> it1(data.begin(), data.begin(), data.end());
    AdjacentVertexIterator<int> it2(data.begin(), data.begin(), data.end());
    AdjacentVertexIterator<int> it3(data.end(), data.begin(), data.end());
    EXPECT_TRUE(it1 == it2);
    EXPECT_FALSE(it1 != it2);
    EXPECT_TRUE(it1 != it3);
}

TEST(AdjacentVertexIteratorTest, Dereference) {
    std::vector<int> data = { 1, 2, 3 };
    AdjacentVertexIterator<int> it(data.begin(), data.begin(), data.end());
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
    EXPECT_THROW(++it; *it, std::out_of_range);
}

TEST(AdjacentVertexIteratorTest, IsValid) {
    std::vector<int> data = { 1, 2, 3 };
    AdjacentVertexIterator<int> it(data.end(), data.begin(), data.end());
    EXPECT_FALSE(it.is_valid());
    it = AdjacentVertexIterator<int>(data.begin(), data.begin(), data.end());
    EXPECT_TRUE(it.is_valid());
}

