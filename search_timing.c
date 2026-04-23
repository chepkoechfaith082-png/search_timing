/*
Project: Search Algorithms Time Analysis

Group Members:
1. Faith Chepkoech - SCT221-0460/2024
2. Margaret Keru - SCT221-0279/2024

Description:
This program implements Linear Search, Binary Search, and Hashing.
It measures execution time using:
T1 = start time
T2 = end time
Time taken = T2 - T1
*/
#include <stdio.h>
#include <time.h>

#define SIZE 100

int linearSearch(int arr[], int n, int key) {
	int i;
    for(i = 0; i < n; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void sort(int arr[], int n) {
	int i,j;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

int main() {
    int arr[SIZE], n, key, choice;
    clock_t T1, T2;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &key);

    printf("\nMENU\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("3. Hashing\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            T1 = clock(); // start time
            linearSearch(arr, n, key);
            T2 = clock(); // end time
            break;

        case 2:
            sort(arr, n); // must sort first
            T1 = clock();
            binarySearch(arr, n, key);
            T2 = clock();
            break;

        case 3:
            T1 = clock();
            hashFunction(key);
            T2 = clock();
            break;

        default:
            printf("Invalid choice\n");
            return 0;
    }

    time_taken = (double)(T2 - T1) / CLOCKS_PER_SEC;

    printf("Time1 (Start): %ld\n", T1);
    printf("Time2 (End): %ld\n", T2);
    printf("Time Taken (T2 - T1): %f seconds\n", time_taken);

    return 0;
}
