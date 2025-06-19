// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// bool isBipartite(int v, vector<int> adj[]) {
//     int color[v];   // where v is size of adj 
//     for(int i = 0; i < v; i++) {
//         color[i] = -1;
//     }
    
//     // Handle disconnected graph by checking each component
//     for(int i = 0; i < v; i++) {
//         if(color[i] == -1) {
//             queue<int> q;
//             q.push(i);
//             color[i] = 0;
            
//             while(!q.empty()) {
//                 int node = q.front();
//                 q.pop();
                
//                 for(auto it : adj[node]) {
//                     if(color[it] == -1) {
//                         color[it] = 1 - color[node]; // Assign opposite color
//                         q.push(it);
//                     }
//                     else if(color[it] == color[node]) {
//                         return false;
//                     }
//                 }
//             }
//         }
//     }
    
//     return true;
// }




// int main() {
//     // Example 1: A bipartite graph (a simple tree)
//     int v1 = 4;
//     vector<int> adj1[4];
    
//     // Adding edges for a tree: 0-1-2-3
//     adj1[0].push_back(1);
//     adj1[1].push_back(0);
    
//     adj1[1].push_back(2);
//     adj1[2].push_back(1);
    
//     adj1[2].push_back(3);
//     adj1[3].push_back(2);
    
//     cout << "Example 1 (Tree): ";
//     if(isBipartite(v1, adj1))
//         cout << "Graph is Bipartite" << endl;
//     else
//         cout << "Graph is not Bipartite" << endl;
    
//     // Example 2: A non-bipartite graph (odd cycle)
//     int v2 = 3;
//     vector<int> adj2[3];
    
//     // Adding edges for a triangle: 0-1-2-0
//     adj2[0].push_back(1);
//     adj2[1].push_back(0);
    
//     adj2[1].push_back(2);
//     adj2[2].push_back(1);
    
//     adj2[2].push_back(0);
//     adj2[0].push_back(2);
    
//     cout << "Example 2 (Triangle): ";
//     if(isBipartite(v2, adj2))
//         cout << "Graph is Bipartite" << endl;
//     else
//         cout << "Graph is not Bipartite" << endl;
    
//     return 0;
// }



#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int col, int color[], vector<int> adj[]) {
    color[node] = col;
    for(auto it: adj[node]) {
        if(color[it] == -1) {
            if(dfs(it, !col, color, adj) == false) {
                return false;
            }
        } else if(color[it] == col) {
            return false;
        }
    }
    return true;
}

bool isBipartite(int v, vector<int> adj[]) {
    int color[v];
    for(int i = 0; i < v; i++) {
        color[i] = -1;
    }

    for(int i = 0; i < v; i++) {
        if(color[i] == -1) {
            if(dfs(i, 0, color, adj) == false) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // Example 1: A bipartite graph (a simple tree)
    int v1 = 4;
    vector<int> adj1[4];
    
    // Adding edges for a tree: 0-1-2-3
    adj1[0].push_back(1);
    adj1[1].push_back(0);
    
    adj1[1].push_back(2);
    adj1[2].push_back(1);
    
    adj1[2].push_back(3);
    adj1[3].push_back(2);
    
    cout << "Example 1 (Tree): ";
    if(isBipartite(v1, adj1))
        cout << "Graph is Bipartite" << endl;
    else
        cout << "Graph is not Bipartite" << endl;
    
    // Example 2: A non-bipartite graph (odd cycle)
    int v2 = 3;
    vector<int> adj2[3];
    
    // Adding edges for a triangle: 0-1-2-0
    adj2[0].push_back(1);
    adj2[1].push_back(0);
    
    adj2[1].push_back(2);
    adj2[2].push_back(1);
    
    adj2[2].push_back(0);
    adj2[0].push_back(2);
    
    cout << "Example 2 (Triangle): ";
    if(isBipartite(v2, adj2))
        cout << "Graph is Bipartite" << endl;
    else
        cout << "Graph is not Bipartite" << endl;
    
    return 0;
}
