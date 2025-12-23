#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;
};

int n, m;
vector<string> grid;
vector<pair<int,int>> moves = {{0,1},{0,-1},{-1,0},{1,0}}; 

bool valid(int x, int y){
    return x>=0 && x<n && y>=0 && y<m && (grid[x][y]=='.' || grid[x][y]=='D');
}

int main(){
    cin >> n >> m;
    grid.resize(n);
    Node start, dest;
    
    for(int i=0;i<n;i++){
        cin >> grid[i];
        for(int j=0;j<m;j++){
            if(grid[i][j]=='R') start = {i,j};
            if(grid[i][j]=='D') dest = {i,j};
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m,false));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    queue<Node> q;

    q.push(start);
    visited[start.x][start.y] = true;

    bool found = false;
    while(!q.empty() && !found){
        Node cur = q.front(); q.pop();
        for(auto mv : moves){
            int nx = cur.x + mv.first;
            int ny = cur.y + mv.second;
            if(valid(nx,ny) && !visited[nx][ny]){
                visited[nx][ny] = true;
                parent[nx][ny] = {cur.x, cur.y};
                if(nx == dest.x && ny == dest.y){
                    found = true;
                    break;
                }
                q.push({nx,ny});
            }
        }
    }

    if(found){
        int x = dest.x, y = dest.y;
        while(!(x == start.x && y == start.y)){
            pair<int,int> p = parent[x][y];
            if(grid[x][y]=='.') grid[x][y]='X';
            x = p.first;
            y = p.second;
        }
    }
    for(int i=0;i<n;i++){
        cout << grid[i] << endl;
    }
    return 0;
}
