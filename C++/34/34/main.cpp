//
//  main.cpp
//  34
//
//  Created by 马宁 on 2019/3/7.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;
int FirstNotRepeatingChar(string str) {
    map<char, int> m;
    for(int i = 0; i < str.length(); i ++){
        m[str[i]] ++;
    }
    for(int i = 0; i < str.length(); i ++){
        if(m[str[i]] == 1) return i;
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
