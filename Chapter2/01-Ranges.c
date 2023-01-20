/* Exercise 2-1. Write a program to determine the ranges of char, short, int,
 * and long variables both signed and unsigned by printing the appropriate
 * values from standard headers and by direct computation. Harder if you compute
 * them: determine the ranger of the various floating-point types.*/

#include <float.h>
#include <limits.h>
#include <stdio.h>

#define UMAX      ~0
#define UMIN      0
#define UMAX_LONG ~0L
#define UMIN_LONG 0L

/* How to compute the MAX and MIN of unsigned data types:
 *
 * The minimum of an unsigned data type is always 0, we can use the ~ operator
 * to shift all bits from 0 to 1 in the binary representation.
 *
 * Example: If an int is 4 bytes, then x = 0 would be represented as:
 *
 * x = 00000000 00000000 00000000 00000000
 *
 * Then, ~x would be:
 *
 * ~x = 11111111 11111111 11111111 11111111
 *
 * This gives us the possible maximum value for an unsigned int. */

/* How to compute the MAX and MIN of signed data types:
 *
 * 1. We find the number of bits in the data type. To do this we multiply the
 * number of bytes [sizeof(type)] by the number of bits in byte [CHAR_BIT].
 *
 * 2. We the << operator to shift the binary representation of 1 by the number
 * of bits of the data type - 1, for example, int x = 1 would be represented:
 *
 * x = 00000000 00000000 00000000 00000001
 *
 * after shifting its binary representation 32-1 positions to the left we get:
 *
 * x = 1 << (sizeof(type) * CHAR_BIT - 1)
 *
 * 00000000 00000000 00000000 00000001
 * ┌─────────────────────────────────┘
 * 10000000 00000000 00000000 00000000
 *
 * This is the minimum value posible for the data type.
 *
 * 3. If we subtract 1 from this value it will cause and overflow and give us
 * the maximum possible value for the data type:
 *
 * x = (1 << (sizeof(type) * CHAR_BIT - 1)) - 1
 *
 *   10000000 00000000 00000000 00000000
 * - 00000000 00000000 00000000 00000001
 *   ───────────────────────────────────
 *   01111111 11111111 11111111 11111111
 */

int main() {
  // char
  signed char   max_signed_char   = (1 << (sizeof(char) * CHAR_BIT - 1)) - 1;
  signed char   min_signed_char   = (1 << (sizeof(char) * CHAR_BIT - 1));
  unsigned char max_unsigned_char = UMAX;
  unsigned char min_unsigned_char = UMIN;

  // printf("signed char: [%d, %d]\n", SCHAR_MIN, SCHAR_MAX);
  printf("signed char: [%d, %d]\n", min_signed_char, max_signed_char);
  // printf("unsigned char: [%u, %u]\n", UMIN, UCHAR_MAX);
  printf("unsigned char: [%u, %u]\n", min_unsigned_char, max_unsigned_char);

  // short
  signed short   max_signed_short   = (1 << (sizeof(short) * CHAR_BIT - 1)) - 1;
  signed short   min_signed_short   = (1 << (sizeof(short) * CHAR_BIT - 1));
  unsigned short max_unsigned_short = UMAX;
  unsigned short min_unsigned_short = UMIN;

  // printf("signed short: [%d, %d]\n", SHRT_MIN, SHRT_MAX);
  printf("signed short: [%d, %d]\n", min_signed_short, max_signed_short);
  // printf("unsigned short: [%u, %u]\n", UMIN, USHRT_MAX);
  printf("unsigned short: [%u, %u]\n", min_unsigned_short, max_unsigned_short);

  // int
  int          max_signed_int   = (1 << (sizeof(int) * CHAR_BIT - 1)) - 1;
  int          min_signed_int   = (1 << (sizeof(int) * CHAR_BIT - 1));
  unsigned int max_unsigned_int = UMAX;
  unsigned int min_unsigned_int = UMIN;

  // printf("signed int: [%d, %d]\n", INT_MIN, INT_MAX);
  printf("signed int: [%d, %d]\n", min_signed_int, max_signed_int);
  // printf("signed int: [%u, %u]\n", UMIN, UINT_MAX);
  printf("signed int: [%u, %u]\n", min_unsigned_int, max_unsigned_int);

  // long
  // In this case is necessary to use the long (64 bit) representation of 0
  // and 1 when shifting the bits.
  signed long   max_signed_long   = (1L << (sizeof(long) * CHAR_BIT - 1)) - 1;
  signed long   min_signed_long   = (1L << (sizeof(long) * CHAR_BIT - 1));
  unsigned long max_unsigned_long = UMAX_LONG;
  unsigned long min_unsigned_long = UMIN_LONG;

  // printf("signed long: [%ld, %ld]\n", LONG_MIN, LONG_MAX);
  printf("signed long: [%ld, %ld]\n", min_signed_long, max_signed_long);
  // printf("unsigned long: [%lu, %lu]\n", UMIN, ULONG_MAX);
  printf("unsigned long: [%lu, %lu]\n", min_unsigned_long, max_unsigned_long);

  // Precision for integer types is rather large and we need a lot of decimal
  // places to find the minimum possible value different than zero
  printf("float: [%f, %f]\n", FLT_TRUE_MIN, FLT_MAX);    //[%.45Ff, %f]
  printf("double: [%lf, %lf]\n", DBL_TRUE_MIN, DBL_MAX); // [%.324f, %f]
  printf("long double: [%Lf, %Lf]\n\n\n", LDBL_TRUE_MIN, LDBL_MAX);
  // [%.4951L, %f]

  return 0;
}
