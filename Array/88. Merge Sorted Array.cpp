class Solution {
public:
    void swapGreater(vector<int>& nums1, int i1, int i2) {
        if (nums1[i1] > nums1[i2]) {
            swap(nums1[i1], nums1[i2]);
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }

        // Copy elements from nums2 into nums1
        int l = 0;
        for (int i = m; i < m + n; i++) {
            nums1[i] = nums2[l++];
        }

        int len = m + n;
        int gap = (len / 2) + (len % 2);

        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < len) {
                swapGreater(nums1, left, right);
                left++;
                right++;
            }

            if (gap == 1) {
                break;
            }
            gap = (gap / 2) + (gap % 2);
        }
    }
};
