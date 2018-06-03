//
//  main.cpp
//  pta-0530-1
//
//  Created by Hao Zeng on 2018/6/2.
//  Copyright © 2018年 Droidhen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <cmath>

using namespace std;

struct BTNode {
    int v; // 负数表示操作符
    BTNode *lchild, *rchild;
    double r;
    string exp;
    BTNode(int v, BTNode* lc, BTNode* rc) {
        this->v = v;
        this->lchild = lc;
        this->rchild = rc;
        if (v > 0) {
            this->r = v;
            exp.append(to_string(v));
        } else {
            char op = (char)(-v);
            if (op == '+')
                this->r = lc->r + rc->r;
            else if (op == '-')
                this->r = lc->r - rc->r;
            else if (op == '*')
                this->r = lc->r * rc->r;
            else if (op == '/') {
                if (fabs(rc->r) < 1e-6)
                    this->r = INT_MAX;
                else
                    this->r = lc->r / rc->r;
            }
            exp.append("(").append(lc->exp).append(string(1, op)).append(rc->exp).append(")");
        }
    }
};

typedef BTNode* BTree;

int operator_arr[]{'+', '-', '*', '/'};

bool FindOperation(vector<BTree> vec);

int main(int argc, const char * argv[]) {
    freopen("in.txt", "r", stdin);
    vector<BTree> vec;
    for (int i = 0; i < 4; i++) {
        int num;
        cin >> num;
        BTree bt = new BTNode(num, nullptr, nullptr);
        vec.push_back(bt);
    }
    
    if (!FindOperation(vec))
        cout << -1 << endl;
    
    return 0;
}

bool FindOperation(vector<BTree> vec) {
    if (vec.size() == 1) {
        if (fabs(vec[0]->r - 24) < 1e-6) {
            cout << (vec[0]->exp).substr(1, (vec[0]->exp).size()-2) << endl;
            return true;
        }
        return false;
    }
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            if (j == i)
                continue;
            for (int k = 0; k < 4; k++) {
                BTree bt = new BTNode(-operator_arr[k], vec[i], vec[j]);
                vector<BTree> vec2;
                vec2.push_back(bt);
                for (int l = 0; l < vec.size(); l++) {
                    if (l != i && l != j)
                        vec2.push_back(vec[l]);
                }
                if (FindOperation(vec2))
                    return true;
            }
        }
    }
    return false;
}


