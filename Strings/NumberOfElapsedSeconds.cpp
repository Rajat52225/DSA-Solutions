/*
Leet Code - 3986 :- Number of elapsed seconds between two times.
So approach was like since we have to find answer in seconds so :
1. I took out difference in hours and minutes and seconds using subtring function of string.
2. Then i took out differences of hours mins and secs of end and start tine.
3. Then i added them up by multiplying differences of hours with 3600 and minutes with 60 and seconds as it is.

Time Complexity : O(1) .
Space Complexity : O(1) .

*/

class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int h1=stoi(startTime.substr(0,2));
        int m1=stoi(startTime.substr(3,5));
        int s1=stoi(startTime.substr(6,8));

        int h2=stoi(endTime.substr(0,2));
        int m2=stoi(endTime.substr(3,5));
        int s2=stoi(endTime.substr(6,8));

        return (h2-h1)*3600+(m2-m1)*60+(s2-s1);
    }
};
