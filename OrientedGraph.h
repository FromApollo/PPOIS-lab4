#ifndef ORIENTEDGRAPH_H
#define ORIENTEDGRAPH_H

#include <vector>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include "AdjacentVertexIterator.h"
#include "EdgeIterator.h"
#include "IncidentEdgeIterator.h"
#include "VertexIterator.h"

template<typename T>
class OrientedGraph {
public:
    typedef T value_type;
    typedef std::pair<value_type, value_type> edge_type;

    typedef VertexIterator<T> iterator;
    typedef EdgeIterator<T> edge_iterator;
    typedef IncidentEdgeIterator<T> incident_edge_iterator;
    typedef AdjacentVertexIterator<T> adjacent_vertex_iterator;

    OrientedGraph() : vertices(), edges() {}

    OrientedGraph(const OrientedGraph& other)
        : vertices(other.vertices), edges(other.edges) {}

    ~OrientedGraph() {}

    bool empty() const {
        return vertices.empty() && edges.empty();
    }

    void clear() {
        vertices.clear();
        edges.clear();
    }

    size_t vertex_count() const {
        return vertices.size();
    }

    size_t edge_count() const {
        return edges.size();
    }

    bool has_vertex(const value_type& vertex) const {
        return std::find(vertices.begin(), vertices.end(), vertex) != vertices.end();
    }

    bool has_edge(const value_type& from, const value_type& to) const {
        return std::find(edges.begin(), edges.end(), edge_type(from, to)) != edges.end();
    }

    void add_vertex(const value_type& vertex) {
        if (!has_vertex(vertex)) {
            vertices.push_back(vertex);
        }
    }

    void remove_vertex(const value_type& vertex) {
        auto it = std::find(vertices.begin(), vertices.end(), vertex);
        if (it != vertices.end()) {
            vertices.erase(it);
            edges.erase(std::remove_if(edges.begin(), edges.end(),
                [&vertex](const edge_type& edge) {
                    return edge.first == vertex || edge.second == vertex;
                }),
                edges.end());
        }
    }

    void add_edge(const value_type& from, const value_type& to) {
        if (!has_vertex(from) || !has_vertex(to)) {
            throw std::invalid_argument("Both vertices must exist in the graph");
        }
        if (!has_edge(from, to)) {
            edges.emplace_back(from, to);
        }
    }

    void remove_edge(const value_type& from, const value_type& to) {
        auto it = std::find(edges.begin(), edges.end(), edge_type(from, to));
        if (it != edges.end()) {
            edges.erase(it);
        }
    }

    size_t vertex_degree(const value_type& vertex) const {
        validate_vertex(vertex);
        return std::count_if(edges.begin(), edges.end(),
            [&vertex](const edge_type& edge) {
                return edge.first == vertex;
            });
    }

    iterator vertices_begin() {
        return iterator(vertices.begin(), vertices.begin(), vertices.end());
    }

    iterator vertices_end() {
        return iterator(vertices.end(), vertices.begin(), vertices.end());
    }

    edge_iterator edges_begin() {
        return edge_iterator(edges.begin(), edges.begin(), edges.end());
    }

    edge_iterator edges_end() {
        return edge_iterator(edges.end(), edges.begin(), edges.end());
    }

    incident_edge_iterator incident_edges_begin(const value_type& vertex) {
        validate_vertex(vertex);
        return incident_edge_iterator(edges.begin(), edges.begin(), edges.end(), vertex);
    }

    incident_edge_iterator incident_edges_end(const value_type& vertex) {
        return incident_edge_iterator(edges.end(), edges.begin(), edges.end(), vertex);
    }

    adjacent_vertex_iterator adjacent_vertices_begin(const value_type& vertex) {
        validate_vertex(vertex);
        for (auto it = edges.begin(); it != edges.end(); ++it) {
            if (it->first == vertex) {
                return adjacent_vertex_iterator(std::find(vertices.begin(), vertices.end(), it->second), vertices.begin(), vertices.end());
            }
            if (it->second == vertex) {
                return adjacent_vertex_iterator(std::find(vertices.begin(), vertices.end(), it->first), vertices.begin(), vertices.end());
            }
        }
        return adjacent_vertex_iterator(vertices.end(), vertices.begin(), vertices.end());
    }

    adjacent_vertex_iterator adjacent_vertices_end(const value_type& vertex) {
        return adjacent_vertex_iterator(vertices.end(), vertices.begin(), vertices.end());
    }

    friend std::ostream& operator<<(std::ostream& os, const OrientedGraph<T>& graph) {
        for (const auto& edge : graph.edges) {
            os << edge.first << "->" << edge.second << " \n";
        }
        return os;
    }

private:
    std::vector<value_type> vertices;
    std::vector<edge_type> edges;

    void validate_vertex(const value_type& vertex) const {
        if (!has_vertex(vertex)) {
            throw std::invalid_argument("Vertex does not exist in the graph");
        }
    }
};

#endif
