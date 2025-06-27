#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int v, vector<int>& vis, vector<vector<int>>& matrix) {
    vis[node] = 1;
    for(int i = 0; i < v; i++) {
        if(matrix[node][i] == 1 && !vis[i]) {
            dfs(i, v, vis, matrix);
        }
    }
}

int numprovince(int v, vector<vector<int>>& matrix) {
    vector<int> vis(v, 0);
    int count = 0;

    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            count++;
            dfs(i, v, vis, matrix);
        }
    }
    
    return count; // Missing return statement
}

int main() {
    // Example usage
    int v = 3;
    vector<vector<int>> matrix = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    
    int result = numprovince(v, matrix);
    cout << "Number of provinces: " << result << endl;
    
    return 0;
}
