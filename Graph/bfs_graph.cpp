/*Breadth First Search of a Graph
Difficulty: MEDIUM | Max Score: 50
You are given N nodes numbered from 1 to N and M edges. You have to print the Breadth First Search Traversal order of the given graph.

You have to start the traversal from node 1.



Input Format:

The first line contains two space separated integers N and M - representing
The next M lines contains 2 space separated integers representing Ui and Vi


Output Format:

You have to print N space separated integers representing the BFS traversal of the graph.


 

Example:

Input: 5 6
3 4
1 2
5 3
2 5
1 3
4 2
Output: 1 2 3 5 4
Explanation: The level order traversal of this graph will be printed as shown above: 1 2 3 5 4
 

Constraints:

1<=N, M <=105*/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    // your code goes here
    int n, m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0; i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n+1, 0);

    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        vis[node]++;
        cout<<node<<" ";

        for(int i=0; i<adj[node].size();i++){
            int neighbour = adj[node][i];
            if(vis[neighbour]==0){
                vis[neighbour]++;
                q.push(neighbour);
            }
        }
    }
    return 0;
}