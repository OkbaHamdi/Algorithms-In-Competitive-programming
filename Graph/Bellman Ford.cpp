typedef long long ll;
const ll INF=1e18;
// choose any size
ll graph[505][505];
ll dis[505];
void Bellman_Ford(ll x,ll n){
    for (ll i = 0; i < n; i++) dis[i] = INF;
    dis[x] = 0;
    for (ll i = 1; i <= n-1; i++) {
            for(ll t=0;t<n;t++){
                for (ll j=0;j<n;j++) {
                    if(graph[t][j]>0)
                    dis[j] = min(dis[j], dis[t]+graph[t][j]);
                            }
                         }
                     }
                }
