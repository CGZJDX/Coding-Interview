//
//  main.cpp
//  51
//
//  Created by 马宁 on 2019/2/25.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> multiply(const vector<int>& A) {
    int len = A.size();
    vector<int> B(len);
    if(len == 0) return B;
    B[0] = 1;
    for(int i = 1; i < len; i ++){
        B[i] = B[i - 1] * A[i - 1];
    }
    int temp = 1;
    for(int i = len - 2; i >= 0; i --){
        temp *= A[i + 1];
        B[i] *= temp;
    }
    return B;
}
int main(int argc, const char * argv[]) {
    return 0;
}
