/*Ranking Pairs
Difficulty: EASY | Max Score: 25
Consider an infrastructure consisting of n cities, connected by a certain number of roads. Every roads[i] = [ai, bi] signifies the presence of a bidirectional road linking city ai and city bi.



The network rank for any two distinct cities is determined by the total count of roads directly connected to either of the two cities. If a single road connects both cities directly, it is counted only once.



The maximal network rank of this infrastructure is the absolute maximum network rank found among all possible pairs of different cities.



Provided the integer n and the roads array, you must return the maximal network rank for the entire infrastructure.



 

Example 1:

Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
Output: 4
Explanation: The network rank of cities 0 and 1 is 4 as there are 4 roads that are connected to either 0 or 1. The road between 0 and 1 is only counted once.


Example 2:

Input: n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
Output: 5
Explanation: The network rank of 2 and 5 is 5. Notice that all the cities do not have to be connected.
 

Constraints:

2 <= n <= 100
0 <= roads.length <= n * (n - 1) / 2
roads[i].length == 2
0 <= ai, bi <= n-1
ai != bi
Each pair of cities has at most one road connecting them.*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
      vector<int> degree(n, 0);
        vector<vector<int>> connected(n, vector<int>(n, 0));

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            degree[u]++;
            degree[v]++;
            connected[u][v] = 1;
            connected[v][u] = 1;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j];
                if (connected[i][j])
                    rank--;
                ans = max(ans, rank);
            }
        }

        return ans;
    }
    
};

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    vector<vector<int>> roads(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> roads[i][0] >> roads[i][1];
    }
    
    Solution obj;
    cout << obj.maximalNetworkRank(n, roads) << "\n";
    
    return 0;
}