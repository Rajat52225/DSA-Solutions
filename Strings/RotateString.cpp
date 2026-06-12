/*
Problem:- Rotate String(Leetcode Problem):
Though There was an easier approach too that we could have checked that if the goal substring is present in s+s which includes
all possible rotations of s possible and that would have been very short code but the approach that clicked very first to me 
i am mentioning that :
1. First generate all the Possible Rotations.
2. Then i just checked if whether the goal string is one of the possibilities.
3. And returned true if a match was found else returned false.

Time Complexity: O(n²)
Space Complexity: O(n)

*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        bool flag = false;
        int m = s.size();

        if (s.size() != goal.size()) {
            return false;
        }

        for (int i = 0; i < m; i++) {
            string ans = "";

            for (int j = m - i - 1; j >= 0; j--) {
                ans += s[j];
            }

            for (int k = m - 1; k >= m - i; k--) {
                ans += s[k];
            }

            reverse(ans.begin(), ans.end());

            if (ans == goal) {
                flag = true;
                break;
            }
        }

        return flag;
    }
};
