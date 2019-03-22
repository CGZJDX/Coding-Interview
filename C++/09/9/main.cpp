//
//  main.cpp
//  9
//
//  Created by 马宁 on 2019/3/4.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;

int jumpFloorII(int number) {
    if(number <= 0) return 0;
    return 1 << -- number;
}

int main(int argc, const char * argv[]) {
    cout<<jumpFloorII(5)<<endl;
    return 0;
}
