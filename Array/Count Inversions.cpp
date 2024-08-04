#include <iostream>
#include <vector>

using namespace std;

// Merge function to merge two halves and count inversions
void merge(vector<long long>& arr, int left, int mid, int right, long long &inversion) {
    int n1 = mid - left + 1; // Length of the left half
    int n2 = right - mid;    // Length of the right half

    // Create temporary arrays
    vector<long long> leftArr(n1);
    vector<long long> rightArr(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into the original array
    int i = 0, j = 0, k = left; // Initial indexes

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            inversion += (n1 - i); // Count the inversions
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr, if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr, if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive merge sort function
void mergeSort(vector<long long>& arr, int left, int right, long long &inversion) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid, inversion);
        mergeSort(arr, mid + 1, right, inversion);

        // Merge the sorted halves
        merge(arr, left, mid, right, inversion);
    }
}

// Function to count inversions
long long int inversionCount(long long arr[], int n) {
    vector<long long> vec(arr, arr + n);
    long long inversion = 0;
    mergeSort(vec, 0, n - 1, inversion);
    return inversion;
}
