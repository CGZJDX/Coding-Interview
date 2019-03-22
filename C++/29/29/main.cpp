//
//  main.cpp
//  29
//
//  Created by 马宁 on 2019/3/6.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void HeapSortCore(vector<int> &input, int s, int m){
    int temp = input[s];
    int i = s * 2 + 1;
    while(i <= m){
        if(i < m && input[i] < input[i + 1]) i ++;
        if(temp >= input[i]) break;
        input[s] = input[i];
        //input[i] = temp;
        s = i;
        i = s * 2 + 1;
    }
    input[s] = temp;
}

vector<int> HeapSort(vector<int> &input){
    int s = input.size() / 2 - 1;
    int m = input.size() - 1;
    for(int i = s; i >= 0; i --){
        HeapSortCore(input, i, m);
    }
    for(int j = m; j >= 1; j --){
        swap(input[0], input[j]);
        HeapSortCore(input, 0, j - 1);
    }
    return input;
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> res;
    bool change = true;
    int length = input.size();
    if(length == 0 || k <= 0 || k > length) return res;
    for(int i = 0; i <= length; i ++){
        if(res.size() < k) res.push_back(input[i]);
        else{
            if(change) HeapSort(res);
            if(i != length && input[i] < res[k - 1]){
                res[k - 1] = input[i];
                change = true;
            }
        }
    }
    return res;
}

/*vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
}*/
int main(int argc, const char * argv[]) {
    //vector<int> a = {4, 1, 7, 3, 8, 5, 9, 2, 6, 0, 123, 22};
    vector<int> a = {4, 5, 1, 6, 2, 7, 3, 8};
    /*vector<int> c = HeapSort(a);
    for(int i = 0; i < c.size(); i ++){
        cout<<c[i]<<",";
    }
    cout<<endl;*/
    vector<int> b = GetLeastNumbers_Solution(a, 8);
    for(int i = 0; i < b.size(); i ++){
        cout<<b[i]<<",";
    }
    cout<<endl;
    return 0;
}
    /*for(int i = k / 2 - 1; i >= 0; i --){
     HeapSortCore(res, i, k - 1);
     }
     for(int j = k - 1; j >= 1; j --){
     swap(res[0], res[j]);
     HeapSortCore(res, 0, j - 1);
     }
     change = false;*/
