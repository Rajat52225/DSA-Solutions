/*
Leet Code - 875 :- Koko eating banana.
So this i approached like:-
1. Created a function which checks if the time taken by given number of banana is less or equal to the given time then returns true else false.
2. Then we do like selects total range of 1 to max amount of pile.
3. We set l=1 and r= max of pile and finds mid and check if mid satisfies the check function and set it as min.
4. If it satisfy then we search on left of it and carry on same on left and we update the min also .
5. Else we carry on right side .

Time Complexity : O(nlogm) .
Space Complexity : O(1) .

*/

class Solution {
public:
    bool checks(vector<int>& piles,int time,int h){
         long long hour=0;
         for(int i=0;i<piles.size();i++){
            hour+=(piles[i]+time-1)/time;
         }
         if(hour<=h){
            return true;
         }
         else{
            return false;
         }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r = *max_element(piles.begin(), piles.end());
        int ans=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(checks(piles,mid,h)){
                ans=min(ans,mid);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
