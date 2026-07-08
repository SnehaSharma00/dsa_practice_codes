//memoisation
class Solution {
public:
    vector<int>dp = vector<int>(31, -1);
    int fib(int n) {
        if(n==0 || n==1) return n;
        if(dp[n] != -1) return dp[n];
        else{
            return dp[n] = fib(n-1) + fib(n-2);
        }
    }
};


//tabulation

class Solution {
public:

    int fib(int n) {
        vector<int>dp(n+1);
        
        dp[0] = 0;
        if(n>=1) dp[1] = 1;

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

            return dp[n];
    }
};