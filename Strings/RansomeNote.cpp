/*
Leet Code - 383 :- Ransome Note.
So here we had to find if its possibe to make a string1 from string 2 characters and each character can be used once only.
So approached like :
1. I created a vector which stored the char and its frequency in a vector.
2. Then we checked if the character in string 1 is having enough frequency in string 2 .
3. If any freuency is zero while checking then return false else return true.

Time Complexity : O(n) .
Space Complexity : O(1) .

*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size()>magazine.size()){
            return false;
        }
      vector<int> freq(26, 0);

for(char ch : magazine) {
    freq[ch - 'a']++;
}

for(char ch : ransomNote) {
    if(freq[ch - 'a'] == 0) {
        return false;
    }

    freq[ch - 'a']--;
}

return true;
    }
};
