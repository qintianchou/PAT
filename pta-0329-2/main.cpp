//
//  main.cpp
//  pta-0329-2
//
//  Created by Hao Zeng on 2018/5/12.
//  Copyright © 2018年 Droidhen. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

class node {
public:
    node() {
        value = 0;
        parent = -1;
        lchild = -1;
        rchild = -1;
    }
    int value;
    int parent;
    int lchild;
    int rchild;
};

node nodes[10];
int n;

int main(int argc, const char * argv[]) {
    freopen("in.txt", "r", stdin);
    cin >> n;
    char str1[3];
    char str2[3];
    for (int i = 0; i < n; ++i) {
        cin >> str1 >> str2;
        nodes[i].value = i;
        if (str1[0] != '-') {
            int index = atoi(str1);
            nodes[i].lchild = index;
            nodes[index].parent = i;
        }
        if (str2[0] != '-') {
            int index = atoi(str2);
            nodes[i].rchild = index;
            nodes[index].parent = i;
        }
    }
    
    // find root
    int root = 0;
    while (nodes[root].parent != -1)
        root = nodes[root].parent;
    
    // bfs tree
    int count = 0;
    queue<int> queue;
    queue.push(root);
    while (!queue.empty()) {
        int index = queue.front();
        queue.pop();
        if (nodes[index].lchild == -1 && nodes[index].rchild == -1) {
            if (count == 0)
                cout << index;
            else
                cout << ' ' << index;
            count++;
        } else {
            if (nodes[index].lchild != -1)
                queue.push(nodes[index].lchild);
            if (nodes[index].rchild != -1)
                queue.push(nodes[index].rchild);
        }
    }
    
    cout << '\n';
    
    return 0;
}
