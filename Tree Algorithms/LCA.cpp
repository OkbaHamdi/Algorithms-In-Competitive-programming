const           int L = log2(N)+1;
int po[L];
vector<int> adj[N];
int par[N][L];
int depth[N];
void work(){
    po[0]=1;
    for(int i=1;i<L;i++)po[i]=po[i-1]*2;
}
void dfs(int u, int p) {
    par[u][0] = p;
    for (int i = 1; i < L; i++) {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (auto v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}
