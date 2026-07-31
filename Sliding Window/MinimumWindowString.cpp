/*
Leet Code - 76 :- Minimum Window Substring.
So approach was of sliding window here :
1. So we do like store the t string in hash map with character and frequency and take i,j,count as 0 and a minlen as int_max and start index sind as -1.
2. Then what we do is we keep checking if s[i] is in map mp and if it is then we -- its freq and if freq>= 0 after -- then we increase count++.
3. Then we check if size of t is equal to count.
4. If it is so then we do like store the min length in minlen variable and j in sind.
5. We also check if s[j] is in mp if yes then we ++ the freq and if theat no. freq >0 then we do count--.
6. Then we move our j and i.
7. At last we check if minlen is still equal to int_max then we return empty string else we return a subtr froms from sind to minlen.

Time Complexity : O(n) .
Space Complexity : O(size of t) .

*/

class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char,int>mp;
       for(char c:t){
        mp[c]++;
       }
       int i=0;
       int j=0;
       int minlen=INT_MAX;
       int sind=-1;
       int count=0;
       while(i<s.size()){
          if(mp.find(s[i])!=mp.end()){
            mp[s[i]]--;
            if(mp[s[i]]>=0){
                count++;
            }
            while(count==t.size()){
                if(i-j+1<minlen){
                    minlen=i-j+1;
                    sind=j;
                }
                if(mp.find(s[j])!=mp.end()){
                    mp[s[j]]++;
                    if(mp[s[j]]>0){
                        count--;
                    }
                }
                j++;
            }
          }
          i++;
       }
       if(minlen==INT_MAX){
        return "";
       }
       return s.substr(sind,minlen);
    }
};
