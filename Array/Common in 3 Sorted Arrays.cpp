  vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
    int l1 = 0, l2 = 0, l3 = 0;
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n3 = arr3.size();
    vector<int> ans;

    while (l1 < n1 && l2 < n2 && l3 < n3) {
        if (arr1[l1] == arr2[l2] && arr1[l1] == arr3[l3]) {
            ans.push_back(arr1[l1]);

            int val = arr1[l1];
            while (l1 < n1 && arr1[l1] == val) l1++;
            while (l2 < n2 && arr2[l2] == val) l2++;
            while (l3 < n3 && arr3[l3] == val) l3++;
        } else if (arr1[l1] < arr2[l2]) {
            l1++;
        } else if (arr2[l2] < arr3[l3]) {
            l2++;
        } else {
            l3++;
        }
    }

    return ans;
}
