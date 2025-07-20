vector<int>dfs(int start,vector<int>adj[]){
    vector<int>vis(adj->size(), 0);
    vector<int>result;
    vis[start] = 1;
    result.push_back(start);

    for(auto it: adj[start]){
        if(!vis[it]){
            vis[it] = 1;
            dfs(it, adj);
        }

    }
}