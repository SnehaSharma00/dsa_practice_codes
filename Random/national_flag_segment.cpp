/*National Flag Segment
Difficulty: EASY | Max Score: 25
With the arrival of Independence Day, Anoop decorates roads with N flags in a random array-like pattern.

The array consists of binary elements, where 1 denotes a flag, and 0 denotes an empty space.

His friend Vivek presents an intriguing problem: Counting the total number of subarrays of size K with exactly M flags.



Input Format:

The first line contains T, the total number of testcases
The first line of each testcase contains three space-separated integers N, K, and M, where N represents the total length of the binary array, K is the size of the subarray and M is the number of flags that should be present in the subarray.
The second line of each testcase contains N space-separated positive integers, A1, A2, A3, ......, AN.


Output Format:

Print the total number of subarrays of size K with exactly M flags.


Constraints:

1 ≤ T ≤ 10
1 ≤ N ≤ 105 
1 ≤ K, M ≤ N
0 ≤ A[i] ≤ 1


Example:

Input:
1
9 3 2
1 0 0 1 0 1 0 1 1

Output:
3

Explanation:
﻿N = 9, K = 3, M = 2
A = [1, 0, 0, 1, 0, 1, 0, 1, 1]
Ans = 3
Assuming we are using 1-based indexing :
Subarray [4, 6] has 2 flags
Subarray [6, 8] has 2 flags
Subarray [7, 9] has 2 flags*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    // your code goes here
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        int n, k, m; 
        cin>>n>>k>>m;

        vector<int>a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        int ans=0;
        int sum = 0;
        for(int i=0; i<k;i++){
            sum += a[i];
        }
        
        for(int i=k; i<n;i++){
            if(sum==m)ans++;
            sum -= a[i-k];
            sum += a[i];
        }
        if(sum==m)ans++;
        cout<<ans<<"\n";
    }