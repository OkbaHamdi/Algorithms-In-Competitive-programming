//implementaton with  struct
//commun version
typedef long long ll;
struct dsu{
     vector<ll> root, groupsize;

    dsu(ll n)
    {
        groupsize.resize(n + 1, 1);
        root.resize(n + 1);
        for (ll i = 1; i <=n; i++) root[i] = i;
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
// version to get min and max of the nodes easily

typedef long long ll;
struct dsu{
     vl root;
     vector<tuple<ll,ll,ll>>grp;

    dsu(ll n)
    {
        grp.resize(n + 1);
        root.resize(n + 1);

        for (ll i = 1; i <= n; i++) {
                root[i] = i;
                get<0>(grp[i])=1;
                get<1>(grp[i])=i;
                get<2>(grp[i])=i;
        }
    }

    ll find_root(ll u)  {return (root[u] == u) ? u : root[u] = find_root(root[u]);}
    void join(ll u,ll v){
        u = find_root(u);
        v = find_root(v);
        if(u==v)return;
        if (get<0>(grp[u])< get<0>(grp[v])) swap(u, v);
        root[v] = u;
        get<0>(grp[u]) +=get<0> (grp[v]);
        get<1>(grp[u])=min(get<1>(grp[u]),get<1>(grp[v]));
        get<2>(grp[u])=max(get<2>(grp[u]),get<2>(grp[v]));
    }

    bool together(ll u, ll v){return find_root(u)==find_root(v)?true:false;}
};
