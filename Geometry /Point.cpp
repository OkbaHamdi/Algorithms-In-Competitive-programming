struct point{
    int x,y;
    point(int kx=0,int ky=0){
        x=kx;
        y=ky;
    }
};
 bool colin(point a,point b,point c){
        ld test=a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
        if(test==0)return 1;
        return 0;
}
vector<point>f(point a,point b,vector<point>v){
    vector<point>ans;
    for(auto c:v){
        if(!colin(a,b,c))ans.pb(c);
    }
    return ans;
}
// segments of n points
bool burn(vector<point>v,int n){
    if(v.size()<=2*n)return 1;
    if(n==0)return 0;
    bool ok=0;
    for(int i=0;i<2;i++)for(int j=i+1;j<=i+2;j++){
        auto x=f(v[i],v[j],v);
        ok=burn(x,n-1);
    }
    return ok;

}
