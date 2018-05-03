//
//  main.cpp
//  PTA7-1
//
//  Created by Hao Zeng on 2018/5/2.
//  Copyright © 2018年 Droidhen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int n = 0, e = 0;
bool graph[10][10];
vector<int> target;
bool flag[10];

void dfs(int v);
void bfs(int v);
bool contains(vector<int>& vec, int value);
void print(vector<int>& vec);

int main(int argc, const char * argv[]) {
    cin >> n >> e;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            graph[i][j] = false;
        }
    }
    
    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = true;
        graph[v2][v1] = true;
    }
    
    for (int i = 0; i < 10; i++) {
        flag[i] = false;
    }
    
    for (int i = 0; i < n; i++) {
        if (flag[i])
            continue;
        target.clear();
        dfs(i);
        print(target);
    }
    
    for (int i = 0; i < 10; i++) {
        flag[i] = false;
    }
    
    for (int i = 0; i < n; i++) {
        if (flag[i])
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
    flag[v] = true;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !flag[i])
            dfs(i);
    }
}

void bfs(int v)
{
    queue<int> q;
    
    q.push(v);
    target.push_back(v);
    flag[v] = true;
    
    while (!q.empty()) {
        int e = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (graph[e][i] && !flag[i]) {
                q.push(i);
                target.push_back(i);
                flag[i] = true;
            }
        }
    }
}

bool contains(vector<int>& vec, int value)
{
    vector<int>::iterator ret;
    ret = find(vec.begin(), vec.end(), value);
    return ret != vec.end();
}

void print(vector<int>& vec)
{
    cout << "{ ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "}\n";
}


