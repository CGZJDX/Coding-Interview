//
//  main.cpp
//  42
//
//  Created by 马宁 on 2019/3/7.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    /*vector<int> res;
    if(array.size() < 1) return res;
    int res1 = sum, res2 = sum;
    map<int, int> set;
    for(int i = 0; i < array.size(); i ++){
        int rest = sum - array[i];
        if(set.count(array[i])){
            if(res1 * res2 > array[set[array[i]]] * array[i]){
                res1 = array[set[array[i]]];
                res2 = array[i];
            }
        }
        else set[rest] = i;
    }
    if(set.size() != array.size()){
        res.push_back(res1);
        res.push_back(res2);
    }
    return res;*/
    vector<int> res;
    int length = array.size();
    if(length < 1) return res;
    int low = 0;
    int high = length - 1;
    while(low < high){
        int seqsum = array[low] + array[high];
        if(seqsum == sum){
            res.push_back(array[low]);
            res.push_back(array[high]);
            break;
        }
        else if(seqsum > sum) high --;
        else low ++;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> a;
    vector<int> array = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int sum = 21;
    a = FindNumbersWithSum(array, sum);
    cout<<a[0]<<","<<a[1]<<endl;
    return 0;
}
