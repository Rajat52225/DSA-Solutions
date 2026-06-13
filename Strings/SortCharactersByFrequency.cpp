/*
 LeetCode 451 - Sort Characters By Frequency
 so this problem asked to return the string in such a way that the characters are arranged in such an order that the character
 with highest frequency comes first and followed by lower ones.
 so i followed the approach like:-
 1. Created an unordered map which stored the charcter and freqeuncies as key value pairs.
 2. Then i converted it to a vector as i had to sort on basis of frequency and in a map we can sort only on the basis of keys.
 3. Then after sorting i simply appended the charcter the number of frequency it had in an empty string res.
 4. And finally i returned the res.
 
 Time Complexity: O(n + k log k)
 Space Complexity: O(k)

*/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(char x:s){
            freq[x]++;
        }
        string res="";
        vector<pair<char, int>> v(freq.begin(), freq.end());

      sort(v.begin(), v.end(), [](auto &a, auto &b) {
       return a.second > b.second;  // decreasing frequency
        });
       for (auto &[ch, count] : v) {
           res.append(count, ch);
            }
         return res;
    }
};
