//
//  main.cpp
//  35
//
//  Created by 马宁 on 2019/2/23.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
long InversePairsCore(vector<int> &data, vector<int>&copy, int begin, int end){
    if(begin == end){
        copy[begin] = data[end];
        return 0;
    }
    int mid = (begin + end) >> 1;
    long leftcount = InversePairsCore(copy, data, begin, mid);
    long rightcount = InversePairsCore(copy, data, mid + 1, end);
    int i = mid;
    int j = end;
    int indexcopy = end;
    long count = 0;
    while(i >= begin && j >= mid + 1){
        if(data[i] > data[j]){
            copy[indexcopy --] = data[i --];
            count += j - mid;
        }
        else copy[indexcopy --] = data[j --];
    }
    for(; i >= begin; i --){
        copy[indexcopy --] = data[i];
    }
    for(; j >= mid + 1; j --){
        copy[indexcopy --] = data[j];
    }
    return count + leftcount + rightcount;
}

int InversePairs(vector<int> data) {
    if(data.size() == 0) return 0;
    vector<int> copy;
    for(int i = 0; i < data.size(); i ++){
        copy.push_back(data[i]);
    }
    return InversePairsCore(data, copy, 0, data.size() - 1) % 1000000007;
}
int main(int argc, const char * argv[]) {
    int a = (0 + 3) >> 1;
    cout<<a<<endl;
    return 0;
}
