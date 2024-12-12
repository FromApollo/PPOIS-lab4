#ifndef EDGEITERATOR_H
#define EDGEITERATOR_H

#include <vector>
#include <utility>
#include <stdexcept>

template<typename T>
class EdgeIterator {
public:

    typedef T value_type;
    typedef std::pair<value_type, value_type> edge_type;
    typedef typename std::vector<edge_type>::iterator iterator;


    EdgeIterator() : current(), begin(), end() {}

    EdgeIterator(iterator current, iterator begin, iterator end)
        : current(current), begin(begin), end(end) {}

    EdgeIterator(const EdgeIterator& other)
        : current(other.current), begin(other.begin), end(other.end) {}


    EdgeIterator& operator++() {
        if (current == end) {
            throw std::out_of_range("Incrementing past the end of the iterator");
        }
        ++current;
        return *this;
    }

    EdgeIterator operator++(int) {
        EdgeIterator temp = *this;
        ++(*this);
        return temp;
    }

    EdgeIterator& operator--() {
        if (current == begin) {
            throw std::out_of_range("Decrementing past the beginning of the iterator");
        }
        --current;
        return *this;
    }

    EdgeIterator operator--(int) {
        EdgeIterator temp = *this;
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

    bool operator==(const EdgeIterator& other) const {
        return current == other.current;
    }

    bool operator!=(const EdgeIterator& other) const {
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
