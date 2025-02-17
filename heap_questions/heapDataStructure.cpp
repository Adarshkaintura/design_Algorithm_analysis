#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Min Heapify Function (Used for building heap)
void heapify(vector<int>& arr, int n, int ind) {
    int mini = ind;
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;

    if (left < n && arr[left] < arr[mini]) {
        mini = left;
    }
    if (right < n && arr[right] < arr[mini]) {
        mini = right;
    }
    if (mini != ind) {
        swap(arr[mini], arr[ind]); 
        heapify(arr, n, mini);
    }
}

// Insert function (Bubble Up approach)
void insert(vector<int>& arr, int val) {
    arr.push_back(val);  
    int i = arr.size() - 1; 

    // Percolate up
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (arr[parent] > arr[i]) {  
            swap(arr[parent], arr[i]);
            i = parent;  
        } else {
            break;  
        }
    }
}
// extract in heap;
int extract(vector<int>& arr) {
    if (arr.empty()) return -1;  // Handle edge case of empty heap
    
    int ans = arr[0];  // Store root element
    int n = arr.size();
    
    swap(arr[0], arr[n - 1]);  // Swap root with the last element
    arr.pop_back();  // Remove last element (which was the original root)
    
    heapify(arr, n - 1, 0);  // Call heapify on reduced heap

    return ans;  // Return extracted min element
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
   
    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Build Min Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Output the Min Heap
    cout << "The Min Heap is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Insert a new element
    cout << "Enter the element to insert in heap: ";
    int val;
    cin >> val;
    insert(arr, val);

    // Output after insertion
    cout << "After inserting, the Min Heap is: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
 
     
    cout<<"after extracting one element:"<<extract(arr)<<endl;
    cout<<"the new heap is :";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
