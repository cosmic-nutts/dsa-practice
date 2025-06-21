#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, int vis[], vector<int> adj[], stack<int>& st) {
    vis[node] = 1;
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}

vector<int> toposort(int v, vector<int> adj[]) {
    int vis[v] = {0};
    stack<int> st;
    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }

    vector<int> ans;
    while(!st.empty()) {
        int x = st.top();
        st.pop();
        ans.push_back(x);
    }
    return ans;
}

int main() {
    // Example: Directed Acyclic Graph with 6 vertices
    int v = 6;
    vector<int> adj[v];
    
    // Adding edges to the graph
    // 5 -> 0
    // 4 -> 0
    // 4 -> 1
    // 3 -> 1
    // 2 -> 3
    // 5 -> 2
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[3].push_back(1);
    adj[2].push_back(3);
    adj[5].push_back(2);
    
    vector<int> result = toposort(v, adj);
    
    cout << "Topological Sort: ";
    for(int node : result) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}
