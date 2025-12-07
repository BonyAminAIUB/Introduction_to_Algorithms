#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000];
bool visited[1000];
int level[1000];
int parent[1000];

void BFS(int source){
    queue<int> q;
    q.push(source);
    visited[source] = true;
    level[source] = 0;
    while(!q.empty()){
        int par = q.front();
        q.pop();

        for(int child : adj_list[par]){
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }
}

int main(){
    int n,e;
    cin >> n >> e;
    while(e--){
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(visited,false,sizeof(visited));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));
    int source,destination;
    cin >> source >> destination;
    BFS(source);

    vector<int> path;
    int node = destination;
    while(node != -1){
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(),path.end());
    for(int i : path){
        cout << i << " ";
    }
    return 0;
}