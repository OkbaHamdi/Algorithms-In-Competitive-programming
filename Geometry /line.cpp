//use point.cpp
template<typename T>
struct line{
    Point<T>A,B;
    line(Point<T>a,Point<T>b){A=a;B=b;}
    friend bool onLine(line<T> l1, Point<T> p){
        return(p.x <= max(l1.A.x, l1.B.x)
            && p.x >= min(l1.A.x, l1.B.x)
            && (p.y <= max(l1.A.y, l1.B.y)
            && p.y >= min(l1.A.y, l1.B.y)));
    }
    friend bool isIntersect(line<T> l1, line<T> l2){
        int dir1=direction(l1.A,l1.B,l2.A);
        int dir2=direction(l1.A,l1.B,l2.B);
        int dir3=direction(l2.A,l2.B,l1.A);
        int dir4=direction(l2.A,l2.B,l1.B);
        // When intersecting
        if (dir1!=dir2&&dir3!=dir4)return 1;
        // When B of line2 are on the line1
        if (dir1==0&& onLine(l1,l2.A))return 1;
        // When A of line2 are on the line1
        if (dir2==0&& onLine(l1, l2.B))return 1;
        // When B of line1 are on the line2
        if (dir3==0&& onLine(l2, l1.A))return 1;
        // When A of line1 are on the line2
        if (dir4==0&& onLine(l2, l1.B))return 1;
        return 0;
    }
};
