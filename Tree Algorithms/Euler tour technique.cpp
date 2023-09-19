vector<vector<int>> g;
vector<int>nodes,start,ending;
int ti = -1;
void dfs(int u, int p) {
    nodes.pb(u);
    start[u]=++ti;
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs(v, u);

    }
    ending[u]=ti;
}
