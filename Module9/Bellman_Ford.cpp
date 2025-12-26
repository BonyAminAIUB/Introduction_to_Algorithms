#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int a,b,c;
        Edge(int a, int b, int c){
            this->a = a;
            this->b = b;
            this->c = c;
        }
};
int dis[1005]; 
vector<Edge> edge_list;
int n,e;

void bellman_ford(int src){
    for(int i = 0; i < n; i++){
        dis[i] = INT_MAX;
    }
    dis[src] = 0;
    for(int i = 0; i<n-1; i++){
        for(auto ed : edge_list){
            int a, b,c;
            a = ed.a;
            b = ed.b;
            c = ed.c;
            if(dis[a] != INT_MAX && dis[a] + c < dis[b]){
                dis[b] = dis[a] + c;
            }
        }
    }
}

int main(){
    cin >> n >> e;
    
    while(e--){
        int a,b,c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a,b,c));
    }
    int src;
    cin >> src; 
    bellman_ford(src);

    for(int i = 0; i < n; i++){
        cout << i << " -> ";
        if(dis[i] == INT_MAX){
            cout << "INF";
        }
        else{
            cout << dis[i];
        }
        cout << "\n";
    }
    return 0;
}