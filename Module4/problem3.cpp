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
        if(valid(ci,cj) == true && !visited[ci][cj] && grid[ci][cj] != '#'){
            DFS(ci,cj);
        }
    }
}
int main(){
    cin >> n >> m;
    int source1 = -1, source2 = -1;
    int destination1 = -1, destination2 = -1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                source1 = i;
                source2 = j;
            }
            if(grid[i][j] == 'B'){
                destination1 = i;
                destination2 = j;
            }
        }
    }
    if(source1 == -1 || source2 == -1){
        cout << "NO" << endl;
    }
    else{
        memset(visited,false,sizeof(visited));
        DFS(source1,source2);
        if(visited[destination1][destination2] == true){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}