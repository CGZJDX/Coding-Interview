//
//  main.cpp
//  31
//
//  Created by 马宁 on 2019/3/6.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
    int count = 0;
    for(int i = 1; i <= n; i *= 10){
        int a = n / i;
        int b = n % i;
        count += (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
    }
    return count;
}

int main(int argc, const char * argv[]) {
    cout<<NumberOf1Between1AndN_Solution(12)<<endl;
    return 0;
}
