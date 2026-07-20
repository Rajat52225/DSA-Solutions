/*
Leet Code - 693 :- Binary Number with alternating bits.
So my approach was like:-
1. Store the binary form of number in a string.
2. Just use xor on adjacent elements of binary number .
3. If any of them gives 0 then return false else return true.

Time Complexity : O(logn) .
Space Complexity : O(logn) .

*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s="";
        int num=n;
        while(num>=2){
           s+=num%2;
           num/=2;
        }
        s+=num;
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size()-1;i++){
            if((s[i]^s[i+1])==0){
               return false;
            }
        }
        return true;
    }
};
