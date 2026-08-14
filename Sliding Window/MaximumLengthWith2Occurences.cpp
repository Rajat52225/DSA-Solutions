/*
Leet Code - 3090 :- Maximum Length Substring With Two Occurrences .
So the approach wa sof sliding window .
1. Just took 2 pointers at start of string and a hash map to store frequencies .
2. Did like kept pushing elements to map and kept checking if its freq>2 .
3. If frequency was >2 then started to shrink the window .
4. During this process i kept storing the maximum length that occured .
5. Returned the maximum length .

Time Complexity : O(n) .
Space Complexity : O(k) .

*/

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int ans = INT_MIN;
        while(i<s.size()){
                mp[s[i]]++;
                while(mp[s[i]]>2){
                    mp[s[j]]--;
                    if(mp[s[j]]==0){
                        mp.erase(s[j]);
                    }
                    j++;
                }
                ans=max(ans,i-j+1);
                i++;
        }
        return ans;
    }
};
