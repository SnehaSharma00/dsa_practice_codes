/*The Grand Royal banquet
Difficulty: MEDIUM | Max Score: 50
The King of a massive empire is hosting a legendary banquet and has invited N nobles from across the realm.

However, the realm's politics are messy, and there are M known bitter rivalries between certain pairs of nobles. If two rivals are placed in the same room, they will start a duel and ruin the entire evening.

The King's castle has exactly two massive dining halls. Your task as the Royal Advisor is to determine if it is possible to divide all the nobles into these two dining halls such that no two rivals end up in the same hall.



Input Format:

The first line contains two integers N and M - representing the number of nobles (numbered from 1 to N) and the number of rivalries.
The next M lines contain two integers Ui and Vi - representing a mutual rivalry between noble Ui and noble Vi.


Output Format:

Print "YES" if it is possible to safely divide the nobles into the two halls. Otherwise, print "NO".


 

Example 1:

Input: 4 4
1 2
1 3
2 4
3 4
Output: YES
Explanation: We can put Nobles 1 and 4 in Hall A, and Nobles 2 and 3 in Hall B. No rivals share a room.


Example 2:

Input: 3 3
1 2
2 3
1 3
Output: NO
Explanation: The rivalries form a triangle. If Noble 1 is in Hall A, Noble 2 must be in Hall B. But Noble 3 is rivals with both of them, leaving them nowhere to sit!
 

Constraints:

1 <= N <= 105
0 <= M <= 105*/

//bi- partite
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include<queue>
#include <set>
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
    
     for(int i=0; i<=n;i++){
        if(vis[i]!=0) continue;

        queue<int> q;
        q.push(i);
        vis[i] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            

            for(int j=0; j< adj[node].size();j++){
                int neighbour = adj[node][j];
                if(vis[neighbour]==0){
                    vis[neighbour] = 3 - vis[node];
                    q.push(neighbour);
                }
                else{
                    if(vis[neighbour]==vis[node]){
                        cout<<"NO\n";
                        return 0;
                    }
                }

            }
        }
    }
    cout<<"YES\n";
    return 0;
}