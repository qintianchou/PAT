//
//  main.cpp
//  pat-L2-028
//
//  Created by Hao Zeng on 2018/5/5.
//  Copyright © 2018年 Droidhen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n, m, k, p;
vector<int>* vecs;

// 照片里人数数组
long long* arr;

long long lcm = 1;

long long* p1_r;
long long* p2_r;

int* sex;

void calc(long long* r, int p);
long long gcd(long long a, long long b);
bool Comp1(const int i1, const int i2);
bool Comp2(const int i1, const int i2);
int abs(int a);
void print(int p1, int p2);

int main(int argc, const char * argv[]) {
    
    double s1 = 1.0 / 3 + 1.0 / 7;
    double s2 = 1.0 / 21 + 3.0 / 7;
    
    cout << s1 << endl;
    cout << s2 << endl;
    
    if (s1 == s2)
        cout << "yes\n";
    else
        cout << "no\n";
    
//    for (int i = 1; i <= 500; i++) {
//        lcm = lcm * i / gcd(lcm, i);
//        cout << i << " " << lcm << endl;
//    }

    lcm = 1;
    
    cin >> n >> m;
    
    vecs = new vector<int>[m];
    arr = new long long[m];
    
    sex = new int[n];
    memset(sex, 0, sizeof(int)*n);
    
    char str[6];
    
    for (int i = 0; i < m; i++) {
        cin >> k;
        arr[i] = k;
        for (int j = 0; j < k; j++) {
            
            cin >> str;
            p = atoi(str);
            vecs[i].push_back(p);
            int abs = p >= 0 ? p : -p;
            sex[abs] = str[0] == '-' ? -1 : 1;
        }
    }
    
    for (int i = 0; i < m; i++) {
        lcm = lcm * arr[i] / gcd(lcm, arr[i]);
    }
    
    int p1, p2;
    
    cin >> str;
    p1 = atoi(str);
    sex[abs(p1)] = str[0] == '-' ? -1 : 1;
    
    cin >> str;
    p2 = atoi(str);
    sex[abs(p2)] = str[0] == '-' ? -1 : 1;
    
    p1_r = new long long[n];
    p2_r = new long long[n];
    memset(p1_r, 0, sizeof(long)*n);
    memset(p2_r, 0, sizeof(long)*n);
    
    calc(p1_r, p1);
    calc(p2_r, p2);
    
    int p2_abs = p2 >= 0 ? p2 : -p2;
    
    // 亲密度
    long long g = p1_r[p2_abs];
    
    vector<int> vec1;
    for (int i = 0; i < n; i++) {
        vec1.push_back(i);
    }
    
    stable_sort(vec1.begin(), vec1.end(), Comp1);
    
    vector<int> vec2;
    for (int i = 0; i < n; i++) {
        vec2.push_back(i);
    }
    
    stable_sort(vec2.begin(), vec2.end(), Comp2);
    
//    print(p1, p2);
    
    long max = 0;
    
    vector<int> p1m;
    
    for (int i = 0; i < n; i++) {
        int index = vec1[i];
        if (sex[abs(p1)] * sex[index] < 0) {
            if (p1_r[index] >= max) {
                max = p1_r[index];
//                cout << p1 << " " << index * sex[index] << endl;
//                print(p1, index * sex[index]);
                p1m.push_back(index * sex[index]);
            }
        }
    }
    
    max = 0;
    
    vector<int> p2m;
    
    for (int i = 0; i < n; i++) {
        int index = vec2[i];
        if (sex[abs(p2)] * sex[index] < 0) {
            if (p2_r[index] >= max) {
                max = p2_r[index];
//                cout << p2 << " " << index * sex[index] << endl;
//                print(p2, index * sex[index]);
                p2m.push_back(index * sex[index]);
            }
        }
    }
    
    if (find(p1m.begin(), p1m.end(), p2) != p1m.end() && find(p2m.begin(), p2m.end(), p1) != p2m.end()) {
        print(p1, p2);
    } else {
        for (int i = 0; i < p1m.size(); i++) {
            print(p1, p1m[i]);
        }
        for (int i = 0; i < p2m.size(); i++) {
            print(p2, p2m[i]);
        }
    }
    
    return 0;
}

void calc(long long* r, int p)
{
    for (int i = 0; i < m; i++) {
        
        bool ret = false;
        unsigned long size = vecs[i].size();
        long long v = lcm / size;
        
        for (int j = 0; j < size; j++) {
            if (p == vecs[i][j]) {
                ret = true;
                break;
            }
        }
        
        if (ret) {
            for (int j = 0; j < size; j++) {
                int temp = vecs[i][j];
                if (p != temp) {
                    int abs = temp >= 0 ? temp : -temp;
                    r[abs] += v;
                }
            }
        }
    }
}

long long gcd(long long a, long long b)
{
    long long t;
    while (b) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

bool Comp1(const int i1, const int i2)
{
    return p1_r[i1] > p1_r[i2];
}

bool Comp2(const int i1, const int i2)
{
    return p2_r[i1] > p2_r[i2];
}

int abs(int a)
{
    return a >= 0 ? a : -a;
}

void print(int p1, int p2)
{
    if (sex[abs(p1)] < 0)
        cout << "-" << abs(p1);
    else
        cout << p1;
    
    cout << " ";
    
    if (sex[abs(p2)] < 0)
        cout << "-" << abs(p2);
    else
        cout << p2;
    
    cout << endl;
}






