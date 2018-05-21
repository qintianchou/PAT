//
//  main.cpp
//  StringTest
//
//  Created by Hao Zeng on 2018/5/19.
//  Copyright © 2018年 Droidhen. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

void print(const string& s) {
    cout << s << endl;
}

struct node {
    string id;
    int score;
    
    node(const string& id, int score) {
        this->id = id;
        this->score = score;
    }
    
    bool operator < (const node& compNode) const {
        if (score != compNode.score)
            return score > compNode.score;
        else
            return id < compNode.id;
    }
};

int main(int argc, const char * argv[]) {
    const char* str = "hello";
    print(str);

    char arr2[2];
    arr2[1] = '\0';
    char arr[2];
    char arr3[2];
    arr3[1] = '\0';
    cin >> arr; // 很危险
    
    cout << "1 " << arr2 << endl;
    cout << "2 " << arr << endl;
    cout << "3 " << arr3 << endl;
    
    set<node> table;
    table.insert(node(arr, 0));
    
    auto it = table.begin();
    
    cout << it->id << endl;
    
    string ss;
    cin >> ss;
    cout << ss << endl;
    
    return 0;
}
