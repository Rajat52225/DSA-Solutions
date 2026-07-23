/*
Leet Code - 3 :- Longest substring without repeating character.
So here approach was like:-
1. Take a set.
2. Take two pointers i and j initialisw them to 0 and take an ans variable initialise to 0.
3. Now until i<size of string keep moving i and putting charcters in the set until i came on an already existing charcter also keep saving max length.
4. If s[i] is already in set then move j until s[i]==s[j] and remove s[j] from set and j++;
5. When s[j]==s[i] then remove s[j] and j++;
6. Return the answer.

Time Complexity : O(n) .
Space Complexity : O(min(n, charset)) .

*/

class Solution{
  public:
    int longestNonRepeatingSubstring(string& s){
        unordered_set<char>st;
        int i=0;
        int j=0;
        int ans=0;
        while(i<s.size()){
            if(st.find(s[i])==st.end()){
                st.insert(s[i]);
                ans=max(ans,i-j+1);
                i++;
            }
            else{
                while(s[j]!=s[i]){
                    st.erase(s[j]);
                    j++;
                }
                st.erase(s[j]);
                j++;
            }
        }
        return ans;
    }
};
