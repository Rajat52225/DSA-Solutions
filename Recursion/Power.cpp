/*
Leet Code - 50 :- Power(x,n) .
So  followed a recurisve approach here:-
1. Created a recurisve function with base case as if power==1 then return the x.
2. Took a variable named half and assign the recurive call to it as x,n/2 .
3. Then if power is even then do like return half*half.
4. If the power is odd then return x*half*half.
5. Inside the main function just check if the exp is negative then just make it postitve and set x as 1/x.
6. Return the recursive function for it.

Time Complexity : O(logn) .
Space Complexity : O(logn) .

*/

class Solution {
public:
    double power(double x, long long n){
        if(n == 0){
            return 1;
        }
        double half=power(x, n/2);
        if(n%2==0){
             return half*half;
        }
        else{
             return x*half*half;
        }
    }

    double myPow(double x, int n) {
        long long exp = n;

        if(exp < 0){
            exp = -exp;
            x = 1 / x;
        }
       return power(x,exp);
    }
};
