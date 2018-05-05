//
//  main.cpp
//  PTA0503_1
//
//  Created by Hao Zeng on 2018/5/3.
//  Copyright © 2018年 Droidhen. All rights reserved.
//

// L2-025. 分而治之
// https://www.patest.cn/contests/gplt/L2-025

#include <iostream>
#include <unordered_set>

using namespace std;

int n = 0, e = 0;

int* v1_arr;
int* v2_arr;

int main(int argc, const char * argv[]) {
    cin >> n >> e;
    
    v1_arr = new int[e];
    v2_arr = new int[e];
    
    for (int i = 0; i < e; i++) {
        cin >> v1_arr[i] >> v2_arr[i];
    }
    
    int s, p, v;
    unordered_set<int> set;
    
    cin >> s;
    for (int i = 0; i < s; i++) {
        set.clear();
        cin >> p;
        for (int j = 0; j < p; j++) {
            cin >> v;
            set.insert(v);
        }
        
        bool ret = true;
        for (int j = 0; j < e; j++) {
            if (set.find(v1_arr[j]) == set.end() && set.find(v2_arr[j]) == set.end()) {
                ret = false;
                break;
            }
        }
        
        if (ret)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}





