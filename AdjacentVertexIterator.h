#ifndef ADJACENTVERTEXITERATOR_H
#define ADJACENTVERTEXITERATOR_H

#include <vector>
#include <stdexcept>

template<typename T>
class AdjacentVertexIterator {
public:

    typedef T value_type;
    typedef typename std::vector<value_type>::iterator iterator;

    AdjacentVertexIterator() : current(), begin(), end() {}

    AdjacentVertexIterator(iterator current, iterator begin, iterator end)
        : current(current), begin(begin), end(end) {}

    AdjacentVertexIterator(const AdjacentVertexIterator& other)
        : current(other.current), begin(other.begin), end(other.end) {}


    AdjacentVertexIterator& operator++() {
        if (current == end) {
            throw std::out_of_range("Incrementing past the end of the iterator");
        }
        ++current;
        return *this;
    }

    AdjacentVertexIterator operator++(int) {
        AdjacentVertexIterator temp = *this;
        ++(*this);
        return temp;
    }

    AdjacentVertexIterator& operator--() {
        if (current == begin) {
            throw std::out_of_range("Decrementing past the beginning of the iterator");
        }
        --current;
        return *this;
    }

    AdjacentVertexIterator operator--(int) {
        AdjacentVertexIterator temp = *this;
        --(*this);
        return temp;
    }

    value_type& operator*() {
        if (!is_valid()) {
            throw std::out_of_range("Dereferencing an invalid iterator");
        }
        return *current;
    }

    const value_type& operator*() const {
        if (!is_valid()) {
            throw std::out_of_range("Dereferencing an invalid iterator");
        }
        return *current;
    }

    bool operator==(const AdjacentVertexIterator& other) const {
        return current == other.current;
    }

    bool operator!=(const AdjacentVertexIterator& other) const {
        return !(*this == other);
    }

    bool is_valid() const {
        return current != end;
    }

private:
    iterator current;
    iterator begin;
    iterator end;
};

#endif 
