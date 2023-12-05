#include <stdio.h>
#define MAX 100

int printA(int arr[]) {
    for (int i = 1; i <= arr[0]; i++) {
        printf("%3d", arr[i]);
    }
    printf("\n");
}

int findDuplicate(int arr[]) {
    for (int i=1; i < arr[0]; i++) 
        for (int j=i+1; j <= arr[0]; j++) 
            if (arr[i] == arr[j]) { return j; }
    return 0;
}

void delete(int arr[], int pos) {
    for (int i=pos; i < arr[0]; i++) arr[i] = arr[i+1]; 
    arr[0] = arr[0] - 1;                    
}

void removeDuplicate(int arr[]) {
    int pos;
    while (pos = findDuplicate(arr) )
        delete(arr, pos);
    
}

int findIndex(int arr[], int length, int target) {
    for (int i = 1; i <= length; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void intersect(int a1[], int a2[], int a3[]) {
    int count = 0;

    for (int i = 1; i <= a1[0]; i++) {
        int indexInA2 = findIndex(a2, a2[0], a1[i]);

        if (indexInA2 != -1) {
            a3[++count] = a1[i];
        }
    }

    a3[0] = count;
}

int main() {
    int arr1[] = {5, 1, 2, 1, 2, 3}; // {1,2,3}
    int arr2[] = {5, 2, 3, 4, 5, 6}; // {2,3,4,5,6}
    int arr3[MAX];

    removeDuplicate(arr1);
    removeDuplicate(arr2);

    intersect(arr1, arr2, arr3);
    printA(arr3);

    return 0;
}