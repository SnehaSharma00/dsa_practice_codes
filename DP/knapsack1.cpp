//pick, not pick problem
//2 branch recursion
// 2D dp

//recursion---------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;


int picknotpick(int idx,int W, vector<int>&w, vector<int>&v, vector<int>&dp){
    if(idx <0) return 0;
    if(W<=0) return 0;

    int notpick = picknotpick(idx-1, W, v, w);

    int pick =0; 
    if(W>=w[idx]) pick = val[idx] + picknotpick(idx-1, W-W[idx], v, w);

    return max(pick , notpick);



    dp[i] = max(rec() + , rec())
}

int main(){
    int n,W;
    cin>>n>>W;

    vector<int>w(n);
    vector<int>v(n);

    for(int i=0; i<n; i++){
        cin>>w[i];
        cin>>v[i];
    }
    vector<int>dp(n, -1);
    return picknotpick(n-1, W, w , v, dp);
}


//memoisation---------------------------------------------------------


class Solution {
  public:
  int picknotpick(int idx, int W, vector<int> &val, vector<int> &wt, vector<vector<int>>&dp){
      if(idx <0) return 0;
      if(W<=0){
          if(W ==0) dp[idx][W] = 0;
          return 0;
      }
      

      if(dp[idx][W] != -1) return dp[idx][W];


      int notpick = picknotpick(idx-1, W, val, wt, dp);
      int pick =0;
      if(W>=wt[idx]) pick = val[idx] +  picknotpick(idx-1, W-wt[idx], val,wt, dp);
      return dp[idx][W] = max(pick, notpick);
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n= val.size();
        vector<vector<int>>dp(n, vector<int>(W+1, -1));
        return picknotpick(n-1, W, val, wt, dp);
    }
};

//tabulation----------------------------------------------

int knapsack(int W, vector<int> &val, vector<int> &wt) {

    int n = val.size();

    vector<vector<int>> dp(n, vector<int>(W+1, 0));

    // Base case
    for(int j = wt[0]; j <= W; j++)
        dp[0][j] = val[0];

    for(int i = 1; i < n; i++) {

        for(int j = 0; j <= W; j++) {

            int notpick = dp[i-1][j];

            int pick = 0;
            if(wt[i] <= j)
                pick = val[i] + dp[i-1][j-wt[i]];

            dp[i][j] = max(pick, notpick);
        }
    }

    return dp[n-1][W];
}
};