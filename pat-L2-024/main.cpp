//
//  main.cpp
//  pat-L2-024
//
//  Created by Hao Zeng on 2018/5/7.
//  Copyright © 2018年 Droidhen. All rights reserved.
//

// L2-024. 部落
// https://www.patest.cn/contests/gplt/L2-024

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n, k, p;
int sum = 0;
vector<int> graph[10001];
unordered_set<int> all;
vector<unordered_set<int>*> orgs;

void dfs(int v, unordered_set<int>& target);

int main(int argc, const char * argv[]) {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> k;
        vector<int> vec;
        for (int j = 0; j < k; j++) {
            cin >> p;
            vec.push_back(p);
        }
        
        for (auto it = vec.begin(); it != vec.end(); it++) {
            if (*it > sum)
                sum = *it;
            for (auto it2 = vec.begin(); it2 != vec.end(); it2++) {
                if (*it != *it2) {
                    graph[*it].push_back(*it2);
                }
            }
        }
    }
    
    for (int i = 1; i <= sum; i++) {
        if (all.find(i) != all.end())
            continue;
        unordered_set<int>* t = new unordered_set<int>();
        dfs(i, *t);
        orgs.push_back(t);
    }
    
    cout << sum << " " << orgs.size() << endl;
    
    int q, v1, v2;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> v1 >> v2;
        bool ret = false;
        for (auto it = orgs.begin(); it != orgs.end(); it++) {
            if ((*it)->find(v1) != (*it)->end() && (*it)->find(v2) != (*it)->end()) {
                ret = true;
                break;
            }
        }
        if (ret)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    
    return 0;
}

void dfs(int v, unordered_set<int>& target)
{
    target.insert(v);
    all.insert(v);
    for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
        if (all.find(*it) == all.end())
            dfs(*it, target);
    }
}

