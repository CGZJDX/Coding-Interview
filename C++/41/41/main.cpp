//
//  main.cpp
//  41
//
//  Created by 马宁 on 2019/3/7.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) {
    vector<vector<int>> res;
    if(sum <= 0) return res;
    int slow = 1;
    int fast = 2;
    while(fast < (sum / 2 + 1) && slow < fast){
        int seqsum = ((fast + slow) * (fast - slow + 1)) >> 1;
        if(seqsum == sum){
            vector<int> temp;
            for(int i = slow; i <= fast; i ++) temp.push_back(i);
            res.push_back(temp);
            slow ++;
        }
        else if(seqsum > sum) slow ++;
        else fast ++;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> a;
    a = FindContinuousSequence(100);
    for(int i = 0; i < a.size(); i ++){
        for(int j = 0; j < a[i].size(); j ++){
            cout<<a[i][j]<<",";
        }
        cout<<endl;
    }
    return 0;
}
