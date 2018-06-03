//
//  main.cpp
//  pta-0530-2
//
//  Created by Hao Zeng on 2018/6/1.
//  Copyright © 2018年 Droidhen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct BTNode {
    int v;
    BTNode *lchild, *rchild;
};

typedef BTNode* BTree;

int n;
vector<int> vec;
vector<int> post_vec;

BTree CreateTree(bool isMirror, int* cursor, int min, int max);
void PostOrder(BTree bt);

int main(int argc, const char * argv[]) {
    freopen("in.txt", "r", stdin);
    cin >> n;
    int v;
    for (int i = 0; i < n; i++) {
        cin >> v;
        vec.push_back(v);
    }
    
    int p = 0;
    BTree bt = CreateTree(false, &p, INT_MIN, INT_MAX);
    if (p < vec.size()) {
        p = 0;
        bt = CreateTree(true, &p, INT_MIN, INT_MAX);
    }
    
    if (p < vec.size()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        PostOrder(bt);
        int count = 0;
        for (auto it = post_vec.begin(); it != post_vec.end(); it++) {
            if (count == 0)
                cout << *it;
            else
                cout << " " << *it;
            count++;
        }
        cout << endl;
    }
    
    return 0;
}

// min, max 是闭区间
BTree CreateTree(bool isMirror, int* cursor, int min, int max) {
    BTree bt = nullptr;
    if (*cursor >= vec.size())
        return bt;
    int v = vec[*cursor];
    if (v >= min && v <= max) {
        *cursor = *cursor + 1;
        bt = new BTNode();
        bt->v = v;
        if (isMirror) {
            bt->lchild = CreateTree(isMirror, cursor, std::max(min, v), std::min(max, INT_MAX));
            bt->rchild = CreateTree(isMirror, cursor, std::max(min, INT_MIN), std::min(max, v-1));
        } else {
            bt->lchild = CreateTree(isMirror, cursor, std::max(min, INT_MIN), std::min(max, v-1));
            bt->rchild = CreateTree(isMirror, cursor, std::max(min, v), std::min(max, INT_MAX));
        }
    }
    return bt;
}

void PostOrder(BTree bt) {
    if (bt == nullptr)
        return;
    PostOrder(bt->lchild);
    PostOrder(bt->rchild);
    post_vec.push_back(bt->v);
}


