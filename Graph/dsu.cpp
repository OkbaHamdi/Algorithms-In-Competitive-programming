//struct
typedef long long ll;
struct dsu{
     vector<ll> root, groupsize;

    dsu(ll n)
    {
        groupsize.resize(n + 1, 1);
        root.resize(n + 1);
        for (ll i = 1; i < n; i++) root[i] = i;
    }

    ll find_root(ll u)  {return (root[u] == u) ? u : root[u] = find_root(root[u]);}
    void join(ll u,ll v){
        u = find_root(u);
        v = find_root(v);
        if (groupsize[u] < groupsize[v]) swap(u, v);
        root[v] = u;
        groupsize[u] += groupsize[v];
    }

    bool together(ll u, ll v){return find_root(u)==find_root(v)?true:false;}
};
