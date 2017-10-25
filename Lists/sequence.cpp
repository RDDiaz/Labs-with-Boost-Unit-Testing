#include "sequence.h"
#include <cassert>
#include <iostream>

namespace csis3700
{

const sequence::size_type sequence::CAPACITY;

sequence::sequence()
{
    used = 0;
}

sequence::size_type sequence::size() const
{
    return used;
}

sequence::value_type sequence::get(size_type i) const
{
    assert(i < size());
    return items[i];
}

void sequence::add(const value_type& value)
{
    assert(size() < CAPACITY);
    items[used] = value;
    used++;

}

void sequence::insert(size_type index, const value_type& value)
{

    assert(index<=size() && size() < CAPACITY);

    if (index == size())
    {
        items[used] = value;
        used++;
    }
    else
    {
        for (size_type i=used-1; i > index; i--)
        {
            items[i+1] = items[i];
        }
        items[index+1] = items[index];
        items[index] = value;
        used++;
    }
}

void sequence::remove(size_type index){

    assert(index<size());

    for (size_type i = index+1; i < used; i++)
        items[i-1] = items[i];

    used--;
  }

sequence operator+(const sequence& s1, const sequence& s2){
    assert(s1.size()+s2.size() <=30);
    sequence temp;

    for (int i = 0; i < s1.size(); i++)
    temp.add(s1.get(i));

    for (int j = 0; j < s2.size(); j++)
    temp.add(s2.get(j));

    return temp;

}

void sequence::operator +=(const sequence& other){
    assert(size()+other.size() <=CAPACITY);

    for (int i=0; i < other.size(); ++i){
        items[used] = (other.get(i));
        used++;
    }
}

}

