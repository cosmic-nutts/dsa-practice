#include <iostream>
#include <vector>

using namespace std;

void dfs(int sr,int sc,int initialcolor,vector<vector<int>>& ans,int delrow[],int delcol[],vector<vector<int>>& img,int newcolor){
    ans[sr][sc]=newcolor;
    int n=img.size();
    int m=img[0].size();
    for(int i=0;i<4;i++){
        int nrow=sr+ delrow[i];
        int ncol=sc + delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0  && ncol<m && img[nrow][ncol]==initialcolor && ans[nrow][ncol]!=newcolor){
            dfs(nrow,ncol,initialcolor,ans,delrow,delcol,img,newcolor);
        }

    }


}


vector<vector<int>>floodfill(vector<vector<int>>& img,int sr,int sc,int newcolor){
    int initialcolor=img[sr][sc]; //where sr and sc are source row and source col respectively
    vector<vector<int>>ans=img;
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    dfs(sr,sc,initialcolor,ans,delrow,delcol,img,newcolor);
    return ans;
}



int main() {
    // Create a sample image grid
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    
    // Print original image
    cout << "Original Image:" << endl;
    for(int i = 0; i < image.size(); i++) {
        for(int j = 0; j < image[0].size(); j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    
    // Apply flood fill starting at position (1,1) with new color 2
    int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>> result = floodfill(image, sr, sc, newColor);
    
    // Print updated image
    cout << "\nAfter Flood Fill (starting at position (" << sr << "," << sc << ") with color " << newColor << "):" << endl;
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}