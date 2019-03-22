//
//  main.cpp
//  48
//
//  Created by 马宁 on 2019/3/9.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;

int Add(int num1, int num2)
{
    /*int sum = num1 ^ num2, carry = (num1 & num2) << 1;
    while (carry != 0) {
        num1 = sum;
        num2 = carry;
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
    }
    return sum;*/
    return num2 ? (Add(num1 ^ num2, (num1 & num2) << 1)) : num1;
}

int main(int argc, const char * argv[]) {
    int a;
    a = Add(5, 6);
    cout<<a<<endl;
    int b = 0x7FFFFFFF;
    cout<<(0x7FFFFFFF + 2)<<endl;
    cout<<((0x7FFFFFFF + 2) & (-1))<<endl;
    cout<<~((0x7FFFFFFF + 2) ^ (-1))<<endl;
    cout<<((-6) ^ (-5))<<endl;
    return 0;
}
