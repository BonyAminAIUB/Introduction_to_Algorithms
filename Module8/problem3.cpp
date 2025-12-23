#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y, steps;
};

int n, m;
vector<pair<int,int>> d = { {2,1}, {2,-1}, {-2,1}, {-2,-1},
                            {1,2}, {1,-2}, {-1,2}, {-1,-2}
                          };

bool valid(int x, int y){
    return x >=0 && x < n && y >=0 && y < m;
}

int knight_moves(int sx, int sy, int dx, int dy){
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<Node> q;
    q.push({sx, sy, 0});
    visited[sx][sy] = true;

    while(!q.empty()){
        Node curr = q.front(); q.pop();
        if(curr.x == dx && curr.y == dy){
            return curr.steps;
        }

        for(int i=0; i<8; i++){
            int nx = curr.x + d[i].first;
            int ny = curr.y + d[i].second;
            if(valid(nx, ny) && !visited[nx][ny]){
                visited[nx][ny] = true;
                q.push({nx, ny, curr.steps + 1});
            }
        }
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        int kx, ky, qx, qy;
        cin >> kx >> ky >> qx >> qy;
        cout << knight_moves(kx, ky, qx, qy) << endl;
    }

    return 0;
}
