#include <iostream>
#include <vector>
using namespace std;


void creategraph(int n,int m){
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Print adjacency list
    for(int i=1;i<=n;i++){
        cout << i << ": ";
        for(int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    creategraph(n,m);
    return 0;
}






