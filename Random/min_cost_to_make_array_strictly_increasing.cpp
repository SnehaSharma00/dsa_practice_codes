/*Minimum Cost to Make Array Strictly Increasing
Difficulty: EASY | Max Score: 25
You are given an integer N and an integer array A of size N.



Your task is to make the array strictly increasing.

An array is strictly increasing if:



A[i] > A[i−1] for all i from 1 to N − 1



You are allowed to increase any element by any positive integer value k.

Increasing an element by k costs exactly k.



Your goal is to minimize the total cost required to make the array strictly increasing.

Print the minimum total cost required.



Input Format

N: INTEGER – size of the array
A: INTEGER ARRAY – the given array


Output Format

Print a single INTEGER representing the minimum total cost required to make the array strictly increasing.


Constraints

1 ≤ N ≤ 200000
−109 ≤ A[i] ≤ 109


Example 1:

Input:
4
1 5 2 4

Output:
7

Explanation:
Increase 2 → 6 (cost = 4)

Increase 4 → 7 (cost = 3)

But optimal solution is:

1 5 6 7

Minimum total cost = 7*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int main() {
    // your code goes here
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    int curcost=0;
    long long totalcost =0;
    
    stack<int>st;
    
    for(int i=0; i<n;i++){
        if(st.empty() || a[i]>st.top()) st.push(a[i]);
        else{
            curcost = st.top()-a[i] + 1;
            totalcost += curcost;
            st.push(a[i]+curcost);
        }
    }
    cout<<totalcost<<"\n";
    return 0;
}