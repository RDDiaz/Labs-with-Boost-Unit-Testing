#include "bigint.h"
#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace csis3700;

#define BOOST_TEST_MODULE BigIntTests
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

///********CONSTRUCTOR TESTS********
BOOST_AUTO_TEST_CASE(long_long_constructor_should_not_produce_error_test1)
{
    bigint i1(0);
}

BOOST_AUTO_TEST_CASE(long_long_constructor_should_not_produce_error_test2)
{
    bigint i1(0);
    BOOST_CHECK_EQUAL(i1.get_digit(0), 0);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 1);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(long_long_constructor_should_not_produce_error_test3)
{
    bigint i1(9876543210);
    BOOST_CHECK_EQUAL(i1.get_digit(0), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 1);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 2);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 3);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 4);
    BOOST_CHECK_EQUAL(i1.get_digit(5), 5);
    BOOST_CHECK_EQUAL(i1.get_digit(6), 6);
    BOOST_CHECK_EQUAL(i1.get_digit(7), 7);
    BOOST_CHECK_EQUAL(i1.get_digit(8), 8);
    BOOST_CHECK_EQUAL(i1.get_digit(9), 9);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 10);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(long_long_constructor_should_not_produce_error_test4)
{
    bigint i1(-9876543210);
    BOOST_CHECK_EQUAL(i1.get_digit(0), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 1);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 2);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 3);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 4);
    BOOST_CHECK_EQUAL(i1.get_digit(5), 5);
    BOOST_CHECK_EQUAL(i1.get_digit(6), 6);
    BOOST_CHECK_EQUAL(i1.get_digit(7), 7);
    BOOST_CHECK_EQUAL(i1.get_digit(8), 8);
    BOOST_CHECK_EQUAL(i1.get_digit(9), 9);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 10);
    BOOST_CHECK_EQUAL(i1.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(uint8_t_size_t_bool_constructor_should_not_produce_error)
{
    uint8_t a[] = {1,2,3,4,5,6,7,8,9};
    bigint i1(a,9,false);
    bigint i2(a,9,true);
}

BOOST_AUTO_TEST_CASE(copy_constructor_should_not_produce_error)
{
    uint8_t a[] = {1,2,3,4,5,6,7,8,9};
    bigint i1(a,9,false);
    bigint i2(i1);
}

BOOST_AUTO_TEST_CASE(copy2_constructor_should_not_produce_error)
{
    bigint i0;
    bigint i1(123456789);
    bigint i2(i1);
    bigint i3(i0);
}


///********METHOD TESTS********
BOOST_AUTO_TEST_CASE(negate_method_should_not_produce_error)
{
    uint8_t a[] = {1,2,3,4,5,6,7,8,9};
    bigint i1(a, 9, true);
    i1.negate();
}

BOOST_AUTO_TEST_CASE(negate_method_should_return_bigint_with_opp_sign)
{
    uint8_t a[] = {1,2,3,4,5,6,7,8,9};
    bigint i1(a, 9, true);
    bigint i2(i1.negate());
    BOOST_CHECK_EQUAL(i2.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(get_digit_count_method_should_return_used)
{
    uint8_t a[] = {1,2,3,4,5,6,7,8,9};
    bigint i1(a, 9, true);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 9);
}

BOOST_AUTO_TEST_CASE(get_digit_method_should_return_digit_at_index)
{
    uint8_t a[] = {1,2,3,4,5,6,7,8,9};
    bigint i1(a, 9, true);
    BOOST_CHECK_EQUAL(i1.get_digit(5), 6);
}

BOOST_AUTO_TEST_CASE(abs_method_should_return_absolute_value_of_bigint)
{
    uint8_t a[] = {1,2,3,4,5,6,7,8,9};
    bigint i1(a, 9, true);
    bigint i2 = i1.abs();
    BOOST_CHECK_EQUAL(i2.is_negative(), false);
}

///********OPERATOR TESTS********

BOOST_AUTO_TEST_CASE(equals_equals_operator_should_return_true_if_digits_and_sign_are_the_same)
{
    uint8_t a[] = {1,2,3,4,5,6,7,8,9};
    bigint i1(a, 9, true);
    bigint i2 = i1.abs();
    BOOST_CHECK_EQUAL(i1==i2, false);
}

BOOST_AUTO_TEST_CASE(not_equal_to_operator_should_return_true_if_not_equal)
{
    uint8_t a[] = {1,2,3,4,5,6,7,8,9};
    bigint i1(a, 9, true);
    bigint i2 = i1.abs();
    BOOST_CHECK_EQUAL(i1!=i2, true);
}

BOOST_AUTO_TEST_CASE(less_than_operator_should_return_true_if_i1_is_less_than_i2_test1)
{
    uint8_t a[] = {2,3,4,5,6,7,8,9};
    uint8_t b[] = {1,2,3,4,5,6,7,8,9};
    bigint i1(a, 8, false);
    bigint i2(b, 9, false);
    BOOST_CHECK_EQUAL(i1<i2, true);
}

BOOST_AUTO_TEST_CASE(less_than_operator_should_return_true_if_i1_is_less_than_i2_test2)
{
    uint8_t a[] = {1,2,3,4,5,6,7,8,9};
    uint8_t b[] = {1,2,3,4,5,6,7,8,9};
    bigint i1(a, 9, false);
    bigint i2(b, 9, false);
    BOOST_CHECK_EQUAL(i1<i2, false);
}

BOOST_AUTO_TEST_CASE(less_than_operator_should_return_true_if_i1_is_less_than_i2_test3)
{
    uint8_t a[] = {2,2,3,4,5,6,7,8,9};
    uint8_t b[] = {2,3,4,5,6,7,8,9};
    bigint i1(a, 9, false);
    bigint i2(b, 8, false);
    BOOST_CHECK_EQUAL(i1<i2, false);
}

BOOST_AUTO_TEST_CASE(less_than_operator_should_return_true_if_i1_is_less_than_i2_test4)
{
    uint8_t a[] = {9,9,9,9};
    uint8_t b[] = {1};
    bigint i1(a, 4, true);
    bigint i2(b, 1, true);
    BOOST_CHECK_EQUAL(i1<i2, true);
}

BOOST_AUTO_TEST_CASE(less_than_operator_should_return_true_if_i1_is_less_than_i2_test5)
{
    uint8_t a[] = {9};
    uint8_t b[] = {9,9,9,9};
    bigint i1(a, 1, true);
    bigint i2(b, 4, true);
    BOOST_CHECK_EQUAL(i1<i2, false);
}

BOOST_AUTO_TEST_CASE(less_than_operator_should_return_true_if_i1_is_less_than_i2_test6)
{
    uint8_t a[] = {9};
    uint8_t b[] = {9,9,9,9};
    bigint i1(a, 1, true);
    bigint i2(b, 4, false);
    BOOST_CHECK_EQUAL(i1<i2, true);
}

BOOST_AUTO_TEST_CASE(less_than_operator_should_return_true_if_i1_is_less_than_i2_test7)
{
    uint8_t a[] = {9};
    uint8_t b[] = {9,9,9,9};
    bigint i1(a, 1, false);
    bigint i2(b, 4, true);
    BOOST_CHECK_EQUAL(i1<i2, false);
}

BOOST_AUTO_TEST_CASE(equals_operator_should_assign_bigint_to_new_bigint_test1)
{
    uint8_t a[] = {1,2,3,4,5,6,7,8,9};
    bigint i1(a,9,false);
    bigint i2 = i1;
    BOOST_CHECK_EQUAL(i1==i2, true);
}

BOOST_AUTO_TEST_CASE(equals_operator_should_assign_bigint_to_new_bigint_test2)
{
    uint8_t a[] = {1,2,3,4,5,6,7,8,9};
    uint8_t b[] = {9,8,7,6,5,4,3,2,1};
    bigint i1(a,9,false);
    bigint i2 = i1;
    bigint i3(b,9,false);
    bigint i4(i3);
    BOOST_CHECK_EQUAL(i1==i2, true);
    BOOST_CHECK_EQUAL(i4==i3, true);
}

BOOST_AUTO_TEST_CASE(greater_than_operator_should_return_true_if_i1_is_greater_than_i2_test1)
{
    uint8_t a[] = {1,2,3,4,5,6,7,8,9};
    uint8_t b[] = {9,8,7,6,5,4,3,2,1};
    bigint i1(a,9,false);
    bigint i2(b,9,false);
    BOOST_CHECK_EQUAL(i1>i2, true);
}

BOOST_AUTO_TEST_CASE(greater_than_operator_should_return_true_if_i1_is_greater_than_i2_test2)
{
    uint8_t a[] = {1,2,3,4,5,6,7,8,9};
    bigint i1(a,9,false);
    bigint i2(a,9,false);
    BOOST_CHECK_EQUAL(i1>i2, false);
}

BOOST_AUTO_TEST_CASE(greater_than_or_equal_operator_should_return_true_if_i1_is_greater_than_or_equal_i2_test1)
{
    uint8_t a[] = {1,2,3,4,5,6,7,8,9};
    uint8_t b[] = {9,8,7};
    bigint i1(a,9,false);
    bigint i2(b,3,false);
    BOOST_CHECK_EQUAL(i1>=i2, true);
}

BOOST_AUTO_TEST_CASE(greater_than_or_equal_operator_should_return_true_if_i1_is_greater_than_or_equal_i2_test2)
{
    uint8_t a[] = {1,2,3,4,5,6,7,8,9};
    uint8_t b[] = {1,2,3,4,5,6,7,8,9};
    bigint i1(a,9,false);
    bigint i2(b,9,false);
    BOOST_CHECK_EQUAL(i1>=i2, true);
}

BOOST_AUTO_TEST_CASE(greater_than_or_equal_operator_should_return_true_if_i1_is_greater_than_or_equal_i2_test3)
{
    uint8_t a[] = {1};
    uint8_t b[] = {9,9,9,9,9,9,9,9,9};
    bigint i1(a,9,false);
    bigint i2(b,9,true);
    BOOST_CHECK_EQUAL(i1>=i2, true);
}

BOOST_AUTO_TEST_CASE(plus_equals_operator_should_add_i1_to_i2_test1)
{
    uint8_t a[] = {5,5,5,5,5};
    uint8_t b[] = {4,4,4,4,4};
    bigint i1(a,5,false);
    bigint i2(b,5,false);
    i1+=i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 9);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 5);
}

