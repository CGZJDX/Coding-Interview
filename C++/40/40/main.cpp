//
//  main.cpp
//  40
//
//  Created by 马宁 on 2019/2/25.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
unsigned int FindFirstBit1(int num){
    unsigned int index = 0;
    while((num & 1) == 0 && index < 8 * sizeof(unsigned int)){
        num = num >> 1;
        index ++;
    }
    return index;
}
bool IsBit1(int num, int index){
    num = num >> index;
    return (num & 1);
}
void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    int len = data.size() - 1;
    if(len < 1) return;
    int num = 0;
    for(int i = 0; i <= len; i ++){
        num ^= data[i];
    }
    int index = FindFirstBit1(num);
    *num1 = *num2 = 0;
    for(int i = 0; i <= len; i ++){
        if(IsBit1(data[i], index)) *num1 ^= data[i];
        else *num2 ^= data[i];
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,2,3,4,5,6,4,3,2,1};
    int num1, num2;
    FindNumsAppearOnce(a, &num1, &num2);
    /*unsigned int b = 0;
    b = b - 1;
    unsigned int c = b >> 31;
    cout<<b<<endl<<c<<endl;*/
    cout<<num1<<endl<<num2<<endl;
    return 0;
}
