//https://atcoder.jp/contests/dp/tasks/dp_b

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#define fastt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;


int rec(vector<int>&stones, int i, vector<int>&dp, int k){
    if(i==0) return dp[i]=0;
    if(i==1) return dp[i] =  abs( stones[1] - stones[0]);
    if(dp[i] != -1)  return dp[i];
    int mini = INT_MAX;

    for(int j=i-1; j>=max(0, i-k);j--){
        mini = min(mini,
                 rec(stones, j, dp, k) + abs(stones[j]-stones[i]));
    }
    return dp[i] = mini;

        // return dp[i] =  min( rec(stones, i-1, dp) + abs(stones[i] - stones[i-1]) ,
        //       rec(stones, i-2, dp)+ abs(stones[i]- stones[i-2]));
}
int main() {
    // your code goes here
    fastt;
    int n, k;
    cin>>n>>k;
    vector<int>stones(n),dp(n,-1);
    for(int i=0; i<n;i++){
        cin>>stones[i];
    }
  
    cout<<rec(stones, n-1, dp, k);
    return 0;
}


//tabulation

int main() {
    // your code goes here
    fastt;
    int n, k;
    cin>>n>>k;
    vector<int>stones(n),dp(n,-1);

    
    for(int i=0; i<n;i++){
        cin>>stones[i];
    }
    
    dp[0] = 0;
    if(n>=2) dp[1] = abs(stones[1]- stones[0]);

 

    for(int i=1; i<n;i++){
         int mini = INT_MAX;
        for(int j=i-1; j>=max(0, i-k); j--){
            mini = min(mini, dp[j] + abs(stones[j]-stones[i]));
        }
        dp[i] = mini;
    }

    cout<<dp[n-1];
    return 0;
}