vector<vector<int>>g;
vector<bool>vis,anc;
//directed graph
bool detect_cycle(int node){
    vis[node]=1;
    anc[node]=1;
    for(auto x:g[node]){
        if(vis[x]&&anc[x])return 1;
        if(!vis[x]&&detect_cycle(x))return 1;
    }
    anc[node]=0;
    return 0;
}
