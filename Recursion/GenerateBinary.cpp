/*
Generate Binary Strings Without Consecutive 1s .
So used recusrive approach here .
1. Start with an empty string and build the binary string one character at a time using recursion.
2. At every position, we have two choices:
Add 0 — always allowed.
Add 1 — allowed only when the previous character is not 1.
3. Decrease n by 1 after adding a character.
4. When n == 0, the string has reached length n, so add it to the answer.
5. Since we always explore 0 before 1, the generated strings are automatically in lexicographical order.

Time Complexity : O(2ⁿ × n) .
Space Complexity : O(2ⁿ × n) .

*/

class Solution {
public:
     vector<string>ans;
    void solve(int n,string s){
        if(n==0){
            ans.push_back(s);
            return;
        }
        solve(n-1,s+"0");
        if(s.empty() || s.back()!='1'){
            solve(n-1,s+"1");
        }
    }
   
    vector<string> generateBinaryStrings(int n) {
        solve(n,"");
        return ans;
    }
};
