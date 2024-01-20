#include<stdio.h>


void two_sum_bin(int *a, int len, int target) {
    int end  = len;
    int start = 0;
    int mid = 0;
    while(end >= start) {
        if(a[start] + a[end] == target){
            printf("[%d] = [%d] + [%d] \r\n", target, a[start], a[end]);
            break;
        }
        mid = (start + end )/2;
        if(target == a[mid] + a[end]){
            printf("[%d] = [%d] + [%d] \r\n", target, a[mid], a[end]);
            break;
        }
        if(target < a[mid] + a[end]) {
            printf("in lower half [%d] [%d]\r\n", mid, end);
            end = mid;
        } else {
            printf("in upper half [%d] [%d]\r\n", mid, end);
            sleep(1);
            start = mid;
        }

    }

}


void brute_f(int a[], int len, int target) {
    for(int i = 0; i< len; i++) {
        for(int j = i; j < len; j++) {
            if(a[i] + a[j] == target) {
                printf("[%d] + [%d] = [%d] \r\n", a[i], a[j], target);
            }
        }

    }
}


void opt_f(int a[], int len, int target) {
    for(int i = 0, j = (len -1); i< len, j>=0; ) {
            if(a[i] == target) {
                printf("[%d]  = [%d] \r\n", a[i], target);
                break;
            }else if(a[j] == target) {
                printf("[%d]  = [%d] \r\n", a[i], target);
                break;                
            }else if(a[i] + a[j] == target) {
                printf("[%d] + [%d] = [%d] \r\n", a[i], a[j], target);
                break;
           } else if(a[i] + a[j] > target) {
            j--;
           }else{
            i++;
           }
        

    }

}



int main() {
    int arr[]={2,7,8,11,13};
    int target = 13; 
    int len = 5;
    //two_sum_bin(arr, len, target);/*1target 8;doesnot work for 18, because 11 and 7 are in different halves*/
    //brute_f(arr, len, target);
    opt_f(arr, len, target);


}