#include <stdio.h>



#define ARR_ELE(array) \
    sizeof((array))/sizeof((array[0]))

#define PRINT_ARR(arr, size) \
    for(int i = 0; i < (size); i++) { \
        printf("[%d] ", (arr[i]));\
    }

#define window 2

void max_val_wind(int *arr, int size) {
    int max_sum =0;
    int sum = 0;
    for(int i =0; i < window; i++){
        max_sum += arr[i]; 
    }

    sum = max_sum;
    printf("[%d] \n", sum);

    for(int i = window; i <size; i++) {
        sum = sum + arr[i] - arr[i-(window)];
        printf("[%d] ", sum);
        if(sum > max_sum) {
            //printf("[%d] ", arr[i]);
            max_sum = sum;
            
        }

    }
    printf("[%d] \r\n", max_sum);

}


int main()
{
    int dup_array[] = {1,2,3,4,2,3,1,6,1,9,6};
    max_val_wind(dup_array, ARR_ELE(dup_array));

    

    






}