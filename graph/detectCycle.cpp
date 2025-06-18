#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//bfs
bool detect(int src,vector<int>adj[],int vis[]){
    vis[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto it: adj[node]){
            if(!vis[it] ){ 
                vis[it]=1;
                q.push({it,node});
            }
            else if(parent !=it){
                return true;
            }
                
        }
    }
    return false;
}





bool isCycle(int v, vector<int>adj[]){     //where v is size of adjancy 
    int vis[v]={0};
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(detect(i,adj,vis)){
                return true;
            }
        }
    }
    return false;




}


int main() {
    // Example graph with a cycle
    int V = 5;
    vector<int> adj[V];
    
    // Adding edges to create a graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(1);  // This creates a cycle: 1 -> 2 -> 3 -> 4 -> 1
    
    // Check if the graph contains a cycle
    if(isCycle(V, adj)) {
        cout << "Graph contains cycle" << endl;
    } else {
        cout << "Graph does not contain cycle" << endl;
    }
    
    // Example graph without a cycle
    vector<int> adj2[V];
    adj2[0].push_back(1);
    adj2[1].push_back(2);
    adj2[2].push_back(3);
    adj2[3].push_back(4);
    
    if(isCycle(V, adj2)) {
        cout << "Graph contains cycle" << endl;
    } else {
        cout << "Graph does not contain cycle" << endl;
    }
    
    return 0;
}
