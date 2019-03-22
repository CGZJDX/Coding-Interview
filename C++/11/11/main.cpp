//
//  main.cpp
//  11
//
//  Created by 马宁 on 2019/3/5.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;

int  NumberOf1(int n) {
    int count = 0;
    while(n){
        n = n & (n - 1);
        count ++;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    int i = 0xffffffff;
    unsigned int j = 0xffffffff;
    cout<<i<<endl<<j<<endl;
    return 0;
}
