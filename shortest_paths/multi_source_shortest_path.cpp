//directed graph
//floyd warshal
//distance matrix but can use adj list too ig

/*Multi-Source Shorted Path
Difficulty: MEDIUM | Max Score: 50
You are given a directed weighted graph with N vertices and M edges. You need to find the shortest distance between every pair of vertices i and j. If no path exists between vertex i and vertex j, the distance should be represented as "INF".



Note: Modify the distances for every pair in place.



Example 1:

Input: 
4 4
0 1 5
1 2 3
2 3 1
0 3 10
Output: 
0 5 8 9
INF 0 3 4
INF INF 0 1
INF INF INF 0
Explanation: The output represents an N x N matrix where matrix[i][j] is the shortest path from vertex i to vertex j. For instance, the shortest path from vertex 0 to vertex 3 is not the direct edge of weight 10, but rather the path 0 -> 1 -> 2 -> 3 which costs 5 + 3 + 1 = 9.


Example 2:

Input:
3 2
0 1 2
1 0 3
Output:
0 2 INF
3 0 INF
INF INF 0
Explanation: Vertex 2 has no incoming or outgoing edges, so it is disconnected. The distance from any node to vertex 2, and from vertex 2 to any other node, is "INF". The distance from a node to itself is always 0.
 

Constraints:

1 ≤ N ≤ 100
1 ≤ M ≤ N x (N - 1)
1 ≤ Weight ≤ 1000*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // Change 1
    for(int i = 0; i < n; i++)
        dist[i][i] = 0;

    // Change 2 & 3
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    for(int intermed = 0; intermed < n; intermed++) {
        for(int src = 0; src < n; src++) {
            for(int dest = 0; dest < n; dest++) {

                if(dist[src][intermed] != INT_MAX &&
                   dist[intermed][dest] != INT_MAX) {

                    dist[src][dest] = min(
                        dist[src][dest],
                        dist[src][intermed] + dist[intermed][dest]
                    );
                    
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}