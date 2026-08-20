/*Sameer's Lottery Secret

Mr. Sameer wants to win the lottery. Because the student needs help calculating the number quickly, write a program that takes the array of money values as strings and outputs the largest possible concatenated number so she can win the lottery.

Input Format
Line 1: A single integer N, representing the number of money values in the array.
Line 2: N space-separated non-negative integer strings representing the money amounts.
Output Format
Print a single string representing the largest possible number formed by concatenating all the values.
Constraints
1 <= N <= 10^5
0 <= length of each string <= 10
Each string consists only of digits from 0 to 9.
Example

Input

5
3 30 34 5 9

Output

9534330

The key phrase is "largest possible number formed by concatenating all the values." So 3, 30, 34, 5, and 9 must each remain intact; you're only changing their order.*/
#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

int main() {
    int n;
    cin >> n;

    vector<string> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), compare);

    string ans = "";

    for (int i = 0; i < n; i++) {
        ans += a[i];
    }

    cout << ans;

    return 0;
}