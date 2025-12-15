// Number of Islands
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        bool vis[305][305];
        vector<pair<int,int>> d = {{0,-1},{0,1},{-1,0},{1,0}};
        int n,m;

        bool valid(int i, int j){
            if(i<0 || i>=n || j<0 || j>=m){
                return false;
            }
            return true;
        }

        void DFS(int si, int sj, vector<vector<char>>& grid){
            vis[si][sj] = true;
            for(int i = 0; i<4; i++){
                int ci = si + d[i].first;
                int cj = sj + d[i].second;
                if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] == '1'){
                    DFS(ci,cj,grid);
                }
            }
        }

        int numIslands(vector<vector<char>>& grid){
            n = grid.size();
            m = grid[0].size();
            int count = 0;
            memset(vis,false,sizeof(vis));
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    if(!vis[i][j] && grid[i][j] == '1'){
                        DFS(i,j,grid);
                        count++;
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
    cin >> n >> m; 

    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    Solution sol;
    cout << sol.numIslands(grid) << endl;

    return 0;
}
