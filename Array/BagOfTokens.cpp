/*
Leet Code - 948 :- Bag Of Tokens.
So approach was of 2 pointer:-
1. Take one pointer at 0 and one at the end of array.
2. Take a counter as 0 and do like when ith one is <= power subtract it and increase counter to +1.
3. When we have a counter then just add up the jth one and decrease counter by one.
4. Keep storing maximum value of counter and return it at the end.

Time Complexity : O(nlogn) .
Space Complexity : O(1) .

*/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0;
        int j=tokens.size()-1;
        int ans=0;
        int in=0;
        while(i<=j){
           if(power>=tokens[i]){
            power-=tokens[i];
            i++;
            in++;
           }
           else if(in>0){
            power+=tokens[j];
            j--;
            in--;
           }
           else{
            break;
           }
           ans=max(in,ans);
        }
        return ans;
    }
};
