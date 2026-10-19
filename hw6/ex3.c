#include <stdio.h>

int main(){
    // #pragma pack(1)
    struct {
        char a;
        int b;
        double c;
    } s;

    printf("Size of s: %d\n", sizeof(s));
    printf("%p char\n", &s.a);
    printf("%p int\n", &s.b);
    printf("%p double\n\n", &s.c);

    return 0;
}

// Without pragma
// Size of s: 16
// 0x7ffd5bd77f50 char
// 0x7ffd5bd77f54 int
// 0x7ffd5bd77f58 double

// #pragma pack(1)
// Size of s: 13
// 0x7ffc0bb4284b char
// 0x7ffc0bb4284c int
// 0x7ffc0bb42850 double

// #pragma pack(2)
// Size of s: 14
// 0x7ffe44d7777a char
// 0x7ffe44d7777c int
// 0x7ffe44d77780 double

// #pragma pack(4)
// Size of s: 16
// 0x7ffc0c629620 char
// 0x7ffc0c629624 int
// 0x7ffc0c629628 double



// #pragma pack (Default Alignment)

// char a (1 byte): 
//     Placed at offset 0
// int b (4 bytes): 
//     Requires a 4-byte boundary. 
//     The next multiple of 4 after offset 1 is offset 4
//     Offsets 1, 2, and 3 are padded with 3 padding bytes (***)
//     b occupies offsets 4–7 (iiii)
// double c (8 bytes): 
//     Requires an 8-byte boundary
//     Offset 8 is divisible by 8 (8 mod 8 = 0)
//     c occupies offsets 8–15 (dddddddd)
// Total Size: 
//     1 + 3(pad) + 4 + 8 = 16 bytes
// Byte Layout: 
//     c***iiiidddddddd


// #pragma pack(1)
// char a (1 byte): 
//     Placed at offset 0
// int b (4 bytes): 
//     Alignment is capped at min(4, 1) = 1 byte
//     Placed immediately at offset 1 with 0 padding bytes
//     Occupies offsets 1–4 (iiii)
// double c (8 bytes): 
//     Alignment is capped at min(8, 1) = 1 byte
//     Placed immediately at offset 5 with 0 padding bytes
//     Occupies offsets 5–12 (dddddddd)
// Total Size: 
//     1 + 4 + 8 = 13 bytes
// Byte Layout: 
//     ciiiidddddddd


// #pragma pack(2)
// char a (1 byte): 
//     Placed at offset 0
// int b (4 bytes): 
//     Alignment is capped at min(4, 2) = 2 bytes 
//     The next multiple of 2 after offset 1 is offset 2
//     Offset 1 is padded with 1 padding byte (*)
//     b occupies offsets 2–5 (iiii)
// double c (8 bytes): 
//     Alignment is capped at min(8, 2) = 2 bytes 
//     Offset 6 is divisible by 2 no padding is needed 
//     c occupies offsets 6–13 (dddddddd)
// Total size is 14 bytes, which is divisible by 2. No padding required
// Total Size: 
//     1 + 1(pad) + 4 + 8 = 14 bytes
// Byte Layout: 
//     c*iiiidddddddd


// #pragma pack(4)
// char a (1 byte): 
//     Placed at offset 0
// int b (4 bytes): 
//     Alignment is capped at min(4, 4) = 4 bytes 
//     The next multiple of 4 after offset 1 is offset 4
//     Offsets 1, 2, and 3 are padded with 3 padding bytes (***)
//     b occupies offsets 4–7 (iiii)
// double c (8 bytes): 
//     Alignment is capped at min(8, 4) = 4 bytes 
//     Offset 8 is divisible by 4 ($8 \pmod 4 = 0$) 
//     c occupies offsets 8–15 (dddddddd)
// Total Size: 
//     1 + 3 (pad) + 4 + 8 = 16 bytes
// Byte Layout: 
//     c***iiiidddddddd