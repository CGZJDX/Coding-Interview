//
//  main.cpp
//  46
//
//  Created by 马宁 on 2019/3/8.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;

int LastRemaining_Solution(int n, int m)
{
    if(n < 1 || m < 1) return -1;
    int last = 0;
    for(int i = 2; i <= n; i ++){
        last = (last + m % i) % i;
    }
    return last;
}

int main(int argc, const char * argv[]) {
    int a;
    int n = 6, m = 7;
    a = LastRemaining_Solution(n, m);
    cout<<a<<endl;
    return 0;
}
