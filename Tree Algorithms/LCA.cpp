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

int getlca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int l = depth[u] - depth[v];
    for (int i = L - 1; i >= 0; i--) {
        if (po[i] <= l) {
            u = par[u][i];
            l -= po[i];
        }
    }
    for (int i = L - 1; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    if (u != v) {
        u = par[u][0];
    }
    return u;
}
int getdist(int u, int v) { return depth[u] + depth[v] - 2 * depth[getlca(u, v)]; }
