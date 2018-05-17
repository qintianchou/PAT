//
//  main.cpp
//  pat-L2-027
//
//  Created by Hao Zeng on 2018/5/5.
//  Copyright © 2018年 Droidhen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

char names[10000][16];
int scores[10000];

bool Comp(const int i1, const int i2);

int main(int argc, const char * argv[]) {
    
    int n, g, k;
    cin >> n >> g >> k;
    
    vector<int> vec;
    
    for (int i = 0; i < n; i++) {
        cin >> names[i] >> scores[i];
        vec.push_back(i);
    }
    
    sort(vec.begin(), vec.end(), Comp);
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int index = vec[i];
        if (scores[index] >= g)
            sum += 50;
        else if (scores[index] >= 60)
            sum += 20;
        else
            break;
    }
    
    cout << sum << endl;
    
    int c = 0;
    int r = 101;
    int acc = 1;
    for (int i = 0; i < n; i++) {
        int index = vec[i];
        if (scores[index] < r) {
            c += acc;
            if (c > k)
                break;
            acc = 0;
            r = scores[index];
        }
        acc++;
        cout << c << " " << names[index] << " " << scores[index] << endl;
    }
    
    return 0;
}

bool Comp(const int i1, const int i2)
{
    if (scores[i1] != scores[i2]) {
        return scores[i1] > scores[i2];
    } else {
        return strcmp(names[i1], names[i2]) < 0;
    }
}
