/*
Leet Code - 28 :- Find the index of first occurrence in the string.
So approached it like :-
1. Used the find function to creturn the index of the substring was part of string.
2. returned -2 if not.

Time Complexity : O(mn) .
Space Complexity : O(1) .

*/

class Solution {
public:
    int strStr(string haystack, string needle) {
       int res=haystack.find(needle);
       if(haystack.find(needle)!=string::npos){
        return res;
       }
       else {
        return -1;
       }
    }
};
