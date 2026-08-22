/*
In this problem we have to reverse a stack .
So Approach was like :-
1. Create a sort function which do like keeps remoeving elements until stack size is <=1.
2. We go to the insert function which do like put remove the element in stack make it empty an pushes x in the top then we put all removed element back .
3. Due to these two insert and reverse functions we are easily able to reverse the stack.

Time Complexity : O(n2) .
Space Complexity : O(n) .

*/

class Solution {
public:
    void insertStack(stack<int>& st,int x){
        if(st.empty()){
            st.push(x);
            return;
        }

        int temp=st.top();
        st.pop();
        
        insertStack(st,x);
        st.push(temp);
    }
    
    void reverseStack(stack<int> &st) {
       if(st.size()<=1){
        return;
       }
       int x=st.top();
       st.pop();
       reverseStack(st);

       insertStack(st,x);
    }
};
