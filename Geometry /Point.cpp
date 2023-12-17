template<typename T>
struct Point {
    T x,y;
    Point(T xx=0,T yy=0):x(xx),y(yy){}
    //cin
    friend istream& operator>>(istream& input, Point<T>& p) {
        input>>p.x>>p.y;
        return input;
    }
    //cout
    friend ostream& operator<<(ostream& output, const Point<T>& p) {
        output<<"("<<p.x<<","<<p.y<<")";
        return output;
    }
    Point<T> operator+(Point<T>p){return{x+p.x, y+p.y};}
    Point<T> operator-(Point<T>p){return{x-p.x, y-p.y};}
    Point<T> operator*(Point<T>p){return{x*p.x-y*p.y, x*p.y+y*p.x};}
    Point<T> operator*(T p){return{x*p, y*p};}
    Point<T> operator/(T p){return{x/p, y/p};}
    bool operator==(const Point<T> &p)const{return x==p.x && y == p.y;}
    bool operator!=(const Point<T> &p)const{return !(*this == p);}
    bool operator<(const Point<T> &p)const{return x<p.x||(x==p.x&&y<p.y);}
    bool operator>(const Point<T> &p)const{return x>p.x||(x==p.x&&y>p.y);}
    T norm(){return x*x+y*y;}
    T norm(Point<T> p){return abs(p.x-x)*abs(p.x-x) + abs(p.y-y)*abs(p.y-y);}
    T dot(Point<T> p){return x*p.x + y*p.y;}//a*cos(O)b
    T cross(Point<T> p){return x*p.y-y*p.x;}
    T orient(Point<T> b,Point<T> c){return (b-*this).cross(c-*this);}//cross 3 points
    ld dist(){return sqrt(norm());}
    ld dist(Point<T> p){return sqrt(norm(p));}
    // slope
    friend int direction(Point<T>a,Point<T>b,Point<T> c){
        ld val=(b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
        if(val==0)return 0;//collinear
        if(val<0)return 2;//Anti-clockwise direction c is left (or up)
        return 1;// Clockwise direction c is right (or down)
    }
    // angle bAc
    friend ld angle(Point<T>a,Point<T>b,Point<T>c) {
        ld ux=b.x-a.x;
        ld uy=b.y-a.y;
        ld vx=c.x-a.x;
        ld vy=c.y-a.y;
        return acos((ux*vx+uy*vy)/sqrt((ux*ux+uy*uy)*(vx*vx+vy*vy)));
    }
};
