/*
So I solvef this leetcode problem which is to check if two strings are anagram or not.
the approach i followed is :-
1. I created unordered maps and stored the character and frequency of each string in its map.
2. Then what i did was i checked the equality of maps if both.
3. if they are equal then it returned true and if they didn't hold equality then it returned false.

Time Complexity: O(n)
Space Complexity: O(k)

*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
     unordered_map<char,int>freq1;
     unordered_map<char,int>freq2;
     for(char x:s){
        freq1[x]++;
     }
     for(char y:t){
        freq2[y]++;
     }
     if(freq1==freq2){
        return true;
     }
     return false;
    }
};
