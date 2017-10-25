#include "sequence.h"
#include <cassert>
#include <cstdlib>
#include <iostream>

namespace csis3700
{

template<typename AnyType>
sequence<AnyType>::sequence()
{
    used = 0;
    head_ptr = NULL;
}

template<typename AnyType>
sequence<AnyType>::sequence(const sequence& other)
{
    node<AnyType> *tail_ptr;
    list_copy(other.head_ptr, head_ptr, tail_ptr);
	used = other.used;
}

template<typename AnyType>
sequence<AnyType>::~sequence()
{
    list_clear(head_ptr);
	used = 0;
}

template <typename AnyType>
typename sequence<AnyType>::size_type sequence<AnyType>::size() const
{
    return used;
}

template <typename AnyType>
AnyType sequence<AnyType>::get(size_type i) const
{
    assert (i >= 0 && i < size());
	const node<AnyType> *cursor;
	cursor = list_locate(head_ptr, i+1);
	return cursor->data();
}

template <typename AnyType>
void sequence<AnyType>::add(const AnyType& value)
{
    if(used == 0){
    list_head_insert(head_ptr, value);
	used++;
    }
    else{
    node<AnyType>* cursor = NULL;
    cursor = list_locate(head_ptr, used);
    list_insert(cursor, value);
    used++;
    }
}

template <typename AnyType>
void sequence<AnyType>::remove(size_type index)
{
    assert (index >=0 && index < size());
    if (index ==0){
    list_head_remove(head_ptr);
    used--;
    }
    else{
    node<AnyType>* cursor = NULL;
    cursor = list_locate(head_ptr, index);
    list_remove(cursor);
    used--;
    }
}

template <typename AnyType>
void sequence<AnyType>::insert(size_type index, const AnyType& value)
{
    if(index == 0)
    {
	list_head_insert(head_ptr, value);
	used++;
    }
    else if(index == used){
    add(value);
    }
    else{
    node<AnyType>* cursor = NULL;
    cursor = list_locate(head_ptr, index);
    list_insert(cursor, value);
    used++;
    }
}

template <typename AnyType>
void sequence<AnyType>::operator +=(const sequence& other)
{
    if (used == 0){
        *this = other;
    }

    else if (used > 0)
	{
        node<AnyType> *tail_ptr = list_locate(head_ptr, used);
        node<AnyType> *copy_head_ptr;
        node<AnyType> *copy_tail_ptr;

	    list_copy(other.head_ptr, copy_head_ptr, copy_tail_ptr);
	    tail_ptr->set_link(copy_head_ptr);
	    used += other.used;
	}
}

template <typename AnyType>
void sequence<AnyType>::operator =(const sequence& other)
{
	node<AnyType> *tail_ptr;

	if (this == &other)
            return;

	list_clear(head_ptr);
	used = 0;

	list_copy(other.head_ptr, head_ptr, tail_ptr);
	used = other.used;
}

template<typename AnyType>
sequence<AnyType> operator+(const sequence<AnyType>& s1, const sequence<AnyType>& s2)
{
    sequence<AnyType> answer;

	answer += s1;
	answer += s2;
	return answer;
}

}

