/*
LeetCode 1614 - Maximum Nesting Depth of the Parentheses
So this was an easy question :-
my approach was like:-
1. I made a counter and mx variables and initialised both to 0.
2. If bracket is opening then i incremented counter and simultaneously updated value of mx by maximum among mx and counter.
3. I decremented the value of counter if bracket was closing.
4. This easily gave me the maximum depth of the brackets.

Time Complexity: O(n)
Space Complexity: O(1)

*/

class Solution {
public:
    int maxDepth(string s) {
        int counter=0;
        int mx=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                counter++;
            }
            else if(s[i]==')'){
                counter--;
            }
            mx=max(counter,mx);
        }
        return mx;
    }
};
