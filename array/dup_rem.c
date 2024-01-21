#include <stdio.h>

void brute_rem(int *arr, int size) {
    for(int i =0; i< size; i++) {
        for(int j=i+1; j < size ;j++) {
            if(arr[i] == arr[j]) {
                printf("q [%d]", arr[i]);
                /*Got Duplicate*/
                for(int k = j; k<size; k++) {
                    arr[k] = arr[k+1];
                }
                j--;
                size--;
            }

        }

    }

}


#define ARR_ELE(array) \
    sizeof((array))/sizeof((array[0]))

#define PRINT_ARR(arr, size) \
    for(int i = 0; i < (size); i++) { \
        printf("[%d] ", (arr[i]));\
    }

int hashmap[20];
void use_hashmap(int *arr, int size) {
    for(int i = 0; i < size; i++) {

        hashmap[arr[i]]++;
    }

    for(int i =0; i< size; i++){
        arr[i] = 0xFF;
    }

    for(int i =0; i < size; i++) {
       if(hashmap[i]==1) {
           *arr = i;
            arr++; 
            printf("[%d] \r\n", *(arr-1) );      
        }
    }

   

}



int main()
{
    int dup_array[] = {1,2,3,4,2,3,5,6,1,4,6,7,8,0};
    //printf("ele [%d] \r\n", ARR_ELE(dup_array));
    use_hashmap(dup_array,ARR_ELE(dup_array));
    printf("\n");
    PRINT_ARR(dup_array, 11);
    






}