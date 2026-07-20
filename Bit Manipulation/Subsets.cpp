/*
LeetCode - 78 :- Subsets .
Approach was like :-
1. First find and store the number of subsets in a variable by 1<<size of array.
2. Then traverse through the subsets and also inside it traverse the array for each subset to check for which array element the bit is set.
3. Then if the bit is set then push the number in a list .
4. Further push the list in the another list of lists.

Time Complexity : O(n · 2ⁿ) .
Space Complexity : O(n · 2ⁿ) .

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       int subsets=1<<nums.size();
       vector<vector<int>>ans;
       for(int i=0;i<subsets;i++){
         vector<int>lt;
        for(int j=0;j<nums.size();j++){
            if(i&(1<<j)){
                lt.push_back(nums[j]);
            }
        }
        ans.push_back(lt);
       }
       return ans;
    }
};
