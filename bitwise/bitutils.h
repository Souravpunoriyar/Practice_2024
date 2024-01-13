/*This file includes macro for multiple bitwise functionalities*/
#include<stdio.h>


#define BIT_CHECK(var, pos) ((var) & (1 << (pos)))?1:0
#define BIT_PRINT(var) \
    for(int i = 0; i < sizeof(int)*8; i++) {\
        printf("%d", BIT_CHECK((var),i)); }\
        printf("\r\n");

#define BIT_SET(var, pos) ((var) = (var) | (1 << (pos)))
#define BIT_CLEAR(var, pos) ((var) = (var) & ~(1 << (pos)))
#define BIT_FLIP(var, pos) ((var) = (var) ^ (1 << (pos)))
#define BIT_TOGGLE_RANGE(var, start, end) \
    ((var) = (var) ^ (((1 << ((end) - (start))+1)-1) << (end)))
#define BIT_SWAP_16(var) \
    ((var) = (((var) & 0x00FF) << 8) | (((var) & 0xFF00)>>8))
#define BIT_ODD_EVEN(var) \
    (((var)&1)?1:0) 
#define BIT_MAKE_EVEN(var) (var) = ((var) & ((var) - 1))
#define BIT_COUNT_SET(var, res) \
    (res) = 0; \
    while((var) != 0) {\
        res++; (var) = (var) & ((var) - 1)\
    }
#define BIT_SWAP(var, pos_i, pos_j) \
    if (BIT_CHECK((var), (pos_i)) != BIT_CHECK((var), (pos_j))) {\
        (var) = (var) ^ (1 << (pos_i)) | (var) ^ (1 << (pos_j));} 
        //(var) = ; }


#define BIT_SWAP_COM(var) \
    ((((var) & 0XAAAAAAAA) >> 1) | (((var) & (0x55555555)) << 1));

#define BIT_SWAP_2BITS(var) \
        ((((var) & 0XCCCCCCCC) >> 2) | (((var) & (0x33333333)) << 2));

#define BIT_SWAP_NIBBLE(var) \
        ((((var) & 0XF0F0F0F0) >> 4) | (((var) & (0x0F0F0F0F)) << 4));

#define BIT_SWAP_BYTE(var) \
        ((((var) & 0XFF00FF00) >> 8) | (((var) & (0x00FF00FF)) << 8));

#define BIT_SWAP_word(var) \
        ((((var) & 0XFFFF0000) >> 16) | (((var) & (0x000FFFF)) << 16));

#define BIT_REVERSE(var) \
    (var) = BIT_SWAP_COM(var);\
    (var) = BIT_SWAP_2BITS(var);\
    (var) = BIT_SWAP_NIBBLE(var);\
    (var) = BIT_SWAP_BYTE(var);\
    (var) = BIT_SWAP_NIBBLE(var);\
    (var) = BIT_SWAP_word(var)

#define BIT_ROTATE_LEFT(var, pos) (var) = (((var) << (pos)) | ((var) >> (32 -(pos))))
#define BIT_ROTATE_RIGHT(var, pos) (var) = (((var) >> (pos)) | ((var) << (32 -(pos))))
#define BIT_CLEAR_MSB2I(var, i) \
    int mask = (1<< (i));\
    mask = mask - 1;\
    (var) = (var) & mask; 

#define BIT_CLEAR_LSB2I(var, i) \
    int mask = (1 << (i));\
    mask = mask - 1;\
    (var) = (var) & ~(mask);

#define BIT_SWAP_ENDIAN(var) \
    int temp = temp | (((var) & 0x000000FF) << 24);\
    temp = temp | (((var) & 0x0000FF00) << 8);\
    temp = temp | (((var) & 0x00FF0000) >> 8);\
    temp = temp | (((var) & 0xFF000000) >> 24); \
    var = temp;

#define BIT_COUNT(var1, var2) \
    int xor_res = (var1) & (var2); int cnt = 0;\
    while(xor_res) { \
        cnt += (xor_res & 1); \
        xor_res = xor_res >> 1; \
    }     



