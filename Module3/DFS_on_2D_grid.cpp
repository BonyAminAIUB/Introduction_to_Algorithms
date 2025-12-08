#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
bool visited[105][105];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;

bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}
void DFS(int si, int sj){
    visited[si][sj] = true;
    for(int i = 0; i<4; i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci,cj) == true && !visited[ci][cj]){
            DFS(ci,cj);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    int si,sj;
    cin >> si >> sj;
    memset(visited,false,sizeof(visited));
    DFS(si,sj);
    return 0;
}