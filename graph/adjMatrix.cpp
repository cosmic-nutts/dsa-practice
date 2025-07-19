#include <iostream>
using namespace std;

int main() {
    int row, col;
    cin>>row>>col;
    //1based indexing
    int adj[row+1][col+1];
    for(int i=0;i<col;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;

    }

    cout << "Adjacency Matrix:" << endl;
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= row; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }


    
    return 0;
}





