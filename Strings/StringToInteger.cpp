/*
LeetCode 8 - String to Integer (atoi)
In this we were given the algorihtm so just followed that.

Time Complexity: O(n)
Space Complexity: O(1)

*/
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;

        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        int sign = 1;

        if (i < s.size() && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < s.size() && s[i] == '+') {
            i++;
        }

        long long num = 0;

        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (num > INT_MAX / 10 ||
                (num == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return sign * num;
    }
};
