/*
Leet Code - 29 :- Divide two integers.
So approached it like since we were not allowed to use multiply and divide main tool for using is right shift thing.
1. First check edge cases if both dividend and divisor are equal .
2. Then check for sign if it will result in positive or negative answer.
3. Then we check until dividend is less than divisor and takes a count which is basically power of 2 that can be multiplied with  divisor and is less than or equal to dividend.
4. We will add the 2 raise to power count to a variable ans and at the end of both while loops we will be getting our answer.
5. Then check the overflow conditions and return ans with sign.

Time Complexity : O((logn)^2) .
Space Complexity : O(1) .

*/

class Solution {
public:
    int divide(int divi, int div) {
        if(divi==div){
            return 1;
        }
        bool sign=true;
        if(divi>=0 && div<0) sign=false;
        if(divi<0 && div>0) sign=false;
        long long n=abs((long long)divi);
        long long d=abs((long long)div);
        long long ans=0;
        while(n>=d){
            int count=0;
            while(n>=(d<<(count+1))){
                count++;
            }
            ans+=(1LL<<count);
            n=n-(d<<count);
        }
        if(ans>INT_MAX){
            return sign?INT_MAX:INT_MIN;
        }
        return sign?ans:-ans;
    }
};
