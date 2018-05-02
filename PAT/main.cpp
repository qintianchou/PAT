//
//  main.cpp
//  PAT
//
//  Created by Hao Zeng on 2018/4/27.
//  Copyright © 2018年 Droidhen. All rights reserved.
//

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int MAX_LENGTH = 101;

bool judge(const char* c_str);

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    char str[MAX_LENGTH];
    cin.getline(str, MAX_LENGTH);
    for (int i = 0; i < n; i++) {
        cin.getline(str, MAX_LENGTH);
        if (judge(str))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

bool judge(const char* c_str) {
    cout << strlen(c_str) << endl;
    string str(c_str);
    
    if (str.length() < 3)
        return false;
    
    int state = 0;
    int a = 0, b = 0, c = 0;
    
    int i = 0;
    while (i < str.length()) {
        if (state == 0)
        {
            if (str[i] == 'A')
            {
                a++;
                i++;
            }
            else
            {
                state = 1;
            }
        }
        else if (state == 1)
        {
            if (str[i] == 'P')
            {
                state = 2;
                i++;
            }
            else
            {
                return false;
            }
        }
        else if (state == 2)
        {
            if (str[i] == 'A')
            {
                b++;
                i++;
            }
            else
            {
                state = 3;
            }
        }
        else if (state == 3)
        {
            if (str[i] == 'T')
            {
                state = 4;
                i++;
            }
            else
            {
                return false;
            }
        }
        else if (state == 4)
        {
            if (str[i] == 'A')
            {
                c++;
                i++;
            }
            else
            {
                return false;
            }
        }
    }
    
    if (b == 0)
        return false;
    
    if (a == 0 && c != 0)
        return false;
    
    if (a * b != c)
        return false;
    
    return true;
}





