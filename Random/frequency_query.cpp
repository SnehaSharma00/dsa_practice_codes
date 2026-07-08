/*Frequency Query
Difficulty: EASY | Max Score: 25
You are given an integer array of size N and Q queries.



For each query, you are given an integer X, and your task is to determine the frequency of X in the given array.



Input Format

The first line contains an integer N, representing the size of the array.
The second line contains N space-separated integers representing the elements of the array.
The third line contains an integer Q, denoting the number of queries.
The next Q lines each contain a single integer X.


Output Format

For each query, print a single integer representing the number of times X occurs in the array.


Constraints

1 ≤ N ≤ 105
1 ≤ A[i]​, X ≤ 109
1 ≤ Q ≤ 105


Example 1:

Input:
5
1 2 2 4 5
5
1
2
3
4
5

Output:
1
2
0
1
1

Explanation:
Query 1: The value 1 appears once in the array.
Query 2: The value 2 appears two times in the array.
Query 3: The value 3 does not appear in the array.
Query 4: The value 4 appears once in the array.
Query 5: The value 5 appears once in the array.*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;
int main() {
    // your code goes here
    int n, q, x;
    cin>>n;

    vector<int>a(n);
    map<int, int>freq;

    for(int i=0; i<n;i++){
        cin>>a[i];
        freq[a[i]]++;
    }
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        cout<<freq[x]<<endl;
    }



    return 0;
}