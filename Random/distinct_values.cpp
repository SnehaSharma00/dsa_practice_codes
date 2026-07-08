/*Distinct Values
Difficulty: EASY | Max Score: 25
You are given a list of N integers.

Your task is to calculate the number of distinct values in the list.



Input Format

The first line contains a single integer N - the number of values.
The second line contains N space-separated integers x1, x2,.... xn.


Output Format

Print a single integer — the number of distinct values in the list.


Constraints

1 ≤ N ≤ 2 · 105
1 ≤ xi ≤ 109




 

Example 1:

Input: 
5
3 1 4 1 5

Output: 4

Explanation: 
The list is {3, 1, 4, 1, 5}. The distinct values are {1, 3, 4, 5}. Hence, the answer is 4.


Example 2:

Input:
5
2 2 3 5 5

Output: 3

Explanation: 
The list is {2, 2, 3, 5, 5}. The distinct values are {2, 3, 5}. Hence, the answer is 3.*/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main() {
    // your code goes here
    int n;
    cin>>n;
    int x;
    set<int>st;
    for(int i=0; i<n;i++){
        cin>>x;
        st.insert(x);
    }
    cout<<st.size()<<endl;
    return 0;
}