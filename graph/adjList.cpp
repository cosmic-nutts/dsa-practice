#include <iostream>
#include <vector>

using namespace std;


int main() {
    int r,col;
    cin>>r>>col;
    vector<vector<int>> adj(r+1);
    for(int i=0;i<col;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}