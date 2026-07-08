/*Invasion
Difficulty: MEDIUM | Max Score: 50
Provided a list of bombs. The range of a bomb is defined as the area where its effect can be felt. This area is in the shape of a circle with the center as the location of the bomb.



The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.



You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. These bombs will further detonate the bombs that lie in their ranges.



Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.

 

Example 1:

Input: bombs = [[2,1,3],[6,1,4]]
Output: 2
Explanation: The above figure shows the positions and ranges of the 2 bombs.
If we detonate the left bomb, the right bomb will not be affected.
But if we detonate the right bomb, both bombs will be detonated.
So the maximum bombs that can be detonated is max(1, 2) = 2.


Example 2:

Input: bombs = [[1,1,5],[10,10,5]]
Output: 1
Explanation: Detonating either bomb will not detonate the other bomb, so the maximum number of bombs that can be detonated is 1.
 

Constraints:

1 <= bombs.length <= 100
bombs[i].length == 3
1 <= xi, yi, ri <= 105*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
void dfs(int u, vector<vector<int>> &adj, vector<int> &vis, int &cnt) {
        vis[u] = 1;
        cnt++;
        for (int v : adj[u]) {
            if (!vis[v])
                dfs(v, adj, vis, cnt);
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r = bombs[i][2];

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                long long dx = x1 - bombs[j][0];
                long long dy = y1 - bombs[j][1];

                if (dx * dx + dy * dy <= r * r)
                    adj[i].push_back(j);
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> vis(n, 0);
            int cnt = 0;
            dfs(i, adj, vis, cnt);
            ans = max(ans, cnt);
        }

        return ans;
    }

};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (cin >> n) {
        vector<vector<int>> bombs(n, vector<int>(3));
        for (int i = 0; i < n; ++i) {
            cin >> bombs[i][0] >> bombs[i][1] >> bombs[i][2];
        }
        
        Solution sol;
        cout << sol.maximumDetonation(bombs) << "\n";
    }
    return 0;
}