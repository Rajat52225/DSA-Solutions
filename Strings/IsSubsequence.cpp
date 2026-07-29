/*
Leet Code - 392 :- Check if Subsequence.
So approach is of two pointers.
1. Take a pointer i and j at start of both s and t.
2. Keep checking s[i]==t[j] until both i and j are less than the size of strings.
3. Keep a count also each time an element is matched.
4. At the end if count==size of s string then return true else return false.

Time Complexity : O(|t|) .
Space Complexity : O(1) .

*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        int count=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                count++;
                i++;
                j++;
            }
            else{
                j++;
            }
 
        }
        if(count==s.size()){
            return true;
        }
        return false;
    }
};
