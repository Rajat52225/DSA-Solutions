/*
Problem Statement :- There is only one row of fruit trees on the farm, oriented left to right. An integer array called fruits represents the trees, where fruits[i] denotes the kind of fruit produced by the ith tree.
The goal is to gather as much fruit as possible, adhering to the owner's stringent rules:
1) There are two baskets available, and each basket can only contain one kind of fruit. The quantity of fruit each basket can contain is unlimited.
2) Start at any tree, but as you proceed to the right, select exactly one fruit from each tree, including the starting tree. One of the baskets must hold the harvested fruits.
3) Once reaching a tree with fruit that cannot fit into any basket, stop.
Return the maximum number of fruits that can be picked.

So approach was like :-
1. We use sliding window here we took a map and i and j as 0 and an ans=0.
2. Then we will iterate until i < size of array.
3. We will push the ith element in map and keep counting the frequency and moving i.
4. If the size of map gets greater than 2 then we decreasesb the frequency where j is until that element become 0 and removed form map making size of map<2=2 again.
5. We keep storing the max length for each iteration .
6. Finally just return the answer.

Time Complexity : O(n) .
Space Complexity is : O(1) .

*/

class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        unordered_map<int,int>st;
        int i=0;
        int j=0;
        int ans=0;
        while(i<fruits.size()){
                st[fruits[i]]++;
                i++;
            while(st.size()>2){
                st[fruits[j]]--;
                if(st[fruits[j]]==0){
                  st.erase(fruits[j]);
                }
                j++;
            }
            ans=max(ans,i-j);
        }
        return ans;
    }
};
