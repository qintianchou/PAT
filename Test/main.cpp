//
//  main.cpp
//  Test
//
//  Created by Hao Zeng on 2018/5/3.
//  Copyright © 2018年 Droidhen. All rights reserved.
//

#include <iostream>
#include <map>
#include <list>
using namespace std;
typedef std::list<int > TESTLIST;
int main(int argc, const char * argv[])
{
    TESTLIST t;
    for (int i = 0; i < 10;i++)
    {
        t.push_back(i);
    }
    
    for (TESTLIST::iterator it = t.begin(); it != t.end();)
    {
        cout << *it << endl;
        it = t.erase(it);
        cout << (it == t.end() ? "end" : "exsit") << endl;
    }
    
    return 0;
}
