//
//  main.cpp
//  30
//
//  Created by 马宁 on 2019/2/23.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int FindGreatestSumOfSubArray(vector<int> array) {
    int res = array[0];
    int max = array[0];
    for(int i = 1; i < array.size(); i ++){
        max = (max + array[i] >= array[i]) ? max + array[i] : array[i];
        res = (max >= res) ? max : res;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> a = {6,-3,-2,7,-15,1,2,2};
    int res = FindGreatestSumOfSubArray(a);
    cout<<res<<endl;
    return 0;
}
