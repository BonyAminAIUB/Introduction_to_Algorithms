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

int DFS(int si, int sj){
    visited[si][sj] = true;
    int cnt = 1; 
    for(int i = 0; i < 4; i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci,cj) && !visited[ci][cj]){
            cnt += DFS(ci,cj);
        }
    }
    return cnt;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    memset(visited, false, sizeof(visited));

    int min_area = INT_MAX;
    bool component = false;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && grid[i][j] == '.'){
                int area = DFS(i,j);
                min_area = min(min_area, area);
                component = true;
            }
        }
    }

    if(component){
        cout << min_area << endl;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}
