template<typename T>
vector<Point<T>>hull(vector<Point<T>>&v){
    vector<Point<T>>ans={v[0],v[1]};
    int n=v.size();
    for(int i=2;i<n;i++){
        while(ans.size()>1){
            auto b=ans.back();
            ans.ppb();
            auto a=ans.back();
            auto c=v[i];
            if(b.orient(c,a)>=0){
                ans.pb(b);
                break;
            }
        }
        ans.pb(v[i]);
    }
    return ans;
}
template<typename T>
vector<Point<T>>convex_hull(vector<Point<T>>v){
    sort(all(v),[](Point<T>&a,Point<T>&b){return(a.x==b.x)?(a.y<b.y):(a.x<b.x);});
    auto v1=hull(v);
    sort(all(v),[](Point<T>&a,Point<T>&b){return(a.x==b.x)?(a.y>b.y):(a.x>b.x);});
    auto v2=hull(v);
    vector<Point<ll>>ans=v1;
    for(int i=1;i<v2.size();i++){
        auto x=v2[i];
        if(x==ans[0])break;
        ans.pb(x);
    }
    return ans;
}
