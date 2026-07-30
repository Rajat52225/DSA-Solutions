/*
Leet Code - 992 :- Subarrays with k different integers.
So here approach was of sliding window .
1. We took a hash map to store integers and their frequency throughtout the window and then we took i ,j and ans as 0.
2. Then we keep putting integers in map and moving i.
3. Then we keep check for each iteration if size of map <= k if its greater than k then do like remove j such that size is <=k.
4. Keep adding the count of all valid subarrays to the ans as ans+i-j.
5. Return in the main function for <=k -<=k-1 this gives count for exact k subarrays.

Time Complexity : O(n) .
Space Complexity : O(n) .

*/

class Solution {
public:
    int goat(vector<int>& nums,int k){
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int ans=0;
        while(i<nums.size()){
            mp[nums[i]]++;
            i++;
            while(mp.size()>k){
                mp[nums[j]]--;
                if(mp[nums[j]]==0){
                    mp.erase(nums[j]);
                }
                j++;
            }
           ans+=i-j;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return goat(nums,k)-goat(nums,k-1);
    }
};
