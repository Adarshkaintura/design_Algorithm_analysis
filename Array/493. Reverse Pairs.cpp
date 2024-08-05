class Solution {
public:
// Function to merge two halves of a vector
void merge(std::vector<int>& arr, int left, int mid, int right,int &ans) {
    int n1 = mid - left + 1; // Length of left half
    int n2 = right - mid;    // Length of right half

    // Temporary vectors for left and right halves
    std::vector<int> leftArr(n1), rightArr(n2);

    // Copy data to temporary vectors
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

       int rt=0;
       
    for(int i=0;i<n1;i++){
        
       while(rt<n2 && leftArr[i]>(long long)2*rightArr[rt]){
         rt++;
       }
       ans += rt;
    }

    // Merge the temporary vectors back into the main vector
    int i = 0, j = 0, k = left; // Initial indices of left, right, and merged subarrays

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of leftArr, if there are any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy any remaining elements of rightArr, if there are any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergeSort(std::vector<int>& arr, int left, int right,int &ans) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle point

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid,ans);
        mergeSort(arr, mid + 1, right,ans);

        // Merge the sorted halves
        merge(arr, left, mid, right,ans);
    }
}
    int reversePairs(vector<int>& nums) {
        int ans=0;
        mergeSort(nums,0,nums.size()-1,ans);
        return ans;
    }
};
