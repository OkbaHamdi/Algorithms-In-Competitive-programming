//use point.cpp and line.cpp
template<typename T>
struct polygon{
    int n;
    vector<Point<T>>poly;
    polygon(int sz){
        n=sz;
        poly.clear();
        poly.resize(sz);
    }
    bool find(Point<T>p){
        for(auto x:poly)if(x==p)return 1;
        return 0;
    }
    int checkInside(Point<T>p){
        // 0 outside
        // 1 boundary
        // 2 inside
        ld sum=0;
        for(int i=0;i<n;i++){
            line<T>side(poly[i],poly[(i+1)%n]);
            if(p.orient(side.A,side.B)==0&&onLine(side,p))return 1; //colinear and in line ->boundary
            if(p.orient(side.A,side.B)<0)sum-=angle(p,side.A,side.B);
            else sum+=angle(p,side.A,side.B);
        }
        return (fabs(2*PI-fabs(sum))<eps)*2;
    }
    ld area(){
        //area=l+b/2-1
        ld ans=0;
        for(int i=0;i<n;i++){
            ans+=poly[i].cross(poly[(i+1)%n]);
        }
        return abs(ans/2);
    }
};
