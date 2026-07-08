/*Encrypted Key Generation
Difficulty: MEDIUM | Max Score: 50
A secret encryption system generates unique keys based on a given sequence of numbers. Each number in the sequence maps to a specific set of characters, and your task is to generate all possible valid encryption keys by replacing each digit with its corresponding character set.

Keys must be generated in a recursive manner from left to right, maintaining the natural order of generation.



Character Mapping Rules

Each digit (1-9) maps to a set of characters as follows:

 Digit - Characters Mapping

1  - T, I
2  - X, Y, Z
3  - A, B, C
4  - M, N, O
5  - P, Q, R
6  - E, F, G
7  - U, V, W
8  - J, K, L
9  - D, S, H


Rules:

Each digit must be replaced by one of its corresponding characters.
The digits must be processed in order from left to right.
All possible valid key combinations should be generated.
The output must preserve the order in which keys are generated recursively (depth-first order).

Input Format

A single string S consisting of 0 to 4 digits (each from '1' to '9').


Output Format

Print all possible encryption keys, space-separated, in the recursive order of generation.


Constraints

0 ≤ S.length ≤ 4
S consists only of digits from '1' to '9'.




Example 1

Input:
12

Output:
TX TY TZ IX IY IZ

Explanation:
1 → {T, I}
2 → {X, Y, Z}
Generated keys (depth-first order):
T → X, Y, Z → TX TY TZ
I → X, Y, Z → IX IY IZ




Example 2

Input:
59

Output:
PD PS PH QD QS QH RD RS RH

Explanation:
5 → {P, Q, R}
9 → {D, S, H}
The recursive generation follows:
P → D, S, H → PD PS PH
Q → D, S, H → QD QS QH
R → D, S, H → RD RS RH*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

void rec(int i, string s, string curr,map<int, string>&charmap, vector<string>&ans){
    if(i>= s.size()){
        ans.push_back(curr);
        return;
    }
    int key = s[i]-'0';
    string code = charmap[key];

    for(int j=0; j<code.size();j++){
        rec(i+1, s, curr + code[j], charmap, ans);
    }
}
int main() {
    // your code goes here
    map<int, string>charmap;
    charmap.insert({1, "TI"});
    charmap.insert({2, "XYZ"});
    charmap.insert({3, "ABC"});
    charmap.insert({4, "MNO"});
    charmap.insert({5, "PQR"});
    charmap.insert({6, "EFG"});
    charmap.insert({7, "UVW"});
    charmap.insert({8, "JKL"});
    charmap.insert({9, "DSH"});

    string s;
    cin>>s;
    vector<string> ans;
    rec(0, s, "",charmap, ans);
    
    for(auto it : ans){
        cout<<it<<" ";
    }
    
    
    return 0;
}