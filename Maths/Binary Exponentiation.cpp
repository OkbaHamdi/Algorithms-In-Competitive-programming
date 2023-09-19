int binexp(int a, int k,int mod=MOD){
    int ans = 1;
    while (k){
        if (k & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        k >>= 1;
    }
    return ans;
}
int inv(int n){
    return binexp(n,MOD-2);
}
int mul(int u , int v, int mod=MOD){
    return ((u%mod)*(v%mod))%mod;
}
int add(int u, int v, int mod=MOD){
    return ((u%mod)+(v%mod)+mod)%mod;
}
 
int sub(int u, int v , int mod=MOD){
    return ((u%mod)-(v%mod)+mod)%mod;
}
