#include <bits/stdc++.h>
using namespace std;
char grid[1001][1001];
bool visited[1001][1001];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
int cnt;
bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }
    return true;
}

void DFS(int si, int sj){
    visited[si][sj] = true;
    cnt++;
    for(int i = 0; i<4; i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci,cj) == true && !visited[ci][cj] && grid[ci][cj] == '.'){
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
    memset(visited,false,sizeof(visited));
    vector<int> v;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!visited[i][j] && grid[i][j] == '.'){
                cnt = 0;
                DFS(i,j);
                v.push_back(cnt);
            }
        }  
    }
    if(v.empty()){
        cout << "0" << endl;
    }
    else{
        sort(v.begin(), v.end());
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}