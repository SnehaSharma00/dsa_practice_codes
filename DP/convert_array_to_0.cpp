/*Convert array to 0

You are given an array of n non-negative integers. The goal is to make all elements of the array equal to 0 using the minimum possible cost.

You can perform the following two operations any number of times, in any order:

Range Decrement Operation:
Choose any contiguous range [l, r] and decrease every element in that range by 1. This operation costs x.
Individual Zero Operation:
Choose any single element and directly set it to 0. This operation costs y.

Return the minimum total cost required to make every element of the array 0.

Example
Input:
n = 3
x = 2
y = 3


Array:
[4, 2, 1]


Output:
7

One optimal way is:

Set the first element 4 directly to 0 → cost 3.
Apply the range operation [2,3] twice:
[0,2,1] → [0,1,0] → [0,0,0] → cost 2 × 2 = 4.

Total cost:

3 + 4 = 7

Therefore, the minimum cost is 7.*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x, y;

    cin >> n >> x >> y;

    vector<long long> a(n);
    for (auto &v : a)
        cin >> v;

    // First element:
    // Option 1: directly make it zero
    long long dp0 = y;

    // Option 2: use range operations
    long long dp1 = a[0] * x;

    for (int i = 1; i < n; i++) {

        long long new_dp0 = min(dp0, dp1) + y;

        long long new_dp1 = min(
            dp0 + a[i] * x,
            dp1 + max(0LL, a[i] - a[i - 1]) * x
        );

        dp0 = new_dp0;
        dp1 = new_dp1;
    }

    cout << min(dp0, dp1) << '\n';

    return 0;
}