BOOST_AUTO_TEST_CASE(plus_equals_operator_should_add_i1_to_i2_test2)
{
    uint8_t a[] = {5,5,5,5,5};
    uint8_t b[] = {4,4,4,4,5};
    bigint i1(a,5,false);
    bigint i2(b,5,false);
    i1+=i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(5), 1);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 6);
}

BOOST_AUTO_TEST_CASE(plus_equals_operator_should_add_i2_to_i1_test3)
{
    uint8_t a[] = {5,5};
    uint8_t b[] = {5,5,5,5,5};
    bigint i1(a,2,false);
    bigint i2(b,5,false);
    i1+=i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 1);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 6);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 5);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 5);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 5);
}

BOOST_AUTO_TEST_CASE(plus_equals_operator_should_add_i1_to_i2_test4)
{
    uint8_t a[] = {5,5,5,5,5};
    uint8_t b[] = {0,0,0,0,1};
    bigint i1(a,5,false);
    bigint i2(b,5,false);
    i1+=i2;
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
    BOOST_CHECK_EQUAL(i1.get_digit(0), 5);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 5);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 5);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 5);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 6);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 5);
}

BOOST_AUTO_TEST_CASE(plus_equals_operator_should_add_i1_to_i2_test5)
{
    uint8_t a[] = {5,5,5,5,5};
    uint8_t b[] = {5,5,5,5,5};
    bigint i1(a,5,false);
    bigint i2(b,5,true);
    i1+=i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 0);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 1);
}

