/*Special City
Difficulty: MEDIUM | Max Score: 50
There are n cities numbered from 0 to n-1. You are given m bidirectional roads connecting these cities. The i-th road connects ui city and city vi with a length of wi. You are also given an integer t, representing the distance threshold.



The distance between two cities is the minimum total weight of a path connecting them. A city j is considered a neighbor of city i if the distance between them is at most t and i ≠ j.



Your task is to find the city with the smallest number of reachable neighbors within the threshold distance t. If there are multiple cities with the same minimum number of neighbors, output the city with the maximum index.



Input Format:

The first line contains three space-separated integers: n (number of cities), m (number of roads), and t (distance threshold).
The next m lines each contain three space-separated integers u, v, and w, representing a bidirectional road connecting city u and city v with a length of w.


Output Format:

Print a single integer: the index of the city with the smallest number of reachable neighbors within the distance threshold t. If there are multiple such cities, print the one with the maximum index.
 

Example 1:

Input: 
4 4 4
0 1 3
1 2 1
1 3 4
2 3 1
Output: 3
Explanation: The neighboring cities at a distance threshold = 4 for each city are:
City 0 -> [City 1, City 2]
City 1 -> [City 0, City 2, City 3]
City 2 -> [City 0, City 1, City 3]
City 3 -> [City 1, City 2]
Cities 0 and 3 have 2 neighboring cities at a threshold = 4, but we output city 3 since it has the maximum index.


Example 2:

Input: 
5 6 2
0 1 2
0 4 8
1 2 3
1 4 2
2 3 1
3 4 1
Output: 0
Explanation: The neighboring cities at a distance threshold = 2 for each city are:
City 0 -> [City 1]
City 1 -> [City 0, City 4]
City 2 -> [City 3, City 4]
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3]
City 0 has 1 neighboring city at a distance threshold = 2.
 

Constraints:

2 <= n <= 100
1 <= m <= n * (n - 1) / 2
0 <= u < v < n
1 <= w, t <= 10000
All pairs (u, v) are distinct.*/

#include <iostream>
using namespace std;

const int INF = 1000000000;

int main() {
    int n, m, t;
    cin >> n >> m >> t;

    int dist[105][105];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w < dist[u][v]) {
            dist[u][v] = w;
            dist[v][u] = w;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    int ans = -1;
    int minCount = INF;

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= t)
                cnt++;
        }

        if (cnt <= minCount) {
            minCount = cnt;
            ans = i;
        }
    }

    cout << ans;

    return 0;
}