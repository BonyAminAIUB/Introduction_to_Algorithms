// Max area of Island
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        bool vis[55][55];
        vector<pair<int,int>> d = {{0,-1},{0,1},{-1,0},{1,0}};
        int n,m,count,mx;

        bool valid(int i, int j){
            if(i<0 || i>=n || j<0 || j>=m){
                return false;
            }
            return true;
        }

        void DFS(int si, int sj, vector<vector<int>>& grid){
            vis[si][sj] = true;
            count ++;
            for(int i = 0; i<4; i++){
                int ci = si + d[i].first;
                int cj = sj + d[i].second;
                if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] == 1){
                    DFS(ci,cj,grid);
                }
            }
        }

        int maxAreaIsland(vector<vector<int>>& grid){
            n = grid.size();
            m = grid[0].size();
            mx = 0;
            memset(vis,false,sizeof(vis));
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    if(!vis[i][j] && grid[i][j] == 1){
                        count = 0;
                        DFS(i,j,grid);
                        mx = max(count,mx);
                    }
                }
            }
            return mx;
        }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m; 

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    Solution sol;
    cout << sol.maxAreaIsland(grid) << endl;

    return 0;
}
