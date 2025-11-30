// Adjacency Matrix Implementation for undirected graph
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin >> n >> e;
    int adj_mat[n][n];

    // sob matrix er value 0 kore dite hobe
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<n; j++){
    //         adj_mat[i][j] = 0;
    //     }
    // }
    // initially sob gulo value 0 kore dite ekta shortcut ache
    memset(adj_mat,0,sizeof(adj_mat));

    // same col and row er value 1 kore dite hobe
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i == j){
                adj_mat[i][j] = 1;
            } 
        }
    }

    // graph er value input 
    while(e--){
        int a,b;
        cin >> a >> b;
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1; // for undirected graph
    }
    
    // adjacency matrix print
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}