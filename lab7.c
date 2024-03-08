#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void resetArray(int original[], int sorted[], int n) {
    for (int i = 0; i < n; i++) {
        sorted[i] = original[i];
    }
}

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swaps[arr[j]]++;
                swaps[arr[j+1]]++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
            
        }
       
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
            swaps[arr[i]]++;
            swaps[arr[minIndex]]++;
        }
    }
}

void countSwaps(int arr[], int n, char *sortType) {
    int swapCount = 0;
    int valueCounts[100] = {0};
      

    

    if (sortType == "Bubble") {
        printf("Before Bubble Sort: \n");
        for(int i = 0; i < n;i++) {
        printf("%d ",arr[i]);
    }
        bubbleSort(arr, n, valueCounts);
        printf("\nAfter Bubble Sort: \n");
        for(int i = 0; i < n;i++) {
        printf("%d ",arr[i]);
    }
    } else if (sortType == "Selection") {
        printf("Before Selection Sort: \n");
        for(int i = 0; i < n;i++) {
        printf("%d ",arr[i]);
    }
        printf("\nAfter Selection Sort: \n");
        selectionSort(arr, n, valueCounts);
        for(int i = 0; i < n;i++) {
        printf("%d ",arr[i]);
    }
    } else {
        printf("Invalid sort type\n");
        return;
    }

    printf("%s Sort:\n", sortType);
    for (int i = 0; i < n; i++) {
        printf("%d: %d times swapped\n", arr[i], valueCounts[arr[i]]);
        swapCount += valueCounts[arr[i]];
        valueCounts[arr[i]] = 0; 

    }
    
    printf("Total number of swaps: %d\n", swapCount / 2);

}

int main() {
    int original1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int original2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    printf("Array 1:\n");
    countSwaps(arr1, sizeof(arr1) / sizeof(arr1[0]), "Bubble");
    resetArray(original1, arr1, sizeof(arr1) / sizeof(arr1[0]));
    printf("\n");
    countSwaps(arr1, sizeof(arr1) / sizeof(arr1[0]), "Selection");

     printf("\nArray 2:\n");
     countSwaps(arr2, sizeof(arr2) / sizeof(arr2[0]), "Bubble");
     resetArray(original2, arr2, sizeof(arr2) / sizeof(arr2[0]));
     printf("\n");
     countSwaps(arr2, sizeof(arr2) / sizeof(arr2[0]), "Selection");

    return 0;
}
