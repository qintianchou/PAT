//
//  main.cpp
//  pta-0329-1
//
//  Created by Hao Zeng on 2018/5/12.
//  Copyright © 2018年 Droidhen. All rights reserved.
//

// dfs, bfs

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <unordered_set>

using namespace std;

int n = 0, e = 0;
set<int> graph[10];
vector<int> target;
unordered_set<int> all;

void dfs(int v);
void bfs(int v);
void print(vector<int>& vec);

int main(int argc, const char * argv[]) {
    freopen("in.txt", "r", stdin);
    cin >> n >> e;
    
    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].insert(v2);
        graph[v2].insert(v1);
    }
    
    all.clear();
    for (int i = 0; i < n; i++) {
        if (all.find(i) != all.end())
            continue;
        target.clear();
        dfs(i);
        print(target);
    }
    
    all.clear();
    for (int i = 0; i < n; i++) {
        if (all.find(i) != all.end())
            continue;
        target.clear();
        bfs(i);
        print(target);
    }
    
    return 0;
}

void dfs(int v)
{
    target.push_back(v);
    all.insert(v);
    for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
        if (all.find(*it) == all.end()) {
            dfs(*it);
        }
    }
}

void bfs(int v)
{
    queue<int> q;
    
    q.push(v);
    target.push_back(v);
    all.insert(v);
    
    while (!q.empty()) {
        int e = q.front();
        q.pop();
        for (auto it = graph[e].begin(); it != graph[e].end(); it++) {
            if (all.find(*it) == all.end()) {
                q.push(*it);
                target.push_back(*it);
                all.insert(*it);
            }
        }
    }
}

void print(vector<int>& vec)
{
    cout << "{ ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "}\n";
}



