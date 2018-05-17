//
//  main.cpp
//  PAT-L2-026
//
//  Created by Hao Zeng on 2018/5/5.
//  Copyright © 2018年 Droidhen. All rights reserved.
//

// L2-026. 小字辈
// https://www.patest.cn/contests/gplt/L2-026

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int* p_arr;
int* l_arr;

int level(int m);

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    
    p_arr = new int[n];
    
    for (int i = 0; i < n; i++) {
        cin >> p_arr[i];
    }
    
    l_arr = new int[n];
    memset(l_arr, 0, sizeof(int) * n);
    
    int max_l = 0;
    vector<int> vec;
    
    for (int i = 1; i <= n; i++) {
        int l = level(i);
        if (l >= max_l) {
            if (l > max_l) {
                max_l = l;
                vec.clear();
            }
            vec.push_back(i);
        }
    }
    
    cout << max_l << endl;
    cout << vec[0];
    for (int i = 1; i < vec.size(); i++) {
        cout << " " << vec[i];
    }
    cout << endl;
    
    return 0;
}

int level(int m)
{
    int* l = &l_arr[m-1];
    if (*l > 0)
        return *l;
    
    int p = p_arr[m - 1];
    if (p == -1)
        *l = 1;
    else
        *l = level(p) + 1;

    return *l;
}
