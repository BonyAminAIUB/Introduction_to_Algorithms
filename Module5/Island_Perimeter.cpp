// Island Perimeter Leetcode problem
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool vis[105][105];
        int count;
        vector<pair<int,int>> d = {{0,1},{0,-1},{1,0},{-1,0}};
        int n,m;
        bool valid(int i, int j){
            if(i < 0 || i >= n || j < 0 || j >= m){
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
                    count++;
                }
                else if(valid(ci,cj) == true && grid[ci][cj] == 0){
                    count++;
                }
                else if(valid(ci,cj) == true && !vis[ci][cj] && grid[ci][cj] == 1){
                    DFS(ci,cj,grid);
                }
            }
        }
        int islandPerimeter(vector<vector<int>>& grid){
            count = 0;
            n = grid.size();
            m = grid[0].size();
            memset(vis,false,sizeof(vis));
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    if(!vis[i][j] && grid[i][j] == 1){
                        DFS(i,j,grid);
                    }
                }
            }
            return count;
        }
};
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    Solution sol;
    cout << sol.islandPerimeter(grid) << endl;
    return 0;
}