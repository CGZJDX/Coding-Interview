//
//  main.cpp
//  33
//
//  Created by 马宁 on 2019/2/26.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int GetUglyNumber_Solution(int index) {
    if(index <= 0) return NULL;
    if(index < 7) return index;
    vector<int> res;
    for(int i = 0; i < 6; i ++){
        res.push_back(i + 1);
    }
    int t2 = 3, t3 = 2, t5 = 1;
    while(res.size() < index){
        int UglyNumber = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
        res.push_back(UglyNumber);
        if(res[t2] * 2 == UglyNumber) t2 ++;
        if(res[t3] * 3 == UglyNumber) t3 ++;
        if(res[t5] * 5 == UglyNumber) t5 ++;
    }
    return res[index - 1];
}

int main(int argc, const char * argv[]) {
    int a = GetUglyNumber_Solution(1500);
    cout<<a<<endl;
    return 0;
}

