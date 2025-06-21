#include <iostream>
using namespace std;



vector<int> bfs(int v;int node;vector<int>adj){
    queue<int>q;
    int vis[v]={0};
    vector<int>ans;

    vis[0]=1;
    q.push(0);

    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;8
                q.push(it);
            }
        }
    }


}

int main() {
    
    return 0;
}