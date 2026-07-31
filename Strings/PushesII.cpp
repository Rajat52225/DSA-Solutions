/*
LeetCode - 3016 :- Minimum Number of Pushes to Type Word II.

Approach:
1. Count the frequency of every character in the given word using a hash map.
2. Store all the frequencies in a vector since only the number of occurrences matters, not the actual characters.
3. Sort the frequencies in descending order so that the most frequent characters are assigned the minimum number of pushes.
4. Initially, every character assigned to the first 8 keys requires only 1 push.
5. After every group of 8 characters, increment the push count because the next set of characters will require one extra press.
6. Multiply each character's frequency by its assigned push count and add it to the answer.

The greedy idea is to assign the smallest push count to the most frequently occurring characters so that the total number of pushes is minimized.

Time Complexity  : O(n + k log k) .
Space Complexity : O(k) .

*/

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(int i=0;i<word.size();i++){
            mp[word[i]]++;
        }
        vector<int>freqs;
        for(auto it:mp){
            freqs.push_back(it.second);
        }
        sort(freqs.begin(),freqs.end(),greater<int>());
        int pushes=0;
        int p=1;
        for(int i=0;i<freqs.size();i++){
            pushes+=1LL*freqs[i]*p;

            if((i+1)%8==0){
              p++;
            }
        }
        return pushes;
    }
};
