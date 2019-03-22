//
//  main.cpp
//  8
//
//  Created by 马宁 on 2019/3/4.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;
int jumpFloor(int number) {
    /*if(number == 1) return 1;
    if(number == 2) return 2;
    return jumpFloor(number - 1) + jumpFloor(number - 2);*/
    if(number <= 0) return 0;
    int g = 2, f = 1;
    while(number > 1){
        g += f;
        f = g - f;
        number --;
    }
    return f;
}
int main(int argc, const char * argv[]) {
    cout<<jumpFloor(4)<<endl;
    return 0;
}
