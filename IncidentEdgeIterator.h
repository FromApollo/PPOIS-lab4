#ifndef INCIDENTEDGEITERATOR_H
#define INCIDENTEDGEITERATOR_H

#include <vector>
#include <stdexcept>

template<typename T>
class IncidentEdgeIterator {
public:

    typedef T value_type;
    typedef std::pair<value_type, value_type> edge_type;
    typedef typename std::vector<edge_type>::iterator iterator;


    IncidentEdgeIterator() : current(), begin(), end(), vertex() {}

    IncidentEdgeIterator(iterator current, iterator begin, iterator end, const value_type& vertex)
        : current(current), begin(begin), end(end), vertex(vertex) {}

    IncidentEdgeIterator(const IncidentEdgeIterator& other)
        : current(other.current), begin(other.begin), end(other.end), vertex(other.vertex) {}


    IncidentEdgeIterator& operator++() {
        if (current == end) {
            throw std::out_of_range("Incrementing past the end of the iterator");
        }
        ++current;
        return *this;
    }

    IncidentEdgeIterator operator++(int) {
        IncidentEdgeIterator temp = *this;
        ++(*this);
        return temp;
    }

    IncidentEdgeIterator& operator--() {
        if (current == begin) {
            throw std::out_of_range("Decrementing past the beginning of the iterator");
        }
        --current;
        return *this;
    }

    IncidentEdgeIterator operator--(int) {
        IncidentEdgeIterator temp = *this;
        --(*this);
        return temp;
    }

    edge_type& operator*() {
        if (!is_valid()) {
            throw std::out_of_range("Dereferencing an invalid iterator");
        }
        return *current;
    }

    const edge_type& operator*() const {
        if (!is_valid()) {
            throw std::out_of_range("Dereferencing an invalid iterator");
        }
        return *current;
    }

    bool operator==(const IncidentEdgeIterator& other) const {
        return current == other.current;
    }

    bool operator!=(const IncidentEdgeIterator& other) const {
        return !(*this == other);
    }


    bool is_valid() const {
        return current != end;
    }

private:
    iterator current;
    iterator begin;
    iterator end;
    value_type vertex;
};

#endif 