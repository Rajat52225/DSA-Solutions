/*
We have to do Palindrome Partitioning .
So Approach was of recursion :-
1. We created a palindrome check function.
2. Then the main func did what is start making partitions from start and check if index to i the substr is palindrome and if yes then push in ans vector.
3. Then we simply apply that take not take strategy .
4. Finally returned the ans.

Time Complexity : O(n² · 2ⁿ) .
Space Complexity : O(n · 2ⁿ) .

*/

class Solution {
public:
    bool ispal(string& s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void func(string& s,int index,vector<string> temp,vector<vector<string>>& ans){
        if(index==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(ispal(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                func(s,i+1,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string> > partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        func(s,0,temp,ans);
        return ans;
    }
};
