/*
Leet Code - 27 :- Remove element .
So approach was like :-
1. Initialize:
i = 0
j = n - 1
count = 0 (stores the number of removed elements)
2. Traverse while i <= j.
3. If nums[i] is not equal to val, it is already in the correct position, so simply move i forward.
4. If nums[i] is equal to val:
5. If nums[j] is also val, decrement j and increase count since this element is already at the end.
6. Otherwise, swap nums[i] and nums[j]. This moves a valid element to the front and the unwanted element to the end. Increment count, move both pointers.
7. After the traversal, the first n - count elements are the required elements. Return n - count

Time complexity : O(n) .
Space Complexity : O(1) .

*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int i = 0;
        int j = nums.size() - 1;
        int count = 0;

        while(i <= j){

            if(nums[i] != val){
                i++;
            }
            else if(nums[j] == val){
                count++;
                j--;
            }
            else{
                swap(nums[i], nums[j]);
                count++;
                i++;
                j--;
            }
        }

        return nums.size() - count;
    }
};
