#include "bitutils.h"
#define INT_SIZE sizeof(int)*8

int rev_bit(int num) {
    int temp = 0;
    
    for(int i = 0; i < INT_SIZE; i++) {
        if(num & (1 << i)) {
            temp = temp | (1 << ((INT_SIZE-1)-i));
        }
    }
    return temp;
}


int main() {
    int num = 0;
    int pos = 0;
    
    printf("enter a number : ");
    scanf("%d", &num);
    printf("enter a position : ");
    scanf("%d", &pos);

     printf("[%d] represent ", num);
     BIT_PRINT(num);
     BIT_CLEAR(num,pos);
     BIT_PRINT(num);
     BIT_SET(num,pos);
     BIT_PRINT(num);
     BIT_FLIP(num, pos);
     BIT_PRINT(num);

    // BIT_TOGGLE_RANGE(num, 1,4);
    // BIT_PRINT(num);
     //BIT_SWAP_16(num);
     BIT_PRINT(num);
     (BIT_ODD_EVEN(num)==1)?printf("ODD number \r\n"):printf("EVEN NUMBER \r\n");
     BIT_SWAP(num, 0,3);
     BIT_PRINT(num);
     //num = rev_bit(num);
     //BIT_PRINT(num);
     BIT_REVERSE(num);
     BIT_PRINT(num);
     




}