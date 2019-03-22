//
//  main.cpp
//  50
//
//  Created by 马宁 on 2019/2/25.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;
bool duplicate(int numbers[], int length, int* duplication) {
    if(length < 1) return false;
    for(int i = 0; i < length; i ++){
        int index = numbers[i] % length;
        if(numbers[index] >= length){
            *duplication = index;
            return true;
        }
        numbers[index] += length;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
