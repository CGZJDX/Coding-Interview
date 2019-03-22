//
//  main.cpp
//  12
//
//  Created by 马宁 on 2019/3/6.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;

bool equal(double num1, double num2){
    if(num1 - num2 < 0.0000001 && num2 - num1 < 0.0000001) return true;
    return false;
}

double Power(double base, int n) {
    int exponent;
    if(n > 0) exponent = n;
    if(n < 0){
        if(equal(base, 0)) return NULL;
        exponent = - n;
    }
    if(n == 0) return 1;
    double res = 1, cur = base;
    while(exponent != 0){
        if((exponent & 1) == 1) res *= cur;
        cur *= cur;
        exponent >>= 1;
    }
    return n >= 0 ? res : (1/res);
}



int main(int argc, const char * argv[]) {
    cout<<Power(0, -2)<<endl;
    return 0;
}
