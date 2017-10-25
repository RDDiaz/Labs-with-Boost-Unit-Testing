#include "sequence.h"
#include <cassert>
#include <iostream>
using namespace csis3700;

#define BOOST_TEST_MODULE SequenceTests
//#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(new_sequence_is_empty) {
  sequence<double> s1;
  sequence<int> s2;
  sequence<char> s3;
}

BOOST_AUTO_TEST_CASE(copy_constructor_copies_default_constructor) {
  sequence<int>s1;
  sequence<int>s2(s1);
}

BOOST_AUTO_TEST_CASE(add_inserts_nodes_without_error) {
  sequence<int>s1;
  s1.add(1);
}

BOOST_AUTO_TEST_CASE(get_function_returns_target_element) {
  sequence<int> s1;
  s1.add(1);
  BOOST_CHECK_EQUAL(s1.get(0), 1);
}

BOOST_AUTO_TEST_CASE(add_inserts_nodes_at_tail) {
  sequence<int>s1;
  s1.add(1);
  s1.add(2);
  s1.add(3);
  s1.add(4);
  BOOST_CHECK_EQUAL(s1.get(0), 1);
  BOOST_CHECK_EQUAL(s1.get(1), 2);
  BOOST_CHECK_EQUAL(s1.get(2), 3);
  BOOST_CHECK_EQUAL(s1.get(3), 4);
}

BOOST_AUTO_TEST_CASE(insert_replaces_index_value_in_sequence) {
  sequence<int>s1;
  s1.add(0);
  s1.add(1);
  s1.insert(0, 99);
  BOOST_CHECK_EQUAL(s1.get(0), 99);
  BOOST_CHECK_EQUAL(s1.get(1), 0);
  BOOST_CHECK_EQUAL(s1.get(2), 1);
}

BOOST_AUTO_TEST_CASE(insert_shifts_index_values_to_the_right) {
  sequence<int> s;
  s.add(0);
  s.add(1);
  s.add(2);
  s.insert(0,3);
  BOOST_CHECK_EQUAL(s.size(), 4);
}
BOOST_AUTO_TEST_CASE(Remove_removes_index_and_shifts_sequence)
{
    sequence<int> s;
    s.add(0);
    s.add(1);
    s.add(2);
    s.remove(2);
    BOOST_CHECK_EQUAL(s.get(0), 0);
    BOOST_CHECK_EQUAL(s.get(1), 1);
    BOOST_CHECK_EQUAL(s.size(), 2);
    s.remove(0);
    BOOST_CHECK_EQUAL(s.get(0), 1);
    BOOST_CHECK_EQUAL(s.size(), 1);
}

BOOST_AUTO_TEST_CASE(Add_operator_appends_sequence2_onto_end_of_sequence1)
{
    sequence<int> s1;
    sequence<int> s2;
    sequence<int> s3;
    s1.add(0);
    s1.add(1);
    s1.add(2);
    s2.add(3);
    s2.add(4);
    s2.add(5);
    s3+=s1;
    s3+=s2;
    BOOST_CHECK_EQUAL(s3.get(0), 0);
    BOOST_CHECK_EQUAL(s3.get(1), 1);
    BOOST_CHECK_EQUAL(s3.get(2), 2);
    BOOST_CHECK_EQUAL(s3.get(3), 3);
    BOOST_CHECK_EQUAL(s3.get(4), 4);
    BOOST_CHECK_EQUAL(s3.get(5), 5);
}

BOOST_AUTO_TEST_CASE(Assignment_by_sum_appends_other_onto_end_of_given_seqeuence)
{
    sequence<int> s1;
    sequence<int> s2;
    sequence<int> s3;
    s1.add(0);
    s1.add(1);
    s2.add(2);
    s2.add(3);
    s3 = s1 +s2;
    BOOST_CHECK_EQUAL(s3.get(0), 0);
    BOOST_CHECK_EQUAL(s3.get(1), 1);
    BOOST_CHECK_EQUAL(s3.get(2), 2);
    BOOST_CHECK_EQUAL(s3.get(3), 3);
}

