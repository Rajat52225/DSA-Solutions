/*
LeetCode 5 - Longest Palindromic Substring.
So in this question we were asked to find the longest substring which is palindrome.
So here approach was like:-
1. I created a function which check if a string entered is boolean or not used two pointer approach in it.
2. Then i simply checked each subtring using this function and i also used a res variable and if its size is less than the 
substring then we updated res as that subtring.
3. This is how we solved this one.

 Time Complexity: O(n³)
 Space Complexity: O(1)

*/
class Solution {
public:
bool isPalindrome(string &s,int l,int r){
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
    string longestPalindrome(string s) {
        string res="";
        for(int i=0;i<s.size();i++){
            string curr="";
            for(int j=i;j<s.size();j++){
            curr+=s[j];
           if (isPalindrome(s, i, j)) {
    if (j - i + 1 > res.size()) {
        res = s.substr(i, j - i + 1);
    }
}
            }
        }
        return res;
    }
};
