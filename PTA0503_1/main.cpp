//
//  main.cpp
//  PTA0503_1
//
//  Created by Hao Zeng on 2018/5/3.
//  Copyright © 2018年 Droidhen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int n = 0, e = 0;

int* v1_arr;
int* v2_arr;

bool judge(vector<int>& vec);

int main(int argc, const char * argv[]) {
    cin >> n >> e;
    
    v1_arr = new int[e];
    v2_arr = new int[e];
    
    for (int i = 0; i < e; i++) {
        cin >> v1_arr[i] >> v2_arr[i];
    }
    
    int s;
    cin >> s;
    
    for (int i = 0; i < s; i++) {
        int p;
        cin >> p;
        vector<int> vec;
        for (int j = 0; j < p; j++) {
            int v;
            cin >> v;
            vec.push_back(v);
        }
        
        if (judge(vec))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}

bool judge(vector<int>& vec)
{
    list<int> l;
    for (int i = 0; i < e; i++)
        l.push_back(i);
    
    for (int i = 0; i < vec.size(); i++) {
        int v = vec[i];
        for (list<int>::iterator it = l.begin(); it != l.end();) {
            int index = *it;
            if (v1_arr[index] == v || v2_arr[index] == v)
                it = l.erase(it);
            else
                it++;
        }
    }
    
    return l.size() == 0;
}





