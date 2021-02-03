#include <stdio.h> 
void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 
void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
int main() 
{ 
    int n;
    int array[100];
    printf("Enter the no of elements:");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(int i=0;i<n;i++){
      scanf("%d",&array[i]);
    }
    printf("Unsorted Array:");
    printArray(array,n);
    insertionSort(array, n);
    printf("Sorted Array:");
    printArray(array, n); 
    return 0; 
} 