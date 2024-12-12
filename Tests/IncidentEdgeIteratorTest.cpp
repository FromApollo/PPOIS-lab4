#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab4\Project1\Project1\IncidentEdgeIterator.h"

TEST(IncidentEdgeIteratorTest, DefaultConstructor) {
    IncidentEdgeIterator<int> it;
    EXPECT_FALSE(it.is_valid());
}

TEST(IncidentEdgeIteratorTest, ParameterizedConstructor) {
    std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 1} };
    int vertex = 1;
    IncidentEdgeIterator<int> it(edges.begin(), edges.begin(), edges.end(), vertex);
    EXPECT_TRUE(it.is_valid());
    EXPECT_EQ(*it, std::make_pair(1, 2));
}

TEST(IncidentEdgeIteratorTest, CopyConstructor) {
    std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 1} };
    int vertex = 1;
    IncidentEdgeIterator<int> it1(edges.begin(), edges.begin(), edges.end(), vertex);
    IncidentEdgeIterator<int> it2(it1);
    EXPECT_TRUE(it2.is_valid());
    EXPECT_EQ(*it2, std::make_pair(1, 2));
}

TEST(IncidentEdgeIteratorTest, PrefixIncrement) {
    std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 1} };
    int vertex = 1;
    IncidentEdgeIterator<int> it(edges.begin(), edges.begin(), edges.end(), vertex);
    ++it;
    EXPECT_EQ(*it, std::make_pair(2, 3));
    ++it;
    EXPECT_EQ(*it, std::make_pair(3, 1));
}

TEST(IncidentEdgeIteratorTest, PostfixIncrement) {
    std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 1} };
    int vertex = 1;
    IncidentEdgeIterator<int> it(edges.begin(), edges.begin(), edges.end(), vertex);
    IncidentEdgeIterator<int> oldIt = it++;
    EXPECT_EQ(*oldIt, std::make_pair(1, 2));
    EXPECT_EQ(*it, std::make_pair(2, 3));
    it++;
    EXPECT_EQ(*it, std::make_pair(3, 1));
}

TEST(IncidentEdgeIteratorTest, PrefixDecrement) {
    std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 1} };
    int vertex = 1;
    IncidentEdgeIterator<int> it(edges.begin() + 2, edges.begin(), edges.end(), vertex);
    --it;
    EXPECT_EQ(*it, std::make_pair(2, 3));
    --it;
    EXPECT_EQ(*it, std::make_pair(1, 2));
   EXPECT_THROW(--it, std::out_of_range);
}

TEST(IncidentEdgeIteratorTest, PostfixDecrement) {
    std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 1} };
    int vertex = 1;
    IncidentEdgeIterator<int> it(edges.begin() + 2, edges.begin(), edges.end(), vertex);
    IncidentEdgeIterator<int> oldIt = it--;
    EXPECT_EQ(*oldIt, std::make_pair(3, 1));
    EXPECT_EQ(*it, std::make_pair(2, 3));
    it--;
    EXPECT_EQ(*it, std::make_pair(1, 2));
    EXPECT_THROW(it--, std::out_of_range);
}

TEST(IncidentEdgeIteratorTest, Dereference) {
    std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 1} };
    int vertex = 1;
    IncidentEdgeIterator<int> it(edges.begin(), edges.begin(), edges.end(), vertex);
    EXPECT_EQ(*it, std::make_pair(1, 2));
    ++it;
    EXPECT_EQ(*it, std::make_pair(2, 3));
}

TEST(IncidentEdgeIteratorTest, EqualityOperators) {
    std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 1} };
    int vertex = 1;
    IncidentEdgeIterator<int> it1(edges.begin(), edges.begin(), edges.end(), vertex);
    IncidentEdgeIterator<int> it2(edges.begin(), edges.begin(), edges.end(), vertex);
    IncidentEdgeIterator<int> it3(edges.end(), edges.begin(), edges.end(), vertex);
    EXPECT_TRUE(it1 == it2);
    EXPECT_FALSE(it1 != it2);
    EXPECT_TRUE(it1 != it3);
}

TEST(IncidentEdgeIteratorTest, IsValid) {
    std::vector<std::pair<int, int>> edges = { {1, 2}, {2, 3}, {3, 1} };
    int vertex = 1;
    IncidentEdgeIterator<int> it(edges.end(), edges.begin(), edges.end(), vertex);
    EXPECT_FALSE(it.is_valid());
    it = IncidentEdgeIterator<int>(edges.begin(), edges.begin(), edges.end(), vertex);
    EXPECT_TRUE(it.is_valid());
}
