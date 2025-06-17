#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited) {
    visited[node] = 1;
    for(auto it : adjList[node]) {
        if(!visited[it]) {
            dfs(it, adjList, visited);
        }
    }
}

int findProvinces(vector<vector<int>>& adjList, int v) {
    vector<int> visited(v, 0);
    int count = 0;
    
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            count++;
            dfs(i, adjList, visited);
        }
    }
    
    return count;
}

int main() {
    int v = 5; // Number of vertices
    
    // Directly define adjacency list
    vector<vector<int>> adjList = {
        {1, 2},     // Node 0 is connected to 1, 2
        {0},        // Node 1 is connected to 0
        {0},        // Node 2 is connected to 0
        {4},        // Node 3 is connected to 4
        {3}         // Node 4 is connected to 3
    };
    
    // Find number of provinces
    int provinces = findProvinces(adjList, v);
    cout << "Number of provinces: " << provinces << endl;
    
    return 0;
}
