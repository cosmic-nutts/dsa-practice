#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// vector<int> toposort(int v, vector<int> adj[]){
//     vector<int> indegree(v, 0);
//     for(int i=0; i<v; i++){
//         for(auto it: adj[i]){
//             indegree[it]++;
//         }
//     }

//     queue<int> q;
//     for(int i=0; i<v; i++){
//         if(indegree[i]==0){
//             q.push(i);
//         }
//     }
//     vector<int> topo;
//     while(!q.empty()){
//         int node=q.front();
//         q.pop();
//         topo.push_back(node);
//         for(auto it:adj[node]){
//             indegree[it]--;
//             if(indegree[it]==0){
//                 q.push(it);
//             }
//         }
//     }
//     return topo;
// }



bool toposort(int v,vector<int>adj[]){
    vector<int> indegree(v, 0);
    queue<int>q;

    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            indegree[it]++;

        }
    }

    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    // vector<int>topo;
    int cnt=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        // topo.push_back(node);
        cnt++;
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(cnt==v){
        return false;
    }
    return true;
}

int main() {
    int v = 6;
    int e = 6;
    vector<int> adj[v];
    
    // Adding edges to the graph
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    
    bool result = toposort(v, adj);
    
    if(result) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph doesn't contain a cycle" << endl;
    }
    
    return 0;
}
