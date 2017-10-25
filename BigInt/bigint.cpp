#include "bigint.h"
#include <cstdlib>
#include <iostream>
#include <math.h>

namespace csis3700
{

///*********CONSTRUCTORS*********

// Constructor creates a bigint from 'long long' argument
bigint::bigint(long long l)
{
    size_t i = 0;
    capacity = 20;
    used = 0;

    if (l < 0)
    {
        l = l * (-1);
        negative = true;
    }
    else
    {
        negative = false;
    }

    digits = new uint8_t[capacity];

    if (l == 0)
    {
        digits[0] = 0;
        used = 1;
    }

    while (l != 0)
    {
        digits[i] = l%10;
        i++;
        l = l/10;
        used++;
    }
}

// Constructor creates bigint using array, array size, and
// a bool indicating whether the number is positive or negative
bigint::bigint(uint8_t d[], size_t ndigits, bool is_negative)
{
    negative = is_negative;
    used = ndigits;
    capacity = ndigits;

    digits = new uint8_t[capacity];

    for(size_t i=0; i<used; i++)
    {
        digits[i] = d[i];
    }

}

// Constructor to create a bigint from another bigint
// by copying arguments member variables
bigint::bigint(const bigint& other)
{
    negative = other.negative;
    used = other.used;
    capacity = other.capacity;

    digits = new uint8_t[capacity];

    for (size_t i=0; i<used; i++)
    {
        digits[i] = other.digits[i];
    }
}

// Destructor for bigint
bigint::~bigint()
{
    delete[] digits;
}

///********METHODS********

// Method returns negative of bigint passed
bigint bigint::negate() const
{
    bigint neg(digits, used, !negative);

    return neg;
}

// Method returns whether bigint is negative or not
bool bigint::is_negative() const
{
    return negative;
}

// Method returns number of digits in number passed
size_t bigint::get_digit_count() const
{
    return used;
}

// Method returns the i-th digit of this number
uint8_t bigint::get_digit(size_t i) const
{
    return digits[i];
}

// Method returns absolute value of bigint passed
bigint bigint::abs() const
{
    bigint absolute(digits, used, false);

    return absolute;
}

///********OVERLOADED OPERATORS********

///**** == ****
bool operator ==(const bigint& i1, const bigint& i2)
{
    // Check parameters of i1 and i2
    if ((i1.is_negative() != i2.is_negative()))
    {
        return false;
    }

    else if ((i1.get_digit_count() != i2.get_digit_count()))
    {
        return false;
    }

    else
    {
        for (size_t i=0; i<i1.get_digit_count(); i++)
        {
            if ((i1.get_digit(i)!=i2.get_digit(i)))
            {
                return false;
            }
        }
    }

    return true;
}

///**** !=****
bool operator !=(const bigint& i1, const bigint& i2)
{
    if ((i1 > i2) || (i1 < i2))
    {
        return true;
    }
    else
        return false;
}

///**** < ****
bool operator <(const bigint& i1, const bigint& i2)
{
    // Check parameters of i1 and i2
    if ((!i1.is_negative()) && (i2.is_negative()))
    {
        return false;
    }

    else if (i1 == i2)
    {
        return false;
    }

    else if ((i1.get_digit_count() > i2.get_digit_count()) && (!i1.is_negative()))
    {
        return false;
    }

    else if ((i1.get_digit_count() == i2.get_digit_count()) && (i1.is_negative() == i2.is_negative()))
    {
        for (size_t i=i1.get_digit_count(); i>0; i--)
        {
            if ((i1.get_digit(i-1)) > (i2.get_digit(i-1)))
            {
                return false;
            }
        }
    }
    else if ((i1.get_digit_count() < i2.get_digit_count()) && (i2.is_negative()))
    {
        return false;
    }

    return true;
}

///**** > ****
bool operator >(const bigint& i1, const bigint& i2)
{
    if ((i1 < i2) || (i1 == i2))
    {
        return false;
    }
    else
    {
        return true;
    }
}

///**** >= ****
bool operator >=(const bigint& i1, const bigint& i2)
{
    if ((i1 > i2) || (i1 == i2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

///**** <= ****
bool operator <=(const bigint& i1, const bigint& i2)
{
    if ((i1 < i2) || (i1 == i2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

///**** = ****
void bigint::operator =(const bigint& other)
{
    uint8_t *new_digits;

    if (this ==&other)
    {
        return;
    }

    if (capacity != other.capacity)
    {
        new_digits = new uint8_t[other.capacity];
        delete[] digits;
        digits = new_digits;
        capacity = other.capacity;
    }

    negative = other.negative;
    used = other.used;

    for (size_t i=0; i<other.used; i++)
    {
        digits[i] = other.digits[i];
    }
}

///**** += ****
void bigint::operator +=(const bigint& other)
{
    uint8_t* new_digits;

    size_t max_size, carry = 0;
    bool borrow = false;
    uint8_t this_digit, other_digit;

    // Find max size of new array
    if (used >= other.used)
    {
        max_size = used + 1;
    }
    else
    {
        max_size = other.used + 1;
    }
    new_digits = new uint8_t[max_size]; // Create new array

    if (((!is_negative()) && (!other.is_negative())) || ((is_negative()) && (other.is_negative()))) /// Positive + Positive ...OR... Negative + Negative
    {
        for (size_t i = 0; i < max_size; i++)
        {
            new_digits[i] = 0;
        }

        for (size_t i=0; i < max_size; i++)
        {
            this_digit = 0;
            other_digit = 0;

            if(i < used)
            {
                this_digit = digits[i];
            }
            if (i < other.used)
            {
                other_digit = other.digits[i];
            }

            if ((this_digit + other_digit + carry) >= 10)
            {
                new_digits[i] = (this_digit + other_digit + carry) % 10;
                carry = 1;
            }
            else
            {
                new_digits[i] = this_digit + other_digit + carry;
                carry = 0;
            }
        }

        if (new_digits[max_size - 1] != 0)
        {
            capacity = max_size;
        }
        else
        {
            capacity = max_size - 1;
        }
        used = capacity;

        if ((is_negative()) && (other.is_negative()))
        {
            negative = true;
        }
        else
        {
            negative = false;
        }

    }

    else if ((!is_negative()) && (other.is_negative())) /// Positive + Negative
    {
        if (abs() == other.abs()) // Case where bigints are same, but opposite sign
        {
            negative=false;
            capacity=1;
            used=1;
            digits[0] = 0;
            return;
        }

        for (size_t i = 0; i < max_size; i++)
        {
            new_digits[i] = 0;
        }

        if (abs() > other.abs()) // Positive > Negative
        {
            negative = false;

            for (size_t i=0; i < max_size; i++)
            {
                this_digit = 0;
                other_digit = 0;

                if(i < used)
                {
                    this_digit = digits[i];
                }

                if (i < other.used)
                {
                    other_digit = other.digits[i];
                }

                if (this_digit < other_digit)
                {
                    borrow = true;
                    new_digits[i] = 10 + this_digit - other_digit;
                }
                else
                {
                    borrow = false;
                    new_digits[i] = this_digit - other_digit;
                }

                if (borrow)
                {
                    size_t j = i;
                    while(digits[j+1] == 0)
                    {
                        digits[j+1] = 9;
                        j++;
                    }
                    if (digits[j+1] != 0)
                    {
                        digits[j+1] -= 1;
                    }
                }
            }

            while(new_digits[max_size-1] == 0)
            {
                max_size--;
                capacity = max_size;
            }
        }
        else if (abs() < other.abs()) // Positive < Negative
        {
            negative = true;

            for (size_t i=0; i < max_size; i++)
            {
                this_digit = 0;
                other_digit = 0;

                if(i < used)
                {
                    this_digit = digits[i];
                }

                if (i < other.used)
                {
                    other_digit = other.digits[i];
                }

                if (other_digit < this_digit)
                {
                    borrow = true;
                    new_digits[i] = 10 + other_digit - this_digit;
                }
                else
                {
                    borrow = false;
                    new_digits[i] = other_digit - this_digit;
                }

                if (borrow)
                {
                    size_t j = i;
                    while(other.digits[j+1] == 0)
                    {
                        other.digits[j+1] = 9;
                        j++;
                    }
                    if (other.digits[j+1] != 0)
                    {
                        other.digits[j+1] -= 1;
                    }
                }
            }

            while(new_digits[max_size-1] == 0)
            {
                max_size--;
                capacity = max_size;
            }
        }

        used = capacity;
    }

    else if ((is_negative()) && (!other.is_negative()))/// Negative + Positive
    {
        if (abs() == other.abs()) // Case where bigints are same, but opposite sign
        {
            negative=false;
            capacity=1;
            used=1;
            digits[0] = 0;
            return;
        }

        for (size_t i = 0; i < max_size; i++)
        {
            new_digits[i] = 0;
        }

        if (abs() > other.abs()) // Negative > Positive
        {
            negative = true;

            for (size_t i=0; i < max_size; i++)
            {
                this_digit = 0;
                other_digit = 0;

                if(i < used)
                {
                    this_digit = digits[i];
                }

                if (i < other.used)
                {
                    other_digit = other.digits[i];
                }

                if (this_digit < other_digit)
                {
                    borrow = true;
                    new_digits[i] = 10 + this_digit - other_digit;
                }
                else
                {
                    borrow = false;
                    new_digits[i] = this_digit - other_digit;
                }

                if (borrow)
                {
                    size_t j = i;
                    while(digits[j+1] == 0)
                    {
                        digits[j+1] = 9;
                        j++;
                    }
                    if (digits[j+1] != 0)
                    {
                        digits[j+1] -= 1;
                    }
                }
            }

            while(new_digits[max_size-1] == 0)
            {
                max_size--;
                capacity = max_size;
            }
        }
        else if (abs() < other.abs()) // Negative < Positive
        {
            negative = false;

            for (size_t i=0; i < max_size; i++)
            {
                this_digit = 0;
                other_digit = 0;

                if(i < used)
                {
                    this_digit = digits[i];
                }

                if (i < other.used)
                {
                    other_digit = other.digits[i];
                }

                if (other_digit < this_digit)
                {
                    borrow = true;
                    new_digits[i] = 10 + other_digit - this_digit;
                }
                else
                {
                    borrow = false;
                    new_digits[i] = other_digit - this_digit;
                }

                if (borrow)
                {
                    size_t j = i;
                    while(other.digits[j+1] == 0)
                    {
                        other.digits[j+1] = 9;
                        j++;
                    }
                    if (other.digits[j+1] != 0)
                    {
                        other.digits[j+1] -= 1;
                    }
                }
            }

            while(new_digits[max_size-1] == 0)
            {
                max_size--;
                capacity = max_size;
            }
        }

        used = capacity;
    }

    delete[] digits;
    digits = new_digits;
}

void bigint::operator -=(const bigint& other)
{
    if (((!is_negative()) && (!other.is_negative())) || ((is_negative()) && (other.is_negative())))/// Positive - Positive ...OR... Negative - Negative
    {
        if (abs() == other.abs()) // This == Other
        {
            negative=false;
            capacity=1;
            used=1;
            digits[0] = 0;
            return;
        }
        else // This < Other ... OR ... This > Other
        {
            *this += other.negate();
        }
    }
    else if (((!is_negative()) && (other.is_negative())) || ((is_negative()) && (!other.is_negative())))/// Positive - Negative ...OR... Negative - Positive
    {
        *this += other.negate();
    }
}

void bigint::operator *=(const bigint& other)
{
    uint8_t* new_digits;
    size_t max_size;

    if ((used == 1 && get_digit(0) == 0) || (other.used == 1 && other.get_digit(0) == 0)) /// Zero * Anything
    {
        negative=false;
        capacity=1;
        used=1;
        digits[0] = 0;
        return;
    }

    else if ((!is_negative() && !other.is_negative()) || (is_negative() && other.is_negative()))/// Positive * Positive ...OR... Negative * Negative
    {
        max_size = used + other.used;

        new_digits = new uint8_t[max_size];

        for (size_t i = 0; i < max_size; i++)
        {
            new_digits[i] = 0;
        }

        negative = false;
        bigint copy_digits = *this;
        bigint copy_other_digits = other.abs();

        while (copy_other_digits > 1)
        {
            *this += copy_digits;
            copy_other_digits -= 1;
        }

        for (size_t i = 0; i < max_size; i++)
        {
            new_digits[i] = digits[i];
        }

        used = max_size;
        while (new_digits[used-1] == 0) // Shave excess zeros
        {
            used--;
        }

        negative = false;
        delete[] digits;
        digits = new_digits;
    }

    else if ((!is_negative() && other.is_negative()) || (is_negative() && !other.is_negative())) /// Positive * Negative ...OR... Negative * Positive
    {
        max_size = used + other.used + 1;

        new_digits = new uint8_t[max_size];

        for (size_t i = 0; i < max_size; i++)
        {
            new_digits[i] = 0;
        }

        negative = false;
        bigint copy_digits = *this;
        bigint copy_other_digits = other.abs();


        while (copy_other_digits > 1)
        {
            *this += copy_digits;
            copy_other_digits -= 1;
        }

        for (size_t i = 0; i < max_size; i++)
        {
            new_digits[i] = digits[i];
        }

        used = max_size;
        while (new_digits[used-1] == 0) // Shave excess zeros
        {
            used--;
        }

        negative = true;
        delete[] digits;
        digits = new_digits;
    }
}

bigint operator +(const bigint& i1, const bigint& i2)
{
    bigint copy_i1(i1);
    bigint copy_i2(i2);
    copy_i1 += copy_i2;
    bigint result(copy_i1);
    return result;
}

bigint operator -(const bigint& i1, const bigint& i2)
{
    bigint copy_i1(i1);
    bigint copy_i2(i2);
    copy_i1 -= copy_i2;
    bigint result(copy_i1);
    return result;
}

bigint operator *(const bigint& i1, const bigint& i2)
{
    bigint copy_i1(i1);
    bigint copy_i2(i2);
    copy_i1 *= copy_i2;
    bigint result(copy_i1);
    return result;
}

std::ostream& operator<<(std::ostream& out, const bigint& i)
{
    if (i.is_negative())
    {
        out << "-";
    }

    for (size_t j = i.get_digit_count() - 1; j > 0; j--)
    {
        int digit = i.get_digit(j);
        out << digit;
    }
    int last = i.get_digit(0);
    out << last;

    return out;
}





}

