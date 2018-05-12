//
//  main.cpp
//  SortTest
//
//  Created by Hao Zeng on 2018/5/6.
//  Copyright © 2018年 Droidhen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Point {
public:
    double x;
    double y;
    double r;
    
    Point(double x, double y, double r) {
        this->x = x;
        this->y = y;
        this->r = r;
    }
    
    static double dist(const Point& p1, const Point& p2) {
        double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;
        double d = sqrt(dx * dx + dy * dy);
        d = d - p1.r - p2.r;
        if (d < 0)
            d = 0;
        return d;
    }
};

bool comp(const string& l, const string& r)
{
    return l.size() < r.size();
}

int main(int argc, const char * argv[]) {
    
    freopen("in.txt", "r", stdin);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << a << b << c << d << endl;
    
    Point p1(0, 0, 0);
    Point p2(1, 1, 1);
    
    double dist = Point::dist(p1, p2);
    
    cout << dist << endl;
    
    cout << -22/7 << endl;
    cout << -22%7 << endl;

    vector<string> vec;
    vec.push_back("about about");
    vec.push_back("about");
    vec.push_back("above");
    vec.push_back("actor");
    vec.push_back("admit");
    vec.push_back("adult");
    vec.push_back("a");
    
    stable_sort(vec.begin(), vec.end(), comp);
    
    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << *it << endl;
    }
    
    return 0;
}
