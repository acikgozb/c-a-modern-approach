// Write a program that declares the `s` structure (see Section 21.4) and prints
// the sizes and offsets of `a`, `b`, and `c` members. Have the program print
// the size of the entire structure as well. From this information, determine
// wheter or not the structure has any holes. If it does, describe the location
// and size of each.

#include <stddef.h>
#include <stdio.h>

struct s {
  char a;
  int b[2];
  float c;
};

int main(void) {
  // NOTE: The sizes and offsets are shown to see the difference.
  printf("the offset of s.a is %d bytes\n", offsetof(struct s, a)); // 0
  printf("the size of s.a is %lu bytes\n", sizeof(char));           // 1

  printf("the offset of s.b is %d bytes\n", offsetof(struct s, b)); // 4
  printf("the size of s.b is %lu bytes\n", sizeof(int) * 2);        // 8

  printf("the offset of s.c is %d bytes\n", offsetof(struct s, c)); // 12
  printf("the size of s.c is %lu bytes\n", sizeof(float));          // 4

  printf("the size of s is %lu bytes\n", sizeof(struct s)); // 16

  // NOTE: Based on the values above, here is what we can say:
  //
  // TLDR: There is only one padding in this struct, which is 3 bytes and
  // between `s.a` and `s.b`.
  // Here is a naive visualization of the memory layout of this struct:
  // |------------------------- 16 b --------------------------|
  // |- 1b -||--- 3b ---||-------- 8b --------- ||---- 4 b ----|
  // | s.a  || padding  ||        s.b           ||     s.c     |
  //
  // s.a:
  //
  // 1 - For the first member of the struct, we see the offset as 0.
  // This is expected since C guarantees that the very first member
  // of a struct has the same address as the struct itself.
  // 2 - Since `s.a` is a char type, it occupies one byte.
  // 3 - However, we see that `s.a` occupies 4 bytes of memory when we see the
  // offset of the next member, `s.b`. This means that there are paddings in
  // between `s.a` and `s.b`, 3 empty bytes in particular, put by the compiler
  // to satisfy a certain memory layout.
  //
  // s.b:
  //
  // 1 - Due to the padding that exists between `s.a` and `s.b`, the second
  // field has the offset of 4, which is what `offsetof` shows us.
  // 2 - `s.b` is an array of two integers. Since the size of `int` is 4 bytes
  // on this host, we expect the compiler to allocate 8 bytes of memory for this
  // field.
  // 3 - When we check the offset of the next member, `s.c`, we see that
  // `s.c` is put right next to `s.b`. The offset of `s.c` (12) is equal to
  // offset + size of `s.b` (4 + 8). Therefore, we can safely say that the
  // compiler puts no padding between `s.b` and `s.c`.
  //
  // s.c:
  //
  // 1 - The final field of the struct has an offset of 12.
  // 2 - `s.c` is a float. The size of float is 4 bytes on this host.
  // 3 - When we check the total size of the struct (16), we can see that it is
  // equal to offset + size of `s.c` (12 + 4). Therefore, we can say that the
  // compiler puts no padding after `s.c` to satisfy a certain memory layout.

  return 0;
}
