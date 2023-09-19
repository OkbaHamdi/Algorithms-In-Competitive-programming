//sparse table
vector<vector<int>>st;
// function
inline int f(int x, int y) { return __gcd(x, y); }
//creation
void build(int n){
    st.clear();
    int K = 32 - __builtin_clz(n);
    st.resize(n, vector<int>(K + 1));
    for (int i = 0; i < n; i++) cin >> st[i][0];
    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

// query the range [l, r], l and r are inclusive
int query(int l, int r){
    int j = 31 - __builtin_clz(r-l+1);
    int ans = f(st[l][j], st[r - (1 << j) + 1][j]);
    return ans;
}
