#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
bool visited[105][105];
int n, m;

vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){
        return false;
    }
    if(grid[i][j] == '-'){
        return false;  
    }
    return true;
}

void DFS(int si, int sj){
    visited[si][sj] = true;
    for(auto [dx, dy] : d){
        int ci = si + dx;
        int cj = sj + dy;
        if(valid(ci,cj) && !visited[ci][cj]){
            DFS(ci, cj);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    int si, sj, di, dj;
    cin >> si >> sj;
    cin >> di >> dj;

    memset(visited, false, sizeof(visited));

    if(grid[si][sj] == '-' || grid[di][dj] == '-'){
        cout << "NO" << endl;
        return 0;
    }

    DFS(si, sj);

    if(visited[di][dj]){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
