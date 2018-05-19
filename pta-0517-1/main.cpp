//
//  main.cpp
//  pta-0517-1
//
//  Created by Hao Zeng on 2018/5/19.
//  Copyright © 2018年 Droidhen. All rights reserved.
//

// 名人堂与代金券
// https://pintia.cn/problem-sets/994805046380707840/problems/994805055176163328

#include <iostream>
#include <string>
#include <set>

using namespace std;

struct node {
    string id;
    int score;
    
    bool operator < (const node& compNode) const {
        if (score != compNode.score)
            return score > compNode.score;
        else
            return id < compNode.id;
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    int n, g, k;
    cin >> n >> g >> k;
    set<node> table;
    
    for (int i = 0; i < n; i++) {
        node p;
        cin >> p.id >> p.score;
        table.insert(p);
    }
    
    int total = 0;
    for (auto it = table.begin(); it != table.end(); it++) {
        if (it->score >= g)
            total += 50;
        else if (it->score >= 60)
            total += 20;
        else
            break;
    }
    
    cout << total << endl;
    
    int rank = 0; // 当前名次
    int score = 101; // 当前名次的分数
    int num = 1; // 当前名次的人数
    for (auto it = table.begin(); it != table.end(); it++) {
        if (it->score < score) {
            rank += num;
            if (rank > k)
                break;
            score = it->score;
            num = 1;
        } else {
            num++;
        }
        cout << rank << ' ' << it->id << ' ' << it->score << endl;
    }
    
    return 0;
}
