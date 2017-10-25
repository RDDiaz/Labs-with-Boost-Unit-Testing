#ifndef _SEQUENCE_H
#define _SEQUENCE_H
#include <cstdlib>

namespace csis3700
{
class sequence
{
public:
    typedef std::size_t size_type;
    typedef int value_type;
    static const size_type CAPACITY = 30;
    sequence();
    sequence(size_type used);
    void add();
    void insert(size_type index, const value_type& value);
    void remove(size_type index);
    size_type size() const;
    value_type get(size_type i) const;
    void add(const value_type& value);
    void operator +=(const sequence& other);
private:
    size_type used;
    value_type items[CAPACITY];
};

    sequence operator+(const sequence& s1, const sequence& s2);

}

#endif
