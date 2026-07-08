#include <bits/stdc++.h>
using namespace std;

bool safe(int i, int j, int n, int m, vector<vector<int>>&grid , vector<vector<int>>&vis){
    return (i>=0 && j>=0 && i<n && j<m && vis[i][j]==0 && grid[i][j]==1 );
}


int bfs(vector<vector<int>>&grid, vector<vector<int>>&vis, int i, int j, int n, int m){
        queue<pair<int,int>> q;
        q.push({i,j});

        vis[i][j] =1;

        int mins =0;
        while(!q.empty()){

            int levelsize = q.size();
         //   vector<pair<int,int>>curlevel;
            bool minadd = false;
            
            for(int I=0;I<levelsize; I++){
                
                int nodei = q.front().first;
                int nodej = q.front().second;
                q.pop();


                if(safe(nodei+1, nodej, n, m, grid, vis)) {
                    vis[nodei+1][nodej]++;
                    q.push({nodei+1, nodej});
                    minadd = true;
                }
                if(safe(nodei, nodej+1, n, m, grid, vis)) {
                    vis[nodei][nodej+1]++;
                    q.push({nodei, nodej+1});
                    minadd = true;
                }
                if(safe(nodei-1, nodej, n, m, grid, vis) ) {
                    vis[nodei-1][nodej]++;
                    q.push({nodei-1, nodej});
                    minadd = true;
                }
                if(safe(nodei, nodej-1, n, m, grid, vis)) {
                    vis[nodei][nodej-1]++;
                    q.push({nodei, nodej-1});
                    minadd = true;
                }
            }
             if (minadd) mins++;
    }
    return mins;

}

int main(){
    int n, m;
    cin>>n>>m;

  vector<vector<int>>grid(n, vector<int>(m));
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<int>>vis(n, vector<int>(m, 0));

    int maxmin = 0;

    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==2 && vis[i][j]==0){
                maxmin = max(maxmin, bfs(grid, vis, i, j, n, m));
            } 
        }
    }

    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(vis[i][j]==0 && grid[i][j]==1){
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<maxmin;
    return 0;

}

