#include <iostream>
#include <vector>

using namespace std;

void merge(vector<long long>& arr, int left, int mid, int right, long long &inversion) {
    int n1 = mid - left + 1;
    int n2 = right - mid;    

    vector<long long> leftArr(n1);
    vector<long long> rightArr(n2);

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left; 

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            inversion += (n1 - i); 
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

   
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<long long>& arr, int left, int right, long long &inversion) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, inversion);
        mergeSort(arr, mid + 1, right, inversion);
        merge(arr, left, mid, right, inversion);
    }
}
long long int inversionCount(long long arr[], int n) {
    vector<long long> vec(arr, arr + n);
    long long inversion = 0;
    mergeSort(vec, 0, n - 1, inversion);
    return inversion;
}
