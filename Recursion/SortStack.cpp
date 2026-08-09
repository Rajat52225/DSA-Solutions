/*
Sort a Stack Using Recursion

Approach

1. Remove the top element from the stack.
2. Recursively sort the remaining stack.
3. When only one element is left, consider it sorted.
4. While returning from recursion, insert each removed element
   into its correct position using the insertSorted function.
5. In insertSorted, if the stack is empty or the top element
   is smaller than or equal to the element, push it.
6. Otherwise, remove the top element temporarily and recursively
   insert the current element.
7. Push the removed element back after insertion.

Time Complexity : O(n²) .
Space Complexity : O(n) .

*/

class Solution {
public:

    void insertSorted(stack<int>& st, int x){

        if(st.empty() || st.top() <= x){
            st.push(x);
            return;
        }

        int temp=st.top();
        st.pop();

        insertSorted(st,x);

        st.push(temp);
    }

    void sortStack(stack<int>& st){

        if(st.size()<=1){
            return;
        }

        int x=st.top();
        st.pop();

        sortStack(st);

        insertSorted(st,x);
    }

    void sort(stack<int>& st){
        sortStack(st);
    }
};
