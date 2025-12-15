// Find if Path Exists in Graph
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        vector<int>adj_list[200005];
        bool vis[200005];
        void DFS(int source){
            vis[source] = true;
            for(int child : adj_list[source]){
                if(!vis[child]){
                    DFS(child);
                }
            }
        }
        bool validPath(int n, vector<vector<int>>& edges, int source, int destination){
            for(int i=0; i<n; i++){
                adj_list[i].clear();
            }
            for(int i = 0; i<edges.size(); i++){
                int a = edges[i][0];
                int b = edges[i][1];
                adj_list[a].push_back(b);
                adj_list[b].push_back(a);
            }
            memset(vis,false,sizeof(vis));
            DFS(source);
            if(vis[destination] == true){
                return true;
            }
            else{
                return false;
            }
        }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;                
    int m;
    cin >> m;                
    
    vector<vector<int>> edges(m, vector<int>(2));
    for(int i=0; i<m; i++){
        cin >> edges[i][0] >> edges[i][1];
    }
    
    int source, destination;
    cin >> source >> destination;
    
    Solution sol;
    cout << (sol.validPath(n, edges, source, destination) ? "true" : "false") << endl;
    cout.flush();
    return 0;
}
