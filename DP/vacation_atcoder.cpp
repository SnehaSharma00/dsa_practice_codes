#include <iostream>
#include <vector>
using namespace std;
int happy( int idx, int task, vector<int>&a, vector<int>&b, vector<int>&c, vector<vector<int>>&dp ){
    if(idx <0) return 0;
    if(dp[task][idx] != -1) return dp[task][idx];
    if(task==0) return dp[0][idx] =  max(happy(idx-1, 1, a ,b, c, dp), happy(idx-1, 2, a, b, c, dp)) + a[idx];
    if(task==1) return dp[1][idx] = max(happy(idx-1, 0, a ,b, c, dp), happy(idx-1, 2, a, b, c, dp)) + b[idx];
    if(task==2) return dp[2][idx] = max(happy(idx-1, 0, a ,b, c, dp), happy(idx-1, 1, a, b, c, dp)) + c[idx];
    return 0;
}

int main(){
    int n;
    cin>>n;

    vector<int> a(n), b(n), c(n);
    for(int i=0; i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
 vector<vector<int>>dp(3, vector<int>(n, -1));
 cout<<max({happy(n-1, 0, a, b, c, dp) , happy(n-1, 1, a, b, c, dp), happy(n-1, 2, a, b, c, dp)});

return 0; 

}
