//
//  main.cpp
//  SortTest
//
//  Created by Hao Zeng on 2018/5/6.
//  Copyright © 2018年 Droidhen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool comp(const string& l, const string& r)
{
    return l.size() < r.size();
}

int main(int argc, const char * argv[]) {

    vector<string> vec;
    vec.push_back("about about");
    vec.push_back("about");
    vec.push_back("above");
    vec.push_back("actor");
    vec.push_back("admit");
    vec.push_back("adult");
    vec.push_back("a");
    
    stable_sort(vec.begin(), vec.end(), comp);
    
    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << *it << endl;
    }
    
    return 0;
}
