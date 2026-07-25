/*
Leet Code - 424 :- Longest repeating character replacement.
So approach was again of sliding window.
1. Take a hash array of size 26 with all values as 0 , i and j as 0 and maxfreq and ans as 0.
2. Traverse the string until i<size.
3. Keep adding up the frequencies of characters coming and moving i.
4. Save the maxfrequency and check if length of substring - maxfreq >k if yes then reduce freq of jth andmove j until its <=k.
5. Then keep storing max ans and return it finally.

Time Complexity : O(n) .
Space Complexity : O(1) .

*/

class Solution {
public:
    int characterReplacement(string s, int k) {
      unordered_map<char,int>mp;
      int i=0;
      int j=0;
      int maxfreq=0;
      int ans=0;
      int hash[26]={0};
      while(i<s.size()){
          hash[s[i]-'A']++;
          i++;
          maxfreq=*max_element(hash,hash+26);
          while((i-j-maxfreq)>k){
            hash[s[j]-'A']--;
            j++;
          }
          ans=max(ans,i-j);
      }
      return ans;
    }
};
