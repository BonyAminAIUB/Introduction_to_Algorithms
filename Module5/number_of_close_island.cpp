// Number of Closed Islands
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        bool vis[105][105];
        vector<pair<int,int>> d = {{0,-1},{0,1},{-1,0},{1,0}};
        int n,m;
        bool flag;

        bool valid(int i, int j){
            if(i<0 || i>=n || j<0 || j>=m){
                return false;
            }
            return true;
        }

        void DFS(int si, int sj, vector<vector<int>>& grid){
            vis[si][sj] = true;
            for(int i = 0; i<4; i++){
                int ci = si + d[i].first;
                int cj = sj + d[i].second;
                if(!valid(ci,cj)){
                    flag = false;
                }
                if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] == 0){
                    DFS(ci,cj,grid);
                }
            }
        }

        int closeIsland(vector<vector<int>>& grid){
            int count = 0;
            n = grid.size();
            m = grid[0].size();
            memset(vis,false,sizeof(vis));
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    if(!vis[i][j] && grid[i][j] == 0){
                        flag = true;
                        DFS(i,j,grid);
                        if(flag == true){
                            count++;
                        }
                    }
                }
            }
            return count;
        }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m; // grid size: n rows, m columns

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    Solution sol;
    cout << sol.closeIsland(grid) << "\n";

    return 0;
}
