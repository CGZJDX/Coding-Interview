//
//  main.cpp
//  21
//
//  Created by 马宁 on 2019/3/4.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
    stack<int> test;
    if(pushV.size() == 0) return false;
    for(int i = 0, j = 0; i < pushV.size(); i ++){
        test.push(pushV[i]);
        while (j < popV.size() && test.top() == popV[j]) {
            test.pop();
            j ++;
        }
    }
    if(popV.empty()) return true;
    return false;
}

int main(int argc, const char * argv[]) {
    return 0;
}
