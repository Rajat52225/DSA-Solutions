/*
 LeetCode 1781 - Sum of Beauty of All Substrings.
 so question was asking to add the difference of all substrings max and min non zero frequency to get an answer.
 1. I approached it like i generated all the substrings and with help of map i saved frequency of each charcter of substring.
 2. Then what i do is i found a max frequency and min frequency of the substring .
 3. Then i simply added it to an ans variable to get the result.

 Time Complexity: O(n²)
 Space Complexity: O(1)

*/
class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
              unordered_map<char,int>freq;
            for(int j=i;j<s.size();j++){
                freq[s[j]]++;
                int maxf=INT_MIN;
                int minf=INT_MAX;
                for(auto a:freq){
                    maxf=max(maxf,a.second);
                    minf=min(minf,a.second);
                }
                ans+=maxf-minf;
            }
        }
        return ans;
    }
};
