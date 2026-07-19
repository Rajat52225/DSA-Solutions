/*
Leet Code - 1331 :- Rank transform of an array.
So approach was like:-
1. Copy the array to other vector and sort in increasing order.
2. Then just rank 1 to till there are unqiue elements and store number and rank in map.
3. Then just traverse the original array and replace number with rank from map.

Time Complexity : O(nlogn).
Space Complexity : O(n) .

*/

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       vector<int>v=arr;
       unordered_map<int,int>mp;
       sort(v.begin(),v.end());
       int rank=1;
       for(int i=0;i<v.size();i++){
        if(mp.find(v[i])==mp.end()){
        mp[v[i]]=rank;
        rank++;
        }
       }
       for(int i=0;i<arr.size();i++){
        arr[i]=mp[arr[i]];
       }
       return arr;
    }
};
