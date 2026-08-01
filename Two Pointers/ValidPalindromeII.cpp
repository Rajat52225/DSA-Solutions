/*
LeetCode 680 - Valid Palindrome II
So approach was of two pointers :
1. Use two pointers.
2. One pointer starts from the left and the other from the right.
3. If both characters are equal, move both pointers.
4. If a mismatch occurs, we have only one chance to delete a character.
5. heck both possibilities:
  * Skip the left character.
  * Skip the right character.
6. If either remaining substring is a palindrome, return `true`.
7. Otherwise, return `false`.

Time Complexity : O(n) .
Space Complexity : O(1) .

*/

class Solution {
public:
    bool palcheck(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
      int i=0;
      int j=s.size()-1;
      while(i<j){
        if(s[i]!=s[j]){
            return palcheck(s,i+1,j) || palcheck(s,i,j-1);
        }
        i++;
        j--;
      }
      return true;
    }
};
