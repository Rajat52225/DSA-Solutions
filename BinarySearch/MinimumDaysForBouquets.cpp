/*
Leet Code - 1482 :- Minimum Number of days to make m bouquets.
So approach was like:-
1. Created a function which checks for a value if it will be able to give us m bouquets of k flowers.
2. And we put binary search in the range [min element to max element] as answer will be between them only.
3. Then if mid value satisfy function then we check on left side for more smaller value if possible.
4. Else we check on right side.

Time Complexity : O(nlog(maxday-minday) .
Space Complexity : O(1) .

*/

class Solution {
public:
    bool checks(vector<int>&bloomDay,int mid,int m,int k){
        int x=mid;
        bool f=false;
        int count=0;
        int ans=0;
            for(int i=0;i<bloomDay.size();i++){
                if(x>=bloomDay[i]){
                    count++;
                }
                else{
                  ans+=count/k;
                  count=0;
                }
                if(ans>=m){
                    f=true;
                }
            }

            ans+=count/k;
             if(ans>=m){
                    f=true;
                }
            if(f==true){
                return true;
            }
            else{
                return false;
            }
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL*m*k>bloomDay.size()){
            return -1;
        }
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int r=*max_element(bloomDay.begin(),bloomDay.end());
        int res=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(checks(bloomDay,mid,m,k)){
                res=min(mid,res);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
    }
};
