#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000];
bool visited[1000];
int level[1000];

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
    int source,destination;
    cin >> source >> destination;
    BFS(source);
    // for(int i = 0; i<n; i++){
    //     cout << i << " -> " << level[i] << endl;
    // }
    cout << level[destination] << endl;
    return 0;
}