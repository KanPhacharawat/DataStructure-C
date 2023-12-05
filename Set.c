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
    for (int i=pos; i < arr[0]; i++) arr[i] = arr[i+1]; // shift from current position until the rest.
    arr[0] = arr[0] - 1;                                // update the array size
}

void removeDuplicate(int arr[]) {
    int pos;
    while (pos = findDuplicate(arr) )   // If there exists a duplicate, then return the position. 
        delete(arr, pos);               // delete current position's element and shift the rest.
    
}

void Union(int a1[], int a2[], int a3[]) {
    int i;
    for (i = 1; i <= a1[0]; i++) {
        a3[i] = a1[i];
    }
    for (int j = 1; j <= a2[0]; j++) {
        a3[i+j-1] = a2[j];
    }
    a3[0] = a1[0] + a2[0];
}

int findIndex(int arr[], int length, int target) {
    for (int i = 1; i <= length; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void intersect(int a1[], int a2[], int a3[]){
    int count = 0;

    for (int i = 1; i <= a1[0]; i++) {
        int indexInA2 = findIndex(a2, a2[0], a1[i]);

        if (indexInA2 != -1) {
            a3[++count] = a1[i];
        }
    }

    a3[0] = count;
}

void difference(int a1[], int a2[], int a3[]) {
    int temp[MAX] = {};
    temp[0] = 0;

    int count = 0;

    intersect(a1, a2, temp);
    removeDuplicate(temp);

    for (int i = 1; i <= a1[0]; i++) {
        int indexInTemp = findIndex(temp, temp[0], a1[i]);

        if (indexInTemp == -1) {
            a3[++count] = a1[i];
        }
    }

    a3[0] = count;
}

void main() {
    int arr1[] = {5, 1, 2, 1, 2, 3}; // {1,2,3}
    int arr2[] = {5, 2, 3, 4, 5, 6}; // {2,3,4,5,6}
    int arr3[MAX], arr4[MAX], arr5[MAX];

    Union(arr1, arr2, arr3); // {1,2,3} && {2,3,4,5,6} --> {1,2,3,4,5,6}
    removeDuplicate(arr3);
    printA(arr3);

    intersect(arr1, arr2, arr4); // {1,2,3} && {2,3,4,5,6} --> {2,3}
    removeDuplicate(arr4);
    printA(arr4);

    difference(arr1,arr2,arr5); // {1,2,3} && {2,3,4,5,6} --> {1}
    removeDuplicate(arr5);
    printA(arr5);

}