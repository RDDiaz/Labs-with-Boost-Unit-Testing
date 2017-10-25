#ifndef _BIGINT_H
#define _BIGINT_H

#include <cstdlib>
#include <iostream>

namespace csis3700
{
    typedef unsigned char uint8_t;

    class bigint
{
    public:
        bigint(long long l = 0);
        bigint(uint8_t d[], size_t ndigits, bool is_negative);
        bigint(const bigint& other);
        ~bigint();
        bigint negate() const;
        bool is_negative() const;
        size_t get_digit_count() const;
        uint8_t get_digit(size_t i) const;
        bigint abs() const;
        void operator =(const bigint& other);
        void operator +=(const bigint& other);
        void operator -=(const bigint& other);
        void operator *=(const bigint& other);
    private:
        uint8_t* digits;
        size_t capacity;
        size_t used;
        bool negative;
};

        bool operator ==(const bigint& i1, const bigint& i2);
        bool operator !=(const bigint& i1, const bigint& i2);
        bool operator <(const bigint& i1, const bigint& i2);
        bool operator >(const bigint& i1, const bigint& i2);
        bool operator >=(const bigint& i1, const bigint& i2);
        bool operator <=(const bigint& i1, const bigint& i2);
        bigint operator +(const bigint& i1, const bigint& i2);
        bigint operator -(const bigint& i1, const bigint& i2);
        bigint operator *(const bigint& i1, const bigint& i2);
        std::ostream& operator <<(std::ostream& out, const bigint& i);

}

#endif

