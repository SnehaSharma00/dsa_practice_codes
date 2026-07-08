/*Special Arrangement
Difficulty: MEDIUM | Max Score: 50
Given integers A, B, and C representing the number of tiles of three different colors — Red, Green, and Blue respectively.

You have a total of N tiles, where N=A+B+C.



Your task is to count and print all special arrangements of these tiles.



A special arrangement is one where no two adjacent tiles have the same color, i.e., for every valid arrangement:

arr[i]≠arr[i+1]



Input Format

The first line contains a single integer T — the total number of test cases.



Each test case consists of:

A single line containing three space-separated integers A, B, and C


Output Format

For each testcase, print all the special arrangements in a sorted manner.


Constraints

1 <= T<=5
0 <= A, B, C <= 3
A+B+C ==N




Example 1:

Input:
3
0 0 0
1 1 0
1 1 1﻿

Output:
AB
BA
ABC
ACB
BAC
BCA
CAB
CBA

Explanation:
Case 1: No special arrangement can be found.
Case 2: There are two special arrangements
Case 3: There are six special arrangements.
*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
void rec(string s, int a, int b, int c, vector<string> &ans){
   
    if(a<=0 && b<=0 && c<=0 ){
         ans.push_back(s);
        return;
    }
    if(s.empty()){
        if(a>=1) rec(s+'R', a-1, b, c, ans);
        if(b>=1) rec(s+'G', a, b-1, c, ans);
        if(c>=1) rec(s+'B', a, b, c-1, ans);
    }
    else{
    char lastchar  = s.back();
    if(lastchar == 'R'){
        if(b>=1) rec(s+'G', a, b-1, c, ans);
        if(c>=1) rec(s+'B', a, b, c-1, ans);
    }
    if(lastchar == 'G'){
        if(a>=1) rec(s+'R', a-1, b, c, ans);
        if(c>=1) rec(s+'B', a, b, c-1, ans);   
    }
    if(lastchar == 'B'){
        if(a>=1) rec(s+'R', a-1, b, c,ans);
        if(b>=1) rec(s+'G', a, b-1, c, ans);   
    }
    }
}
int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        string s = "";
        vector<string>ans;
        if(a<=0 && b<=0 && c<=0 )continue;
        rec(s, a, b, c, ans);
        sort(ans.begin(), ans.end());
        for(auto it : ans){
            cout<<it<<"\n";
        }
    }
    return 0;
}