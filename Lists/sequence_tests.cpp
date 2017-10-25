#include "sequence.h"
#include <cassert>
#include <iostream>
using namespace csis3700;

#define BOOST_TEST_MODULE SequenceTests
//#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(new_sequence_is_empty) {
  sequence s;
  BOOST_CHECK_EQUAL(s.size(), 0);
}

BOOST_AUTO_TEST_CASE(add_function_increases_size) {
  sequence s;
  s.add(3);
  s.add(2);
  BOOST_CHECK_EQUAL(s.size(), 2);
}

BOOST_AUTO_TEST_CASE(get_function_returns_target_element) {
  sequence s;
  s.add(3);
  BOOST_CHECK_EQUAL(s.get(0), 3);
}

BOOST_AUTO_TEST_CASE(insert_replaces_index_value_in_sequence) {
  sequence s;
  s.add(0);
  s.add(1);
  s.insert(0, 99);
  BOOST_CHECK_EQUAL(s.get(0), 99);
  BOOST_CHECK_EQUAL(s.get(1), 0);
}

BOOST_AUTO_TEST_CASE(insert_shifts_index_values_to_the_right) {
  sequence s;
  s.add(0);
  s.add(1);
  s.add(2);
  s.insert(0,3);
  BOOST_CHECK_EQUAL(s.get(1), 0);
}

BOOST_AUTO_TEST_CASE(insert_shifts_index_values_and_replaces_index_value)
{
    sequence s;
    s.add(0);
    s.add(1);
    s.add(2);
    std::cout << "---------------" << std::endl;
    s.insert(1,3);
    BOOST_CHECK_EQUAL(s.get(0), 0);
    BOOST_CHECK_EQUAL(s.get(1), 3);
    BOOST_CHECK_EQUAL(s.get(2), 1);
    BOOST_CHECK_EQUAL(s.get(3), 2);

    std::cout <<s.get(0) << std::endl;
    std::cout <<s.get(1) << std::endl;
    std::cout <<s.get(2) << std::endl;
    std::cout <<s.get(3) << std::endl;
}

BOOST_AUTO_TEST_CASE(Remove_removes_index_and_shifts_sequence)

{
    sequence s;
    s.add(0);
    s.add(1);
    s.add(2);
    std::cout << "---------------" << std::endl;
    s.remove(2);

    BOOST_CHECK_EQUAL(s.get(0), 0);
    BOOST_CHECK_EQUAL(s.get(1), 1);

    std::cout <<s.get(0) << std::endl;
    std::cout <<s.get(1) << std::endl;

    s.remove(0);

    BOOST_CHECK_EQUAL(s.get(0), 1);

    std::cout <<s.get(0) << std::endl;
}

BOOST_AUTO_TEST_CASE(Add_operator_appends_sequence2_onto_end_of_sequence1)
{

    sequence s1;
    sequence s2;
    sequence s3;
    std::cout << "---------------" << std::endl;
    s1.add(0);
    s1.add(1);
    s1.add(2);
    s2.add(3);
    s2.add(4);
    s2.add(5);
    s3 = s1+s2;
    std::cout <<s3.get(0) << std::endl;
    std::cout <<s3.get(1) << std::endl;
    std::cout <<s3.get(2) << std::endl;
    std::cout <<s3.get(3) << std::endl;
    std::cout <<s3.get(4) << std::endl;
    std::cout <<s3.get(5) << std::endl;
}

BOOST_AUTO_TEST_CASE(Assignment_by_sum_appends_other_onto_end_of_given_seqeuence)
{
    sequence s1;
    sequence s2;
    std::cout << "---------------" << std::endl;
    s1.add(0);
    s1.add(1);
    s2.add(2);
    s2.add(3);
    s1+=s2;
    std::cout <<s1.get(0) << std::endl;
    std::cout <<s1.get(1) << std::endl;
    std::cout <<s1.get(2) << std::endl;
    std::cout <<s1.get(3) << std::endl;
}
