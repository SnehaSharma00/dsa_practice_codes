/*Frog Jump - 1
Difficulty: MEDIUM | Max Score: 50
There are N stones, numbered 1, 2,.....,N. For each i (1 <= i <= N), the height of Stone i is hi.



There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:



If the frog is currently on Stone i, jump to Stone i + 1 or Stone i + 2. Here, a cost of |hi - hj| is incurred, where j is the stone to land on.


Find the minimum possible total cost incurred before the frog reaches Stone N.



Input Format: 

Input is given from Standard Input in the following format:



N

h1 h2 ... hN



Output Format:

Print the minimum possible total cost incurred.

​.

 

Example 1:

Input: 
4
10 30 40 20
Output: 30
Explanation: If we follow the path 1 → 2 → 4, the total cost incurred would be ∣10−30∣ + ∣30−20∣ = 30.


Example 2:

Input:
2
10 10
Output: 0
Explanation: If we follow the path 1 → 2, the total cost incurred would be ∣10−10∣ = 0.
 

Constraints:

All values in input are integers.
2 <= N <= 105*/


// MEMOISATION---------------------------------------------------------------
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#define fastt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
// rec(vector<int>&stones, int n, int i, int min){ 
//     if(i==n){

//     }
//     if(stones[i+1] < stones[i+2]) {
//         rec(stones, n, i+1);
//         min += 
//     }
//     else rec(stones, n, i+2);

// }

int rec(vector<int>&stones, int i, vector<int>&dp){
    if(i==0) return dp[i]=0;
    if(i==1) return dp[i] =  abs( stones[1] - stones[0]);
    if(dp[i] != -1)  return dp[i];
    
        return dp[i] =  min( rec(stones, i-1, dp) + abs(stones[i] - stones[i-1]) ,
              rec(stones, i-2, dp)+ abs(stones[i]- stones[i-2]));
}
int main() {
    // your code goes here
    fastt;
    int n;
    cin>>n;
    vector<int>stones(n),dp(n,-1);
    for(int i=0; i<n;i++){
        cin>>stones[i];
    }
  
    cout<<rec(stones, n-1, dp);
    return 0;
}

//TABULATION---------------------------------------------------------------


int main() {
    // your code goes here
    fastt;
    int n;
    cin>>n;
    vector<int>stones(n),dp(n);
    for(int i=0; i<n; i++){
        cin>>stones[i];
    }

    dp[0] = 0;
    if(n>=1) dp[1] = abs(stones[1] - stones[0]);

    for(int i=2; i<n;i++){
        dp[i] = min(dp[i-1] + abs(stones[i]-stones[i-1]), 
                    dp[i-2]+ abs(stones[i]- stones[i-2]));
    }

    cout<<dp[n-1];
    return 0;
}