/*
LeetCode - 78 :- Subsets

Approach (Bit Manipulation)

1. For an array of size n, there are exactly 2^n possible subsets.
2. Each subset can be represented using a binary number (mask) from 0 to (2^n - 1).
3. Every bit in the mask corresponds to an element in the array:
   - Bit = 1 → Include the element.
   - Bit = 0 → Exclude the element.
4. For every mask, check all n bit positions using
      (mask & (1 << i))
   If the ith bit is set, include nums[i] in the current subset.
5. Store every generated subset in the answer vector.

Example:
nums = [1,2,3]

mask = 5 (101₂)

Bit 0 = 1 → Include 1
Bit 1 = 0 → Exclude 2
Bit 2 = 1 → Include 3

Subset = [1,3]

Time Complexity : O(n * 2^n)
Space Complexity : O(n) (excluding the output vector)
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> subset;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            ans.push_back(subset);
        }

        return ans;
    }
};
