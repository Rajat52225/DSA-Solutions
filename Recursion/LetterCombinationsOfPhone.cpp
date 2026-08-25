/*
Leet Code - 17 :- Letter Combinations of a phone number .
So the used a recursive approach here :-
1. Created a map which stored number with the strings they have.
2. Then created recursive function and extracted the string associated with each number given to from combinations index wise.
3. Used the take and not take approach here .

Time Complexity : O(n × 4^n) .
Space Complexity : O(n × 4^n) .

*/

class Solution {
public:
    vector<string>ans;
    vector<string> mp = {
    "", 
    "",     
    "abc",  
    "def",  
    "ghi",  
    "jkl",  
    "mno",  
    "pqrs", 
    "tuv",  
    "wxyz"  
};
    void solve(string& digits,int index,string temp){
        if(index==digits.size()){
            ans.push_back(temp);
            return;
        }
        string letters=mp[digits[index]-'0'];
        for( char c:letters){
            temp.push_back(c);
            solve(digits,index+1,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string temp;
        solve(digits,0,temp);
        return ans;
    }
};
