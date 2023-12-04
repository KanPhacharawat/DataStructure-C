#include <stdio.h>

#define MAX 100

void Union(int a1[], int a2[], int a3[]){
    int i;
    for(i = 1; i <= a1[0]; i++){
        a3[i] = a1[i];
    }
    for(int j = 1; j <= a2[0]; j++){
        a3[i+j-1] = a2[j];
    }

    a3[0] = a1[0] + a2[0];
}

void printArr(int arr[]){
    for(int i = 1; i <= arr[0]; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void removeDuplicate(int arr[]) {
    int n = arr[0];

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;
                j--;
            }
        }
    }

    arr[0] = n;
}

int main(void){
    int arr1[] = {5,1, 2, 1, 2, 3};
    int arr2[] = {5,2, 3, 4, 5, 6};
    int arr3[MAX];

    removeDuplicate(arr1);
    removeDuplicate(arr2);
    Union(arr1, arr2, arr3);
    removeDuplicate(arr3);
    printArr(arr3);
}