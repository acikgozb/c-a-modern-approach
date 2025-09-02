// Design an union that makes it possible to view a 32-bit value as either a
// `float` or the structure described in Exercise 14.
// Write a program that stores 1 in the struct's sign field, 128 in the exponent
// field, and 0 in the fraction field, then prints the `float` value stored in
// the union. (The answer should be -2.0 if you've set up the bit-fields
// correctly.)

#include <endian.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

union u_float {
  float value;
  // IMPORTANT: The way the memory is allocated for this struct
  // depends completely on the compiler that is used (I'm using GCC).
  //
  // When bitfields are used in struct, the way the fields are ordered
  // in the struct is vitally important and there is no universally single way
  // to do it.
  //
  // GCC always puts the fields starting from the beginning of the memory block.
  //
  // IF the CPU architecture is little-endian, then GCC expects the ordering of
  // the bitfields to be from least-significant bit (LSB) to most-significant
  // bit (MSB).
  //
  // IF the CPU architecture is big-endian, then GCC expectds the ordering of
  // the bitfields to be from MSB to LSB.
  //
  // Therefore, the way we decide the struct ordering should be aligned with the
  // architecture that we support.
  //
  // This program current supports only Intel x86_64, which is little-endian.
  // That is the reason why the struct starts with the LSB field (fraction) and
  // ends with the MSB field (sign).
  //
  // Keep in mind that if we had more bits than we could fit in a single 32 bit
  // memory space, the way the extra bits are put in memory depends completely
  // on the compiler and we have no control over it.
  struct {
    uint32_t fraction : 23;
    uint32_t exponent : 8;
    uint32_t sign : 1;
  } float_t;
};

int main(void) {
  union u_float f;

  f.float_t.fraction = 0;
  f.float_t.exponent = 128;
  f.float_t.sign = 1;

  printf("%f", f.value);

  return 0;
}
