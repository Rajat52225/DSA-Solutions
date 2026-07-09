/*
Leet Code - 774 :- Minimize max distance gas station .
Approach is like:-
1. We create a check function which checks for a mid value that what whether it will be possible to have it as a equal gap between each station such that k stations are added more.
2. Range will be like [0 ,maximum gap].
3. So if mid value staisfies check then we make r=mid as we need more min value if possible.
4. Else we go for right side.

Time Complexity : O(nlog(d/e) .
Space Complexity : O(1) .

*/

class Solution {
public: 
    bool check(vector<int>& arr,double mid,int k){
        int count=0;
        for(int i=0;i<arr.size()-1;i++){
            double gap=arr[i+1]-arr[i];
            count+=ceil(gap/mid)-1;
        }
      return count<=k;
    }
    long double minimiseMaxDistance(vector<int> &arr, int k) {
       double l=0.0;
       double r=0.0;
       for(int i=0;i<arr.size()-1;i++){
        r=max(r,(double)(arr[i+1]-arr[i]));
       }
       while(r-l>1e-6){
        double mid=l+(r-l)/2.0;
        if(check(arr,mid,k)){
             r=mid;
        }
        else{
            l=mid;
        }
       }
       return r;
    }
};
