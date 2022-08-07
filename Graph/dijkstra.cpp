typedef long long ll;
typedef pair<ll,ll>pl;
const ll N=2e5+5;
vector<pl> g[N];
bool vis[N];
vl dist(N,INF);
void dijkstra(){
    set<pl> pq;
    pq.insert({0, 1});
    while (!pq.empty()){
        int a = pq.begin()->second;
        pq.erase(pq.begin());
        if (vis[a]) continue;
        vis[a]=1;
        for (auto e : g[a]){
            ll b=e.first;
            int c=e.second;
            if (dist[a]+c< dist[b]){
                dist[b] = dist[a] + c;
                pq.insert({dist[b], b});
            }
        }
    }
}
//g[node1]={node2,weight}
