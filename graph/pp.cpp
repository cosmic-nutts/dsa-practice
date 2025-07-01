#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dijk(int v, vector<pair<int, int>> adj[], int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v, 1e9);
    
    pq.push({0, src});  // {distance, node}
    dist[src] = 0;
    
    while(!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(dis > dist[node]) continue;  // Skip if we already found a better path
        
        for(auto it : adj[node]) {
            int adjnode = it.first;
            int wt = it.second;
            
            if(dis + wt < dist[adjnode]) {
                dist[adjnode] = dist[node] + wt;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }
    return dist;
}

int main() {
    // Predefined graph with 6 vertices (0 to 5)
    int v = 6;
    vector<pair<int, int>> adj[v];
    
    // Adding edges: {adjacent_node, weight}
    // Edge from 0 to 1 with weight 2
    adj[0].push_back({1, 2});
    // Edge from 0 to 2 with weight 4
    adj[0].push_back({2, 4});
    // Edge from 1 to 2 with weight 1
    adj[1].push_back({2, 1});
    // Edge from 1 to 3 with weight 7
    adj[1].push_back({3, 7});
    // Edge from 2 to 4 with weight 3
    adj[2].push_back({4, 3});
    // Edge from 3 to 5 with weight 1
    adj[3].push_back({5, 1});
    // Edge from 4 to 3 with weight 2
    adj[4].push_back({3, 2});
    // Edge from 4 to 5 with weight 5
    adj[4].push_back({5, 5});
    
    // Source vertex
    int src = 0;
    
    // Run Dijkstra's algorithm
    vector<int> distances = dijk(v, adj, src);
    
    // Print the shortest distances from source to all vertices
    cout << "Shortest distances from source vertex " << src << ":\n";
    for(int i = 0; i < v; i++) {
        cout << "To vertex " << i << ": ";
        if(distances[i] == 1e9)
            cout << "Infinity (Not reachable)";
        else
            cout << distances[i];
        cout << endl;
    }
    
    return 0;
}
