/*Center of Graph - 1
Difficulty: EASY | Max Score: 25
"You can always become the star in your own world" ~do4Z
﻿

There is an undirected star graph consisting of N nodes labeled from 1 to N.

A Star Graph is a graph where there is one center node and exactly N - 1 edges that connect the center node with every other node.

You are given N-1 connections listed down and then you have to print the center of that Star Graph.



Input Format:

The first line contains and integer N - representing the number of nodes in the graph.
The next N-1 lines contains two space separated integers representing the N-1 edge connections.


Output Format:

You have to print the node which is center of the start graph.
 

Example 1:

Input: 5
2 5 
3 2
1 2 
2 4
Output: 2
Explanation: This graph will be formed like:

                         5
                      1  |  4
                       \ | /
                         2
                         |
                         |
                         3
So, as we can see that center of the graph is 2.
 

Constraints:

3 <= N <= 1015*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    // your code goes here
    map<int, int>freq;
    int x;
    for(int i=0; i<4;i++){
        cin>>x;
        freq[x]++;
    }
    int maxi = 0;
    for(auto it : freq){
        if(it.second > freq[maxi]){
            maxi = it.first;
        }
    }
    cout<<maxi;
    return 0;
}