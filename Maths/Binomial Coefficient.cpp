//O(r Log n) 
int C(int n,int r){
    int p=1,k=1;
    if(n-r<r)r=n-r;
    if(r!=0){
        while(r){
            p*=n,k*=r;
            int m =__gcd(p,k);
            p/=m,k/=m,n--,r--;
        }
    }
    return p;
}

//with DP
int c[N][K] ;
void work(){
    c[0][0] = 1;
    for (int n = 1; n < N; ++n) {
        c[n][0] = c[n][K-1] = 1;
        for (int k = 1; k < 8; ++k)
        c[n][k] = (c[n - 1][k - 1] + c[n - 1][k]);
    }
}
int C(int n,int k){
    if(k>n)return 0;
    return c[n][k];
}
