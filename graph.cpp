#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<vector<int>> adj, bool visited[]){
    
}

void dfs_main(vector<vector<int>> adj, int n){
    bool visited[n] = {false};
    for(int i = 0; i < n; i++){
        if(visited[i] == true){
            dfs(adj, visited);
        }
    }
}

int main(){

    vector<vector<int>> adj;
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 9);
    addEdge(adj, 9, 8);
    addEdge(adj, 1, 8);
    addEdge(adj, 8, 7);
    addEdge(adj, 7, 10);
    addEdge(adj, 7, 11);
    addEdge(adj, 10, 11);
    addEdge(adj, 7, 3);
    addEdge(adj, 7, 6);
    addEdge(adj, 3, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 3, 2);
    addEdge(adj, 3, 4);

    int n = adj.size();

    return 0;
}