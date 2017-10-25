#ifndef _SEQUENCE_H
#define _SEQUENCE_H
#include <cstdlib>
#include "node.h"

namespace csis3700
{
template <typename AnyType>
class sequence
{
public:
    typedef std::size_t size_type;
    sequence();
    sequence(const sequence& other);
    ~sequence();
    size_type size() const;
    AnyType get(size_type i) const;
    void add(const AnyType& value);
    void insert(size_type index, const AnyType& value);
    void remove(size_type index);
    void operator +=(const sequence& other);
    void operator =(const sequence& other);

private:
    size_type used;
    node<AnyType> *head_ptr;
};

template<typename AnyType>
sequence<AnyType> operator+(const sequence<AnyType>& s1, const sequence<AnyType>& s2);

}

#include "sequence.hpp"
#endif
