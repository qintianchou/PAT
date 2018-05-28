//
//  main.cpp
//  pta-0517-2
//
//  Created by Hao Zeng on 2018/5/27.
//  Copyright © 2018年 Droidhen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstdlib>
#include <cmath>
#include <unordered_map>

using namespace std;

struct picture {
    vector<int> boys;
    vector<int> girls;
    
    unsigned long size() const {
        return boys.size() + girls.size();
    }
};

struct person {
    int num;
    double r;
    
    bool operator < (const person& comp) const {
        if (fabs(r - comp.r) > 1e-6)
            return r > comp.r;
        else
            return abs(num) < abs(comp.num);
    }
};

struct relation {
    int num;
    unordered_map<int, double> dict;
    set<person> max;
    
    void calc(const vector<picture>& pictures) {
        string pNum;
        cin >> pNum;
        int a = atoi(pNum.c_str());
        this->num = pNum[0] == '-' ? a - 1 : a + 1;
        for (auto it = pictures.begin(); it != pictures.end(); it++) {
            const vector<int> *same, *diff;
            if (this->num > 0) {
                same = &(it->boys);
                diff = &(it->girls);
            } else {
                same = &(it->girls);
                diff = &(it->boys);
            }
            double r = 0;
            if (find(same->begin(), same->end(), num) != same->end())
                r = 1.0 / it->size();
            for (auto it2 = diff->begin(); it2 != diff->end(); it2++) {
                if (dict.count(*it2) == 0)
                    dict[*it2] = 0;
                dict[*it2] += r;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    int n, m, k;
    string pNum;
    vector<picture> pictures;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        pictures.push_back(picture());
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> pNum;
            if (pNum[0] == '-') {
                pictures[i].girls.push_back(atoi(pNum.c_str()) - 1);
            } else {
                pictures[i].boys.push_back(atoi(pNum.c_str()) + 1);
            }
        }
    }

    return 0;
}
