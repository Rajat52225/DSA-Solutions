/*
Leet Code - 349 :- Intersection of two arrays.
Approach was like :
1. Store all elements of nums1 in an unordered_set.
2. Traverse nums2.
3. If the current element exists in the set:
4. Add it to the answer.
5. Remove it from the set to avoid duplicates.

Time Complexity : O(nxm) .
Space Complexity : O(n) .

*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       unordered_set<int>st(nums1.begin(),nums1.end());
       vector<int>ans;
       for(int i=0;i<nums2.size();i++){
        if(st.find(nums2[i])!=st.end()){
            ans.push_back(nums2[i]);
            st.erase(nums2[i]);
        }
       }
       return ans;
    }
};
