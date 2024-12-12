#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab4\Project1\Project1\OrientedGraph.h"


TEST(OrientedGraphTest, AddVertex) {
    OrientedGraph<int> graph;
    graph.add_vertex(1);
    EXPECT_TRUE(graph.has_vertex(1));
    EXPECT_EQ(graph.vertex_count(), 1);
}

TEST(OrientedGraphTest, RemoveVertex) {
    OrientedGraph<int> graph;
    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.remove_vertex(1);
    EXPECT_FALSE(graph.has_vertex(1));
    EXPECT_EQ(graph.vertex_count(), 1);
}

TEST(OrientedGraphTest, AddEdge) {
    OrientedGraph<int> graph;
    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_edge(1, 2);
    EXPECT_TRUE(graph.has_edge(1, 2));
    EXPECT_EQ(graph.edge_count(), 1);
}

TEST(OrientedGraphTest, RemoveEdge) {
    OrientedGraph<int> graph;
    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_edge(1, 2);
    graph.remove_edge(1, 2);
    EXPECT_FALSE(graph.has_edge(1, 2));
    EXPECT_EQ(graph.edge_count(), 0);
}

TEST(OrientedGraphTest, VertexDegree) {
    OrientedGraph<int> graph;
    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_vertex(3);
    graph.add_edge(1, 2);
    graph.add_edge(1, 3);
    EXPECT_EQ(graph.vertex_degree(1), 2);
}

TEST(OrientedGraphTest, EmptyGraph) {
    OrientedGraph<int> graph;
    EXPECT_TRUE(graph.empty());
    graph.add_vertex(1);
    EXPECT_FALSE(graph.empty());
}

TEST(OrientedGraphTest, Iterators) {
    OrientedGraph<int> graph;
    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_vertex(3);
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);

    auto vit = graph.vertices_begin();
    EXPECT_EQ(*vit, 1);
    ++vit;
    EXPECT_EQ(*vit, 2);

    auto eit = graph.edges_begin();
    EXPECT_EQ(*eit, std::make_pair(1, 2));
    ++eit;
    EXPECT_EQ(*eit, std::make_pair(2, 3));
}

TEST(OrientedGraphTest, IncidentEdgeIterator) {
    OrientedGraph<int> graph;
    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_vertex(3);
    graph.add_edge(1, 2);
    graph.add_edge(1, 3);

    auto it = graph.incident_edges_begin(1);
    EXPECT_EQ(*it, std::make_pair(1, 2));
    ++it;
    EXPECT_EQ(*it, std::make_pair(1, 3));
}

TEST(OrientedGraphTest, AdjacentVertexIterator) {
    OrientedGraph<int> graph;
    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_vertex(3);
    graph.add_edge(1, 2);
    graph.add_edge(1, 3);

    auto it = graph.adjacent_vertices_begin(1);
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
}
