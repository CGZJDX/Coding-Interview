//
//  main.cpp
//  7
//
//  Created by 马宁 on 2019/3/4.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;

int Fibonacci(int n) {
    '''
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
    '''
    int f = 0, g = 1;
    while(n --){
        g += f;
        f = g - f;
    }
}
int main(int argc, const char * argv[]) {
    for(int i = 0; i < 40; i ++){
        cout<<Fibonacci(i)<<endl;
    }
    return 0;
}
