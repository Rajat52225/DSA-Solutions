/*
Leet Code - 1423 :- Maximum Points You Can Obtain from Cards .
So Approach will be of 2 pointers.
1. Take the sum of k elements from left side .
2. Initialise i and j as i at k-1 position and j at end of array.
3. Then we keep removing one element from last of k selected from sum and add one from last and do until k becomes zero in while loop.
4. Keep reducing i and j and k until k is 0.
5. Keep storing max sum in a variable named ans and finally return answer.

Time Complexity : O(k) .
Space Complexity : O(1) .

*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i=k-1;
        int j=cardPoints.size()-1;
        int sum=0;
        for(int z=0;z<k;z++){
            sum+=cardPoints[z];
        }
        int ans=sum;
        while(k){
              sum-=cardPoints[i];
              sum=sum+cardPoints[j];
              i--;
              j--;
              k--;
              ans=max(ans,sum);
        }
        return ans;
    }
};
