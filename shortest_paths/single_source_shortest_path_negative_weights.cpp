//bellman ford
//negative weights


/*Shortest Path with Negative Weights
Difficulty: MEDIUM | Max Score: 50
You are given a directed, weighted graph consisting of V vertices numbered from 0 to V-1 and E directed edges. You are also given a source vertex, src.

Your task is to calculate the minimum distance required to travel from the source vertex to every other vertex in the graph.

Because the graph may contain negative edge weights, you must account for the following special conditions:

Unreachable Nodes: If a vertex is completely unreachable from the source vertex, its shortest distance should be represented as 108 (100000000).
Negative Weight Cycles: If the graph contains a cycle where the sum of the edge weights is strictly less than zero, the shortest paths can decrease infinitely. If such a negative weight cycle exists, shortest paths cannot be reliably computed. In this case, you must simply return -1.






Input Format:

The first line contains three space-separated integers: V (number of vertices), E (number of edges).
The next E lines each contain three space-separated integers u, v, and w, representing a directed edge from vertex u to vertex v with a travel weight of w.
The last line contains a integer src.
Output Format:

If a negative weight cycle exists, print a single integer: -1.
Otherwise, print a single line containing V space-separated integers, where the i-th integer represents the shortest distance from src to vertex i.


 

Example 1:

Input: 5 5
1 3 2
4 3 -1
2 4 1
1 2 1
0 1 5
0
Output: 0 5 6 6 7
Explanation: Shortest Paths:
For 0 to 1 minimum distance will be 5. By following path 0 → 1
For 0 to 2 minimum distance will be 6. By following path 0 → 1  → 2
For 0 to 3 minimum distance will be 6. By following path 0 → 1  → 2 → 4 → 3 
For 0 to 4 minimum distance will be 7. By following path 0 → 1  → 2 → 4


Example 2:

Input: 4 4
0 1 4
1 2 -6
2 3 5
3 1 -2
0
Output: [-1]
Explanation: The graph contains a negative weight cycle formed by the path 1 → 2 → 3 → 1, where the total weight of the cycle is negative.
 

Constraints:

1 <= V <= 500
1 <= E <= V * (V - 1)
0 <= src < V
0 <= u, v < V
-105 <= w <= 105*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    // your code goes here
    int V, E;
    cin>>V>>E;
    vector<vector<int>>edges(E, vector<int>(3));
    for(int i=0; i<E;i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    int src;
    cin>>src;
    vector<int>dist(V, 100000000);
    dist[src] = 0;
    for(int i=1; i<V; i++){
    for(int j=0; j<edges.size(); j++){
        int u = edges[j][0], v = edges[j][1], w=edges[j][2];
        //intermediate-> u , dest->v
        if((dist[u] != 100000000)&& dist[v]>dist[u]+w){
            dist[v] = dist[u] + w;
        }
    }

    }
    int negcycle  =0;
    for(int j=0; j<edges.size();j++){
        int u = edges[j][0], v = edges[j][1], w=edges[j][2];
        if((dist[u] != 100000000)&& dist[v]>dist[u]+w){
            negcycle++;
        }
    }
    if(negcycle >0){
        cout<<-1;
        return 0;
    }
    for(auto &i : dist){
        cout<<i<<" ";
    }

    return 0;
}