#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid) {
    vis[i][j] = 1;
    queue<pair<int, int>> q;
    q.push({i, j});
    int m = grid.size();
    int n = grid[0].size();

    while(!q.empty()) {  // Fixed: added parentheses
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for(int delrow = -1; delrow <= 1; delrow++) {
            for(int delcol = -1; delcol <= 1; delcol++) {
                int nrow = i + delrow;
                int ncol = j + delcol;
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

int noOfIslands(vector<vector<char>>& grid) {  // Fixed: added closing angle bracket
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> vis(row, vector<int>(col, 0));  // Fixed: changed n to row
    int count = 0;
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(!vis[i][j] && grid[i][j] == '1') {
                count++;
                bfs(i, j, vis, grid);
            }
        }
    }
    return count;
}

int main() {
    // Create a sample grid representing islands (1) and water (0)
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    
    // Print the grid
    cout << "Grid representation (1: land, 0: water):" << endl;
    for (const auto& row : grid) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    
    // Count the number of islands
    int islands = noOfIslands(grid);
    
    cout << "Number of islands: " << islands << endl;
    
    return 0;
}
