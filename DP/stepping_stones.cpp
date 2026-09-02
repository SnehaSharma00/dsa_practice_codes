/*Stepping Stones
Difficulty: EASY | Max Score: 25
You are crossing a river by jumping across a sequence of stones. There are n stones in total. From your current stone, you can either jump to the very next stone (1 step ahead) or jump to the stone after it (2 steps ahead).



In how many distinct ways can you reach the nth stone?



Note: Since n can be up to 105, the number of ways can be extremely large. Return the answer modulo 109 + 7.

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to reach the 2nd stone.
1. Jump 1 stone ahead + Jump 1 stone ahead
2. Jump 2 stones ahead


Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to reach the 3rd stone.
1. Jump 1 stone ahead + Jump 1 stone ahead + Jump 1 stone ahead
2. Jump 1 stone ahead + Jump 2 stones ahead
3. Jump 2 stones ahead + Jump 1 stone ahead
 

Constraints:

1 <= n <= 105*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    const long long MOD = 1000000007;

    if (n == 1) {
        cout << 1;
        return 0;
    }

    long long prev2 = 1; // dp[1]
    long long prev1 = 2; // dp[2]

    for (int i = 3; i <= n; i++) {
        long long curr = (prev1 + prev2) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1;

    return 0;
}