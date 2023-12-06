typedef         long long ll;
const           int MOD=1000000007;
int mul(int u , int v, int mod=MOD){
    return ((u%mod)*(v%mod))%mod;
}
int add(int u, int v, int mod=MOD){
    return ((u%mod)+(v%mod)+mod)%mod;
}
int sub(int u, int v , int mod=MOD){
    return ((u%mod)-(v%mod)+mod)%mod;
}
struct Matrix {
    int r,c;
    vector<vector<int>>mat;
    Matrix(int n,int m){
        r=n;
        c=m;
        mat.resize(r,vector<int>(c,0));
    }
};
Matrix matMul(Matrix a,Matrix b){
    int r=a.r,c=b.c;
    Matrix ans(r,c);
    for(int i=0;i<r;i++)
        for (int j=0;j<c;j++)
            for(int k=0;k<a.c;k++)
                ans.mat[i][j]=add(mul(a.mat[i][k],b.mat[k][j]),ans.mat[i][j]);// ops modulo
    return ans;
}
Matrix matPow(Matrix base, ll p){
    int r=base.r,c=base.c;
    Matrix ans(r,c);
    for (int i=0;i<r; i++)for (int j=0;j<c;j++)ans.mat[i][j]=(i==j);
    while(p){
        if(p&1)ans=matMul(ans, base);
        base=matMul(base, base);
        p>>= 1;
    }
    return ans;
}
