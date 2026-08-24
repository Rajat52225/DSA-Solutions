/*
We have to generate binary strings with no consecutive ones in them.
So approach will be like :-
1. Create a function such that it starts with an empty string .
2. We will do like we can add '0' t string any where but for '1' we will set condition as the element at back of the string should not be '1' or 
   string should be empty then only we can put '1'.
3. We keep pushing the strings when base case of n==0 is reached .
4. Finally we return the answer.

Time Complexity : O(n × F(n+2)) .
Space Complexity : O(n × F(n+2)) .

*/

class Solution {
public:
    vector<string>ans;
     void fn(string s,int n){
        if(n==0){
            ans.push_back(s);
            return;
        }
        fn(s+'0',n-1);
        if(s.size()==0 || s.back()!='1'){
            fn(s+'1',n-1);
        }
    }
    vector<string> generateBinaryStrings(int n) {
       fn("",n);
       return ans;
    }
};
