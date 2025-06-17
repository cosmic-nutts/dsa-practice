#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsGraph(int first, vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size();
    vector<int> vis(n, 0);  // visited array
    queue<int> q;
    vis[first] = 1;
    q.push(first);
    vector<int> bfs;

    while(!q.empty()) {
        int f = q.front();
        q.pop();
        bfs.push_back(f);
        
        for(int i = 0; i < n; i++) {
            if(adjMatrix[f][i] == 1 && !vis[i]) {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    return bfs;
}

int main() {
    // Define the size of the adjacency matrix
    const int n = 5;
    
    // Create and initialize the adjacency matrix
    vector<vector<int>> adjMatrix = {
        {0, 1, 0, 0, 1},  // Node 0 connected to nodes 1 and 4
        {1, 0, 1, 0, 0},  // Node 1 connected to nodes 0 and 2
        {0, 1, 0, 1, 0},  // Node 2 connected to nodes 1 and 3
        {0, 0, 1, 0, 1},  // Node 3 connected to nodes 2 and 4
        {1, 0, 0, 1, 0}   // Node 4 connected to nodes 0 and 3
    };
    
    // Start BFS from vertex 0
    vector<int> bfs = bfsGraph(0, adjMatrix);
    
    // Print the BFS traversal
    cout << "BFS traversal: ";
    for(int i : bfs) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
