class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4) return ans;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Avoid duplicates for the first element

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Avoid duplicates for the second element

                int l = j + 1;
                int h = n - 1;

                while (l < h) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[h];
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[h]});

                        // Skip duplicates for the third element
                        while (l < h && nums[l] == nums[l + 1]) ++l;
                        // Skip duplicates for the fourth element
                        while (l < h && nums[h] == nums[h - 1]) --h;

                        ++l;
                        --h;
                    } else if (sum < target) {
                        ++l;
                    } else {
                        --h;
                    }
                }
            }
        }

        return ans;
    }
};
