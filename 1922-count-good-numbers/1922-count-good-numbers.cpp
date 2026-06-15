class Solution {
public:
    long long MOD = 1e9 + 7;

    long long power(long long a, long long b){
        if(b==0) return 1;

        long long half = power(a,b/2);
        if(b%2 == 0){
            return (half*half) % MOD;
        }
        return (a* ((half*half)%MOD))%MOD;
    }
    int countGoodNumbers(long long n) {
        if(n==0) return 1;

        long long evenPos = (n+1)/2;
        long long oddPos = n/2;

        long long evenWays = power(5,evenPos);
        long long oddWays = power(4,oddPos);

        return (evenWays * oddWays) % MOD;

    }
};