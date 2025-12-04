#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000];
bool visited[1000];
// Overall BFS er complexity O(V + E)   
//V -> means vertices and E -> means edges
void BFS(int source){
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while(!q.empty()){ // O(V)
        int par = q.front();
        q.pop();
        cout << par << " ";
        for(int child : adj_list[par]){ // O(E)
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
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
    for(int i = 0; i<n; i++){  //  disconnected graph er jonno
        if(!visited[i]){
            BFS(i);
        }
    }
    return 0;
}