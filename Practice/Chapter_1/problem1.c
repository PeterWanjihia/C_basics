#include <stdio.h>

int main (){
    
    int arr[9] = {2,34,5,2,5,2,5,6,7};

    int reverseArray(int arr[],int size){
        int temp ,start = 0, end = size-1;
        while(start < end){
            temp =  arr[start];
            arr[start]= arr[end];
            start++;
            end--;
        }
        return arr;
    }

    reverseArray(arr,9);
}