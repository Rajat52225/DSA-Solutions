/*
Leet Code - 859 :- Buddy Strings.
The approach i followed earlier was by generating all the possible strings after swapping any two positions but that exceeded the time limit.
So i had to do some changes the next approach i took was:-
1. First i checked if lengths are different then it's a straight away false.
2. Then if s string was equal to goal string then i checked if any character is having frequency > 1 i.e if its repeating then i retured true otherwise will give false.
3. Now for core logic i ran for loop once then what i do is i pushed the index which have differnent charcters in both s and goal ina vector say index.
4. Then i just checked if size of vector index is not equal to 2 because at max it was possible that at max two position will mismatch not more or less for zero we 
   covered already.
5. So we just put i and j as index[0] and index[1] and checked if at i for s and j for goal and vice verrsa are equal if yes then returned true.
It was any easy question in leetcode but took hell lot of my time though.

Time Complexity  : O(n)
Space Complexity : O(1)

*/

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        int count=0;
        unordered_map<char,int>freq;
        if(s==goal){
        for(char x:s){
            freq[x]++;
        for( char x:s){
            if(freq[x]>1){
                return true;
            }
        }
        } 
        return false;
        }
        vector<int>ind;
        for(int i=0;i<s.size();i++){
          if(s[i]!=goal[i]){
            ind.push_back(i);
          }
        }
        if(ind.size()!=2){
            return false;
        }
        int i=ind[0];
        int j=ind[1];
        return s[i]==goal[j] && s[j]==goal[i];
    }
};
