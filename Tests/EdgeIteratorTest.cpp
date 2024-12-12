#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab4\Project1\Project1\EdgeIterator.h"

TEST(EdgeIteratorTest, DefaultConstructor) {
    EdgeIterator<int> it;
    EXPECT_FALSE(it.is_valid());
}

TEST(EdgeIteratorTest, ParameterizedConstructor) {
    std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 4} };
    EdgeIterator<int> it(edges.begin(), edges.begin(), edges.end());
    EXPECT_TRUE(it.is_valid());
    EXPECT_EQ(*it, std::make_pair(1, 2));
}

TEST(EdgeIteratorTest, CopyConstructor) {
    std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 4} };
    EdgeIterator<int> it1(edges.begin(), edges.begin(), edges.end());
    EdgeIterator<int> it2(it1);
    EXPECT_TRUE(it2.is_valid());
    EXPECT_EQ(*it2, std::make_pair(1, 2));
}

TEST(EdgeIteratorTest, PrefixIncrement) {
    std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 4} };
    EdgeIterator<int> it(edges.begin(), edges.begin(), edges.end());
    ++it;
    EXPECT_EQ(*it, std::make_pair(2, 3));
    ++it;
    EXPECT_EQ(*it, std::make_pair(3, 4));
}

TEST(EdgeIteratorTest, PostfixIncrement) {
    std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 4} };
    EdgeIterator<int> it(edges.begin(), edges.begin(), edges.end());
    EdgeIterator<int> oldIt = it++;
    EXPECT_EQ(*oldIt, std::make_pair(1, 2));
    EXPECT_EQ(*it, std::make_pair(2, 3));
    it++;
    EXPECT_EQ(*it, std::make_pair(3, 4));
}

TEST(EdgeIteratorTest, PrefixDecrement) {
    std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 4} };
    EdgeIterator<int> it(edges.begin() + 2, edges.begin(), edges.end());
    --it;
    EXPECT_EQ(*it, std::make_pair(2, 3));
    --it;
    EXPECT_EQ(*it, std::make_pair(1, 2));
    EXPECT_THROW(--it, std::out_of_range);
}

TEST(EdgeIteratorTest, PostfixDecrement) {
    std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 4} };
    EdgeIterator<int> it(edges.begin() + 2, edges.begin(), edges.end());
    EdgeIterator<int> oldIt = it--;
    EXPECT_EQ(*oldIt, std::make_pair(3, 4));
    EXPECT_EQ(*it, std::make_pair(2, 3));
    it--;
    EXPECT_EQ(*it, std::make_pair(1, 2));
    EXPECT_THROW(it--, std::out_of_range);
}

TEST(EdgeIteratorTest, EqualityOperators) {
    std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 4} };
    EdgeIterator<int> it1(edges.begin(), edges.begin(), edges.end());
    EdgeIterator<int> it2(edges.begin(), edges.begin(), edges.end());
    EdgeIterator<int> it3(edges.end(), edges.begin(), edges.end());
    EXPECT_TRUE(it1 == it2);
    EXPECT_FALSE(it1 != it2);
    EXPECT_TRUE(it1 != it3);
}

TEST(EdgeIteratorTest, Dereference) {
    std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 4} };
    EdgeIterator<int> it(edges.begin(), edges.begin(), edges.end());
    EXPECT_EQ(*it, std::make_pair(1, 2));
    ++it;
    EXPECT_EQ(*it, std::make_pair(2, 3));
    ++it;
    EXPECT_EQ(*it, std::make_pair(3, 4));
    EXPECT_THROW(++it; *it, std::out_of_range);
}

TEST(EdgeIteratorTest, IsValid) {
    std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 4} };
    EdgeIterator<int> it(edges.end(), edges.begin(), edges.end());
    EXPECT_FALSE(it.is_valid());
    it = EdgeIterator<int>(edges.begin(), edges.begin(), edges.end());
    EXPECT_TRUE(it.is_valid());
}