BOOST_AUTO_TEST_CASE(plus_equals_operator_should_add_i1_to_i2_test6)
{
    uint8_t a[] = {5,5,5,5,5};
    uint8_t b[] = {6,6,6,6,5};
    bigint i1(a,5,true);
    bigint i2(b,5,true);
    i1+=i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 1);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 2);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 2);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 2);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 1);
    BOOST_CHECK_EQUAL(i1.get_digit(5), 1);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 6);
    BOOST_CHECK_EQUAL(i1.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(plus_equals_operator_should_add_i1_to_i2_test7)
{
    uint8_t a[] = {5,5,5};
    uint8_t b[] = {6,6,6,6,6};
    bigint i1(a,3,true);
    bigint i2(b,5,true);
    i1+=i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 1);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 2);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 2);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 7);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 6);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 5);
    BOOST_CHECK_EQUAL(i1.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(plus_equals_operator_should_add_i1_to_i2_test8)
{
    uint8_t a[] = {9,9,9,9,9};
    uint8_t b[] = {1};
    bigint i1(a,5,false);
    bigint i2(b,1,false);
    i1+=i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(5), 1);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 6);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(plus_equals_operator_should_add_i1_to_i2_test9)
{
    uint8_t a[] = {9,9,9,9,9};
    uint8_t b[] = {1};
    bigint i1(a,5,false);
    bigint i2(b,1,true);
    i1+=i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 8);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 9);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 5);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(plus_equals_operator_should_add_i1_to_i2_test10)
{
    uint8_t a[] = {0,0,0,0,1};
    uint8_t b[] = {1};
    bigint i1(a,5,false);
    bigint i2(b,1,true);
    i1+=i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 4);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(plus_equals_operator_should_add_i1_to_i2_test11)
{
    uint8_t a[] = {1};
    uint8_t b[] = {0,0,0,0,1};
    bigint i1(a,1,false);
    bigint i2(b,5,true);
    i1+=i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 4);
    BOOST_CHECK_EQUAL(i1.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(plus_equals_operator_should_add_i1_to_i2_test12)
{
    uint8_t a[] = {1};
    uint8_t b[] = {0,0,0,0,1};
    bigint i1(a,1,true);
    bigint i2(b,5,false);
    i1+=i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 4);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(plus_equals_operator_should_add_i1_to_i2_test13)
{
    uint8_t a[] = {0,0,0,0,1};
    uint8_t b[] = {1};
    bigint i1(a,5,true);
    bigint i2(b,1,false);
    i1+=i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 4);
    BOOST_CHECK_EQUAL(i1.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(plus_equals_operator_should_double_test14)
{
    uint8_t a[] = {0,0,0,0,1};
    bigint i1(a,5,false);
    i1+=i1;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 2);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 5);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(minus_equal_operator_should_subtract_i2_to_i1_test1)
{
    uint8_t a[] = {0,0,0,0,1};
    uint8_t b[] = {1};
    bigint i1(a,5,false);
    bigint i2(b,1,false);
    i1 -= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 4);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(minus_equal_operator_should_subtract_i2_to_i1_test2)
{
    uint8_t a[] = {0,0,0,0,1};
    uint8_t b[] = {0,0,0,0,1};
    bigint i1(a,5,false);
    bigint i2(b,5,false);
    i1 -= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 0);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 1);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(minus_equal_operator_should_subtract_i2_to_i1_test3)
{
    uint8_t a[] = {1};
    uint8_t b[] = {0,0,0,0,1};
    bigint i1(a,1,false);
    bigint i2(b,5,false);
    i1 -= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 4);
    BOOST_CHECK_EQUAL(i1.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(minus_equal_operator_should_subtract_i2_to_i1_test4)
{
    uint8_t a[] = {0,0,0,0,1};
    uint8_t b[] = {0,0,0,0,1};
    bigint i1(a,5,true);
    bigint i2(b,5,true);
    i1 -= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 0);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 1);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(minus_equal_operator_should_subtract_i2_to_i1_test5)
{
    uint8_t a[] = {0,0,0,0,1};
    uint8_t b[] = {1};
    bigint i1(a,5,true);
    bigint i2(b,1,true);
    i1 -= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 4);
    BOOST_CHECK_EQUAL(i1.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(minus_equal_operator_should_subtract_i2_to_i1_test6)
{
    uint8_t a[] = {1};
    uint8_t b[] = {0,0,0,0,1};
    bigint i1(a,1,true);
    bigint i2(b,5,true);
    i1 -= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 4);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(minus_equal_operator_should_subtract_i2_to_i1_test7)
{
    uint8_t a[] = {0,0,0,0,1};
    uint8_t b[] = {0,0,0,0,1};
    bigint i1(a,5,false);
    bigint i2(b,5,true);
    i1 -= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 2);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 5);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(minus_equal_operator_should_subtract_i2_to_i1_test8)
{
    uint8_t a[] = {0,0,0,0,1};
    uint8_t b[] = {0,0,0,0,1};
    bigint i1(a,5,true);
    bigint i2(b,5,false);
    i1 -= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 2);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 5);
    BOOST_CHECK_EQUAL(i1.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(minus_equal_operator_should_subtract_i2_to_i1_test9)
{
    uint8_t a[] = {0,0,0,0,1};
    uint8_t b[] = {1};
    bigint i1(a,5,false);
    bigint i2(b,1,true);
    i1 -= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 1);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 1);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 5);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(minus_equal_operator_should_subtract_i2_to_i1_test10)
{
    uint8_t a[] = {0,0,0,0,1};
    uint8_t b[] = {1};
    bigint i1(a,5,true);
    bigint i2(b,1,false);
    i1 -= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 1);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 1);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 5);
    BOOST_CHECK_EQUAL(i1.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(minus_equal_operator_should_subtract_i2_to_i1_test11)
{
    uint8_t a[] = {1};
    uint8_t b[] = {0,0,0,0,1};
    bigint i1(a,1,true);
    bigint i2(b,5,false);
    i1 -= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 1);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 1);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 5);
    BOOST_CHECK_EQUAL(i1.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(minus_equal_operator_should_subtract_i2_to_i1_test12)
{
    uint8_t a[] = {1};
    uint8_t b[] = {0,0,0,0,1};
    bigint i1(a,1,false);
    bigint i2(b,5,true);
    i1 -= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 1);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 0);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 1);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 5);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(multiply_equal_operator_should_multiply_i1_by_i2_test1)
{
    uint8_t a[] = {0};
    uint8_t b[] = {0,0,0,0,1};
    bigint i1(a,1,false);
    bigint i2(b,5,true);
    i1 *= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 0);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 1);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(multiply_equal_operator_should_multiply_i1_by_i2_test2)
{
    uint8_t a[] = {9,9,9,9,9};
    uint8_t b[] = {0};
    bigint i1(a,5,false);
    bigint i2(b,1,false);
    i1 *= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 0);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 1);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(multiply_equal_operator_should_multiply_i1_by_i2_test3)
{
    uint8_t a[] = {1};
    uint8_t b[] = {9,8,7,6,5};
    bigint i1(a,1,false);
    bigint i2(b,5,true);
    i1 *= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 8);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 7);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 6);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 5);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 5);
    BOOST_CHECK_EQUAL(i1.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(multiply_equal_operator_should_multiply_i1_by_i2_test4)
{
    uint8_t a[] = {1,2,3,4,5};
    uint8_t b[] = {1};
    bigint i1(a,5,false);
    bigint i2(b,1,false);
    i1 *= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 1);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 2);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 3);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 4);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 5);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 5);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(multiply_equal_operator_should_multiply_i1_by_i2_test5)
{
    uint8_t a[] = {3};
    uint8_t b[] = {9};
    bigint i1(a,1,false);
    bigint i2(b,1,false);
    i1 *= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 7);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 2);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 2);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(multiply_equal_operator_should_multiply_i1_by_i2_test6)
{
    uint8_t a[] = {3,4,5,6};
    uint8_t b[] = {5,6,7,8,9};
    bigint i1(a,4,false);
    bigint i2(b,5,false);
    i1 *= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 5);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 3);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 1);
    BOOST_CHECK_EQUAL(i1.get_digit(5), 2);
    BOOST_CHECK_EQUAL(i1.get_digit(6), 6);
    BOOST_CHECK_EQUAL(i1.get_digit(7), 4);
    BOOST_CHECK_EQUAL(i1.get_digit(8), 6);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 9);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(multiply_equal_operator_should_multiply_i1_by_i2_test7)
{
    uint8_t a[] = {3,4,5,6};
    uint8_t b[] = {5,6,7,8,9};
    bigint i1(a,4,true);
    bigint i2(b,5,true);
    i1 *= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 5);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 3);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 1);
    BOOST_CHECK_EQUAL(i1.get_digit(5), 2);
    BOOST_CHECK_EQUAL(i1.get_digit(6), 6);
    BOOST_CHECK_EQUAL(i1.get_digit(7), 4);
    BOOST_CHECK_EQUAL(i1.get_digit(8), 6);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 9);
    BOOST_CHECK_EQUAL(i1.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(multiply_equal_operator_should_multiply_i1_by_i2_test8)
{
    uint8_t a[] = {3,4,5,6};
    uint8_t b[] = {5,6,7,8,9};
    bigint i1(a,4,false);
    bigint i2(b,5,true);
    i1 *= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 5);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 3);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 1);
    BOOST_CHECK_EQUAL(i1.get_digit(5), 2);
    BOOST_CHECK_EQUAL(i1.get_digit(6), 6);
    BOOST_CHECK_EQUAL(i1.get_digit(7), 4);
    BOOST_CHECK_EQUAL(i1.get_digit(8), 6);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 9);
    BOOST_CHECK_EQUAL(i1.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(multiply_equal_operator_should_multiply_i1_by_i2_test9)
{
    uint8_t a[] = {3,4,5,6};
    uint8_t b[] = {5,6,7,8,9};
    bigint i1(a,4,true);
    bigint i2(b,5,false);
    i1 *= i2;
    BOOST_CHECK_EQUAL(i1.get_digit(0), 5);
    BOOST_CHECK_EQUAL(i1.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(2), 3);
    BOOST_CHECK_EQUAL(i1.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i1.get_digit(4), 1);
    BOOST_CHECK_EQUAL(i1.get_digit(5), 2);
    BOOST_CHECK_EQUAL(i1.get_digit(6), 6);
    BOOST_CHECK_EQUAL(i1.get_digit(7), 4);
    BOOST_CHECK_EQUAL(i1.get_digit(8), 6);
    BOOST_CHECK_EQUAL(i1.get_digit_count(), 9);
    BOOST_CHECK_EQUAL(i1.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(plus_operator_should_create_new_bigint_equalling_sum_i1_and_i2_test1)
{
    uint8_t a[] = {3,4,5,6};
    uint8_t b[] = {5,6,7,8,9};
    bigint i1(a,4,false);
    bigint i2(b,5,false);
    bigint i3 = i1 + i2;
    BOOST_CHECK_EQUAL(i3.get_digit(0), 8);
    BOOST_CHECK_EQUAL(i3.get_digit(1), 0);
    BOOST_CHECK_EQUAL(i3.get_digit(2), 3);
    BOOST_CHECK_EQUAL(i3.get_digit(3), 5);
    BOOST_CHECK_EQUAL(i3.get_digit(4), 0);
    BOOST_CHECK_EQUAL(i3.get_digit(5), 1);
    BOOST_CHECK_EQUAL(i3.get_digit_count(), 6);
    BOOST_CHECK_EQUAL(i3.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(plus_operator_should_create_new_bigint_equalling_sum_i1_and_i2_test2)
{
    uint8_t a[] = {3,4,5,6};
    uint8_t b[] = {5,6,7,8,9};
    bigint i1(a,4,true);
    bigint i2(b,5,false);
    bigint i3 = i1 + i2;
    BOOST_CHECK_EQUAL(i3.get_digit(0), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(1), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(2), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(3), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(4), 9);
    BOOST_CHECK_EQUAL(i3.get_digit_count(), 5);
    BOOST_CHECK_EQUAL(i3.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(plus_operator_should_create_new_bigint_equalling_sum_i1_and_i2_test3)
{
    uint8_t a[] = {3,4,5,6};
    uint8_t b[] = {5,6,7,8,9};
    bigint i1(a,4,true);
    bigint i2(b,5,true);
    bigint i3 = i1 + i2;
    BOOST_CHECK_EQUAL(i3.get_digit(0), 8);
    BOOST_CHECK_EQUAL(i3.get_digit(1), 0);
    BOOST_CHECK_EQUAL(i3.get_digit(2), 3);
    BOOST_CHECK_EQUAL(i3.get_digit(3), 5);
    BOOST_CHECK_EQUAL(i3.get_digit(4), 0);
    BOOST_CHECK_EQUAL(i3.get_digit(5), 1);
    BOOST_CHECK_EQUAL(i3.get_digit_count(), 6);
    BOOST_CHECK_EQUAL(i3.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(plus_operator_should_create_new_bigint_equalling_sum_i1_and_i2_test4)
{
    uint8_t a[] = {3,4,5,6};
    uint8_t b[] = {5,6,7,8,9};
    bigint i1(a,4,false);
    bigint i2(b,5,true);
    bigint i3 = i1 + i2;
    BOOST_CHECK_EQUAL(i3.get_digit(0), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(1), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(2), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(3), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(4), 9);
    BOOST_CHECK_EQUAL(i3.get_digit_count(), 5);
    BOOST_CHECK_EQUAL(i3.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(minus_operator_should_create_new_bigint_equalling_sum_i1_and_i2_test1)
{
    uint8_t a[] = {3,4,5,6};
    uint8_t b[] = {5,6,7,8,9};
    bigint i1(a,4,false);
    bigint i2(b,5,false);
    bigint i3 = i1 - i2;
    BOOST_CHECK_EQUAL(i3.get_digit(0), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(1), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(2), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(3), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(4), 9);
    BOOST_CHECK_EQUAL(i3.get_digit_count(), 5);
    BOOST_CHECK_EQUAL(i3.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(minus_operator_should_create_new_bigint_equalling_sum_i1_and_i2_test2)
{
    uint8_t a[] = {3,4,5,6};
    uint8_t b[] = {5,6,7,8,9};
    bigint i1(a,4,true);
    bigint i2(b,5,false);
    bigint i3 = i1 - i2;
    BOOST_CHECK_EQUAL(i3.get_digit(0), 8);
    BOOST_CHECK_EQUAL(i3.get_digit(1), 0);
    BOOST_CHECK_EQUAL(i3.get_digit(2), 3);
    BOOST_CHECK_EQUAL(i3.get_digit(3), 5);
    BOOST_CHECK_EQUAL(i3.get_digit(4), 0);
    BOOST_CHECK_EQUAL(i3.get_digit(5), 1);
    BOOST_CHECK_EQUAL(i3.get_digit_count(), 6);
    BOOST_CHECK_EQUAL(i3.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(minus_operator_should_create_new_bigint_equalling_sum_i1_and_i2_test3)
{
    uint8_t a[] = {3,4,5,6};
    uint8_t b[] = {5,6,7,8,9};
    bigint i1(a,4,true);
    bigint i2(b,5,true);
    bigint i3 = i1 - i2;
    BOOST_CHECK_EQUAL(i3.get_digit(0), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(1), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(2), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(3), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(4), 9);
    BOOST_CHECK_EQUAL(i3.get_digit_count(), 5);
    BOOST_CHECK_EQUAL(i3.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(minus_operator_should_create_new_bigint_equalling_sum_i1_and_i2_test4)
{
    uint8_t a[] = {3,4,5,6};
    uint8_t b[] = {5,6,7,8,9};
    bigint i1(a,4,false);
    bigint i2(b,5,true);
    bigint i3 = i1 - i2;
    BOOST_CHECK_EQUAL(i3.get_digit(0), 8);
    BOOST_CHECK_EQUAL(i3.get_digit(1), 0);
    BOOST_CHECK_EQUAL(i3.get_digit(2), 3);
    BOOST_CHECK_EQUAL(i3.get_digit(3), 5);
    BOOST_CHECK_EQUAL(i3.get_digit(4), 0);
    BOOST_CHECK_EQUAL(i3.get_digit(5), 1);
    BOOST_CHECK_EQUAL(i3.get_digit_count(), 6);
    BOOST_CHECK_EQUAL(i3.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(multiply_operator_should_create_new_bigint_equalling_sum_i1_and_i2_test1)
{
    uint8_t a[] = {3,4,5,6};
    uint8_t b[] = {5,6,7,8,9};
    bigint i1(a,4,false);
    bigint i2(b,5,false);
    bigint i3 = i1 * i2;
    BOOST_CHECK_EQUAL(i3.get_digit(0), 5);
    BOOST_CHECK_EQUAL(i3.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i3.get_digit(2), 3);
    BOOST_CHECK_EQUAL(i3.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i3.get_digit(4), 1);
    BOOST_CHECK_EQUAL(i3.get_digit(5), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(6), 6);
    BOOST_CHECK_EQUAL(i3.get_digit(7), 4);
    BOOST_CHECK_EQUAL(i3.get_digit(8), 6);
    BOOST_CHECK_EQUAL(i3.get_digit_count(), 9);
    BOOST_CHECK_EQUAL(i3.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(multiply_operator_should_create_new_bigint_equalling_sum_i1_and_i2_test2)
{
    uint8_t a[] = {3,4,5,6};
    uint8_t b[] = {5,6,7,8,9};
    bigint i1(a,4,true);
    bigint i2(b,5,false);
    bigint i3 = i1 * i2;
    BOOST_CHECK_EQUAL(i3.get_digit(0), 5);
    BOOST_CHECK_EQUAL(i3.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i3.get_digit(2), 3);
    BOOST_CHECK_EQUAL(i3.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i3.get_digit(4), 1);
    BOOST_CHECK_EQUAL(i3.get_digit(5), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(6), 6);
    BOOST_CHECK_EQUAL(i3.get_digit(7), 4);
    BOOST_CHECK_EQUAL(i3.get_digit(8), 6);
    BOOST_CHECK_EQUAL(i3.get_digit_count(), 9);
    BOOST_CHECK_EQUAL(i3.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(multiply_operator_should_create_new_bigint_equalling_sum_i1_and_i2_test3)
{
    uint8_t a[] = {3,4,5,6};
    uint8_t b[] = {5,6,7,8,9};
    bigint i1(a,4,true);
    bigint i2(b,5,true);
    bigint i3 = i1 * i2;
    BOOST_CHECK_EQUAL(i3.get_digit(0), 5);
    BOOST_CHECK_EQUAL(i3.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i3.get_digit(2), 3);
    BOOST_CHECK_EQUAL(i3.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i3.get_digit(4), 1);
    BOOST_CHECK_EQUAL(i3.get_digit(5), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(6), 6);
    BOOST_CHECK_EQUAL(i3.get_digit(7), 4);
    BOOST_CHECK_EQUAL(i3.get_digit(8), 6);
    BOOST_CHECK_EQUAL(i3.get_digit_count(), 9);
    BOOST_CHECK_EQUAL(i3.is_negative(), false);
}

BOOST_AUTO_TEST_CASE(multiply_operator_should_create_new_bigint_equalling_sum_i1_and_i2_test4)
{
    uint8_t a[] = {3,4,5,6};
    uint8_t b[] = {5,6,7,8,9};
    bigint i1(a,4,false);
    bigint i2(b,5,true);
    bigint i3 = i1 * i2;
    BOOST_CHECK_EQUAL(i3.get_digit(0), 5);
    BOOST_CHECK_EQUAL(i3.get_digit(1), 9);
    BOOST_CHECK_EQUAL(i3.get_digit(2), 3);
    BOOST_CHECK_EQUAL(i3.get_digit(3), 9);
    BOOST_CHECK_EQUAL(i3.get_digit(4), 1);
    BOOST_CHECK_EQUAL(i3.get_digit(5), 2);
    BOOST_CHECK_EQUAL(i3.get_digit(6), 6);
    BOOST_CHECK_EQUAL(i3.get_digit(7), 4);
    BOOST_CHECK_EQUAL(i3.get_digit(8), 6);
    BOOST_CHECK_EQUAL(i3.get_digit_count(), 9);
    BOOST_CHECK_EQUAL(i3.is_negative(), true);
}

BOOST_AUTO_TEST_CASE(outstream_operator_returns_bigint_in_normal_form_test1)
{
    uint8_t a[] = {3,4,5,6};
    bigint i1(a,4,false);
    std::stringstream ss;
    ss << i1;
    BOOST_CHECK_EQUAL(ss.str(), "6543");
}

BOOST_AUTO_TEST_CASE(outstream_operator_returns_bigint_in_normal_form_test2)
{
    uint8_t a[] = {3,4,5,6};
    bigint i1(a,4,true);
    std::stringstream ss;
    ss << i1;
    BOOST_CHECK_EQUAL(ss.str(), "-6543");
}

BOOST_AUTO_TEST_CASE(outstream_operator_returns_bigint_in_normal_form_test3)
{
    uint8_t a[] = {3,4,5,6};
    bigint i1(a,4,true);
    bigint i2(10);
    bigint i3 = i1 * i2;
    std::stringstream ss;
    ss << i3;
    BOOST_CHECK_EQUAL(ss.str(), "-65430");
}
