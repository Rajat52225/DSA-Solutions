/*
LeetCode 13 - Roman to Integer.
So this was also an easy question.
I approached it like:-
1. Created an unordered map and stored roman symbol and integer value as key value pairs in it.
2. Then I used reverse loop like i traversed the roman number from right to left.
3. What i did was i created a prev and ans variable and initialised both to zero.
4. I initialised a variable curr as last loop element and if curr was < prev then i added curr to ans otherwise substracted it.
5. And set prev to curr and return the answer at last.

Time Complexity: O(n)
Space Complexity: O(1)

*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp={
       {'I', 1},
       {'V', 5},
       {'X', 10},
       {'L', 50},
       {'C', 100},
       {'D', 500},
       {'M', 1000}
       };
      int ans=0;
      int prev=0;
      for(int i=s.size()-1;i>=0;i--){
        int curr=mp[s[i]];
        if(curr<prev){
            ans-=curr;
        }
        else{
            ans+=curr;
        }
        prev=curr;
      }
      return ans;
    }
};
