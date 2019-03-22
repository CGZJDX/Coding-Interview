//
//  main.cpp
//  10
//
//  Created by 马宁 on 2019/3/4.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;

int rectCover(int number) {
    if(number <= 1) return 1;
    int g = 2, f = 1;
    while(number > 1){
        g += f;
        f = g - f;
        number --;
    }
    return f;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
