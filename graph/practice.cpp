#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    // Priority queue (min heap)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    vector<int> dis(V);
    for(int i = 0; i < V; i++) {
        dis[i] = 1e9;
    }
    dis[S] = 0;
    pq.push({0, S});

    while(!pq.empty()) {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]) {
            int adjnode = it[0];
            int edgewt = it[1];
            if(distance + edgewt < dis[adjnode]) {
                dis[adjnode] = distance + edgewt;
                pq.push({dis[adjnode], adjnode});
            }
        }
    }
    return dis;
}

// Driver Code
int main() {
    int V = 5; // Number of vertices in the graph
    vector<vector<int>> adj[V];
    
    // Adding edges to the graph
    // Format: {adjacent node, weight}
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 1});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 4});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 4});
    adj[2].push_back({3, 3});
    adj[3].push_back({0, 1});
    adj[3].push_back({2, 3});
    adj[3].push_back({4, 1});
    adj[4].push_back({1, 5});
    adj[4].push_back({3, 1});
    
    int S = 0; // Source vertex
    
    vector<int> res = dijkstra(V, adj, S);
    
    cout << "Shortest distances from source " << S << ":\n";
    for(int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << res[i] << endl;
    }
    
    return 0;
}
