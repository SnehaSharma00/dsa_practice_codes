/*Count Distinct Value Subarray
Difficulty: MEDIUM | Max Score: 50
Given an array of N integers, count the number of subarrays where each element is distinct.



Notes

A subarray is a contiguous part of the array.
A subarray has distinct elements when no element repeats inside it.


Input Format

The first line contains a single integer N — the size of the array.
The second line contains N space-separated integers X1, X2, … , XN.


Output Format

Print a single integer — the number of subarrays with all distinct elements.


Constraints

1 ≤ N ≤ 2 × 105
1 ≤ X[i] ≤ 109
 

Example 1:

Input: 
3
1 2 1

Output: 5

Explanation: The subarrays with distinct values are {1} , {2} , {1} , {1,2} , {2,1}.


Example 2:

Input:
4
1 2 3 4

Output: 10

Explanation: All the subarrays of this array are distinct value subarray .The subarrays are {1} , {2} , {3} , {4} , {1,2} , {1,2,3} ,{1,2,3,4} , {2,3} ,{2,3,4}  , {3,4}.*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main() {
    // your code goes here
    int n;
    cin>>n;

    vector<int>a(n);
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    vector<int>window(n);
    map<int, int>freq;
    long long l=0;
    long long count =0;

    for(int r=0; r<n; r++){
        freq[a[r]]++;
        //count++;

        while(freq[a[r]]>1){
            freq[a[l]]--;
            l++;
        }
        count += r -l + 1;
    }
    cout<<count<<endl;
    return 0;
}