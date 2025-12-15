// Count sub islands
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        bool vis[505][505];
        vector<pair<int,int>> d = {{0,-1},{0,1},{-1,0},{1,0}};
        int n,m;
        bool flag;

        bool valid(int i, int j){
            if(i<0 || i>=n || j<0 || j>=m){
                return false;
            }
            return true;
        }

        void DFS(int si, int sj, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
            vis[si][sj] = true;
            if(grid1[si][sj] == 0){
                flag = false;
            }
            for(int i = 0; i<4; i++){
                int ci = si + d[i].first;
                int cj = sj + d[i].second;
                if(valid(ci,cj) && !vis[ci][cj] && grid2[ci][cj] == 1){
                    DFS(ci,cj,grid1,grid2);
                }
            }
        }

        int countSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2){
            int count = 0;
            n = grid1.size();
            m = grid1[0].size();
            memset(vis,false,sizeof(vis));
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    if(!vis[i][j] && grid2[i][j] == 1){
                        flag = true;
                        DFS(i,j,grid1,grid2);
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

    vector<vector<int>> grid1(n, vector<int>(m));
    vector<vector<int>> grid2(n, vector<int>(m));

    // input grid1
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid1[i][j];
        }
    }

    // input grid2
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid2[i][j];
        }
    }

    Solution sol;
    cout << sol.countSubIsland(grid1, grid2) << "\n";

    return 0;
}
