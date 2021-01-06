//
// Created by Linus Chen on 2019-09-19.
//

#include "stdc++.h"

using namespace std;

struct point {
    double x, y;
    point(){x=0,y=0;}
    point(const point &a){
        x = a.x;
        y = a.y;
    }
    point(double _x, double _y){
        x = _x;
        y = _y;
    }
    point operator+(const point &a){
        return point(x+a.x, y+a.y);
    }
    point operator-(const point &a){
        return point(x-a.x, y-a.y);
    }
    bool operator==(const point &a){
        return x==a.x && y==a.y;
    }

    double real(){return x;}
    double imag(){return y;}
    double abs(){return sqrt(x*x+y*y);}

    double mag(point p2 = point(0,0)) const {
        return sqrt((x-p2.x)*(x-p2.x) + (y-p2.y)*(y-p2.y));
    }
};

double dist(point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y*b.y));
}

double dot(point a, point b){
    return a.real() * b.real() + a.imag() * b.imag();
}

double cross(point a, point b){
    return a.real() * b.imag() - a.imag() * b.real();
}

double _ccw(point a, point b, point c){
    return cross(b - a, c - a);
}

double ccw(point a, point b, point c){
    return cross(b - a, c - b);
}

double polygon_area(vector<point> p) {
    double area = 0;
    int cnt = p.size();
    for (int i = 1; i + 1 < cnt; i++){
        area += cross(p[i] - p[0], p[i + 1] - p[0])/2;
    }
    return abs(area);
}

point lo;
bool cmp(point &a, point &b){return a.y < b.y;}
bool cmp2(point &a, point &b){return acos(dot(lo, a)/(lo.mag()*a.mag())) < acos(dot(lo, b)/(lo.mag()*b.mag()));}

const int MAXN = 1e6;
int SIZE;
point hull[MAXN];

int convex_hull(vector<point> p){
    int n = p.size(), l=0;
    sort(p.begin(),p.end(),cmp);
    lo = p[0];
    sort(p.begin(),p.end(),cmp2);

    for(int i=0; i<n; i++){
        if(i > 0 && p[i] == p[i-1])
            continue;
        while(l>=2&&ccw(hull[l-2],hull[l-1],p[i])>=0)
            l--;
        hull[l++] = p[i];
    }

    int r = l;
    for(int i=n-2; i>=0; i--){
        if(p[i]==p[i+1])
            continue;
        while(r-l>=1&&ccw(hull[r-2],hull[r-1],p[i])>=0)
            r--;
        hull[r++] = p[i];
    }
    return l == 1 ? 1 : r - 1;
}

bool in_hull(point p, vector<point> chull){
    double area = 0;
    vector<point> tri(3);
    tri[1] = p;
    for(int i=0; i<chull.size()-1; i++){
        tri[0] = chull[i];
        tri[2] = chull[i+1];
        area += polygon_area(tri);
    }
    tri[0] = chull[chull.size()-1];
    tri[2] = chull[0];
    area += polygon_area(tri);
    return area <= polygon_area(chull);
}

int main(){
    int n;
    double a, b;
    cin >> n;
    SIZE = n;
    vector<point> points;

    for(int i=0; i<n; i++){
        cin >> a >> b;
        points.push_back({a,b});
    }

    //number of points part of hull
    int s = convex_hull(points);
    cout << s << endl;

    vector<point> chull(s);

    for(int i=0; i<s; i++){
        cout << hull[i].real() << " " << hull[i].imag() << endl;
        chull.push_back(hull[i]);
    }

    cout << "Area of hull: " << polygon_area(chull);

    cout << "\nTest points\n";
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        cout << (in_hull(point(a,b), chull) ? "YA\n" : "NA\n");
    }

    cout << "DONE\n";
}