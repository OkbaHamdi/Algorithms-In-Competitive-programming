vector<bool> prime(N+1,0) ;
void sieve(){
    for (ll p=2; p*p<=N;p++)
        if (prime[p]==1)for (ll i = p * p; i <= N; i += p)prime[i]=0;
}
