/*
Leet Code - 22 :- Generate Parenthesis.
So approach was of recursion :-
1. Use recursion to build the string one character at a time.
2. Keep track of:
3. open → number of ( used
4. close → number of ) used
5. We can add ( only when open < n.
6. We can add ) only when close < open.
7. This ensures we never have more closing brackets than opening brackets.
8. When open == n and close == n, we have formed a valid combination, so add it to the answer.

Time Complexity : O(Cₙ × n) .
Space Complexity : O(Cₙ × n) .

*/

class Solution {
public:
    vector<string>ans;
    void solve(int n,string s,int open,int close){
        if(n==open && n==close){
            ans.push_back(s);
            return;
        }
        if(open<n){
            solve(n,s+'(',open+1,close);
        }
        if(close<open){
            solve(n,s+')',open,close+1);
        }

    }
    vector<string> generateParenthesis(int n) {
        solve(n,"",0,0);
        return ans;
    }
};
