/*
Leet Code - 204 :- Count prime numbers.
So for this i used sieve eratosthenes algorithm .

Time Complexity : O(nlogn logn) .
Space Complexity : O(n) .

*/

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }
        vector<bool>isprime(n,true);
        isprime[0]=false;
        isprime[1]=false;
        for(int i=2;i<n;i++){
            if(isprime[i]){
                for(int j=i*i;j<n;j+=i){
                    isprime[j]=false;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(isprime[i]){
                count++;
            }
        }
        return count;
    }
};
