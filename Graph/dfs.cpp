/*Can we reach to city Y ?
Difficulty: MEDIUM | Max Score: 50
You are living in a country where there are N cities. All these cities are having indexes regarding to them from 1 to N
There are also 2 way roads between different cities. If there exists a 2 way road between A and B, then it is possible to transmute between A and B cities.
Currently you are having a car with you on the city X. Can you find out if you will be ever able to reach city Y ?
Input Format:
The first line contains an integer N, M, X and Y - representing the number of cities, the number of 2-way roads, the city where you are right now and the city where you want to reach.
Next M lines will contain 2 integers in each line representing Ui and Vi representing the cities between which i-th road is.
Output Format:
If you would be able to reach city Y starting from city X, then print "YES" otherwise print "NO".
Example 1:

Input: 7 7 3 6
1 2
2 3
3 4
4 5
5 6
6 7
1 7

Output: YES

Explanation: The graph is like a loop bounded by all the seven cities which makes it possible to go from city 3 to 6.
Constraints:
1 <= N, M <= 105
1 <= X, Y, Ui , Vi <= N
There will be no Self loops(edges starting and ending at same node) in the given graph.*/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
void dfs(vector<vector<int>> &adj, vector<int> &vis, int node){
    vis[node]++;

    for(int i=0; i<adj[node].size(); i++){
        int neighbour = adj[node][i];
        if(vis[neighbour] == 0){
            dfs(adj, vis, neighbour);
        }
    }
}
int main() {
    // your code goes here
    int n, m, x, y;
    cin>>n>>m>>x>>y;

    vector<vector<int>>adj(n+1);

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n+1, 0);

    dfs(adj, vis, x );

    cout<<((vis[y] == 1)?"YES":"NO");
    return 0;
}
//time complexity of dfs : O(v+e) linear or O(n)