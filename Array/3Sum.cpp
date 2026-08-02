/*
LeetCode 15 - 3Sum

Approach

1. Sort the array first.
2. Fix one element at a time.
3. Use two pointers (`left` and `right`) to find the remaining two elements whose sum equals the negative of the fixed element.
4. If the sum is too small, move the left pointer.
5. If the sum is too large, move the right pointer.
6. If a valid triplet is found, store it and skip duplicate values to avoid repeated triplets.
7. Continue until all possible triplets are checked.

Time Complexity : O(n²) .
Space Complexity : O(1) .

*/


class Solution {
public:
    vector<vector<int>>
 threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Skip duplicate fixed elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                }
                else if (sum > 0) {
                    right--;
                }
                else {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate left values
                    while (left < right && nums[left] == nums[left + 1])
                        left++;

                    // Skip duplicate right values
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
            }
        }

        return ans;
    }
};
