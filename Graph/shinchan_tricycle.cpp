/*Shinchan's Epic Tricycle Story
Difficulty: HARD | Max Score: 75
"I am a Good Boy like Shinchan :) " ~do4Z


Shinchan and his friends in Hinderland are planning to travel to a mega Action Kamen event! There are N cities in Hinderland, and Shinchan starts his journey at city 1. The event is happening at city N. The map of cities forms an undirected graph with N cities and M roads. Each road i connects two cities and has a base length of Wi.

Unfortunately, Shinchan's cycle is broken, but he has plenty of pocket money. Every city sells exactly one type of tricycle. The tricycle sold in the i-th city has a "sluggishness factor" of i.

Once Shinchan buys a tricycle in a city, he can ride it to any neighboring city. If he traverses a road of base length W using a tricycle with sluggishness factor S, it takes him W * S units of time. Shinchan can buy as many tricycles as he wants along the way, abandoning his old one whenever he finds a better (less sluggish) tricycle in a new city.

Since Shinchan is impatient, he wants to reach the Action Kamen event as quickly as possible. Calculate the minimum amount of time required for Shinchan to travel from city 1 to city N. It is guaranteed that city N is reachable from city 1.





Input Format:

The first line contains two space-separated integers: N (number of cities) and M (number of roads).
The next M lines each contain three space-separated integers U, V, and W, representing an undirected road between city U and city V with a base length of W.
The final line contains N space-separated integers, where the i-th integer is Si, the sluggishness factor of the tricycle available in city i.


Output Format:

Print a single integer representing the shortest amount of time required to travel from city 1 to city N.




 

Example 1:

Input: 3 3
1 2 10
2 3 10
1 3 100
5 1 2
Output: 60
Explanation: Shinchan starts at city 1. He buys the tricycle at city 1 (sluggishness = 5).
He could travel directly from 1 to 3: Time taken = 100 * 5 = 500.
Or, he travels from 1 to 2: Time taken = 10 * 5 = 50.
At city 2, he buys a new tricycle (sluggishness = 1).
He travels from 2 to 3 with the new tricycle: Time taken = 10 * 1 = 10. Total minimum time = 50 + 10 = 60.


Example 2:

Input: 4 4
1 2 10
2 3 20
3 4 30
1 3 40
10 4 10 10
Output: 300
Explanation: Shinchan starts at city 1 and buys the tricycle (sluggishness = 10).
Travels 1 to 2: Time = 10 * 10 = 100.
At city 2, he buys a new tricycle (sluggishness = 4).
Travels 2 to 3: Time = 20 * 4 = 80.
Keeps the same tricycle (since the one at city 3 has sluggishness 10, which is worse).
Travels 3 to 4: Time = 30 * 4 = 120. Total time = 100 + 80 + 120 = 300.
 

Constraints:

2 <= N <= 1000
1 <= M <= 1000
1 <= U, V <= N
1 <= W <= 105
1 <= Si <= 1000*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long shortestTime(int N, vector<vector<pair<int,int>>> &adj, vector<int> &bike) {
        const long long INF = 1e18;

        vector<vector<long long>> dist(N + 1, vector<long long>(1001, INF));

        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;

        dist[1][bike[1]] = 0;
        pq.push({0, 1, bike[1]});

        while (!pq.empty()) {
            auto [d, u, s] = pq.top();
            pq.pop();

            if (d != dist[u][s]) continue;

            for (auto &e : adj[u]) {
                int v = e.first;
                int w = e.second;

                int ns = min(s, bike[v]);
                long long nd = d + 1LL * w * s;

                if (nd < dist[v][ns]) {
                    dist[v][ns] = nd;
                    pq.push({nd, v, ns});
                }
            }
        }

        long long ans = INF;
        for (int s = 1; s <= 1000; s++)
            ans = min(ans, dist[N][s]);

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int,int>>> adj(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> bike(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> bike[i];

    Solution obj;
    cout << obj.shortestTime(N, adj, bike);

    return 0;
}