/*
Leet Code - 1011 :- Capacity to ship packages within d days.
So this i approached like :
1. Created a check function which returns true if a particular weight capacity helps in shipping in <= d days.
2. Then i put binary search on range [max element,total sum of all] :
3. If the mid value satisfy check then we put it as min and check on left half.
4. If the mid value fails check then we check on the other right half.

Time Complexity : O(nlog(sum of elements)) .
Space Complexity : O(1) .

*/

class Solution {
public:
    bool checks(vector<int>& weights,int mid,int days){
       int count = 0;
int dayx = 1;

for(int i = 0; i < weights.size(); i++){
    if(count + weights[i] > mid){
        dayx++;
        count = weights[i];
    }
    else{
        count += weights[i];
    }
}

return dayx <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        int l=*max_element(weights.begin(),weights.end());
        int r=sum;
        int res=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(checks(weights,mid,days)){
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
