#include <bits/stdc++.h>
using namespace std;
bool vis[105];
vector<int> adj_list[105];
int parent[105];
bool cycle;

void DFS(int source){
    vis[source] = true;
    for(int child : adj_list[source]){
        if(vis[child] && parent[source] != child){
                cycle = true;
            }
        if(!vis[child]){
            parent[child] = source;
            DFS(child);
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
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    cycle = false;
    for(int i = 0; i<n; i++){
        if(!vis[i]){
            DFS(i);
        }
    }
    // For printing parent
    // for(int i = 0; i<n; i++){
    //     cout << i << " parent: " << parent[i] << endl;
    // }
    if(cycle){
        cout << "Cycle Detected" << endl;
    }
    else{
        cout << "No Cycle" << endl;
    }
    return 0;
}