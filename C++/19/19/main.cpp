//
//  main.cpp
//  19
//
//  Created by 马宁 on 2019/3/6.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
    int left = 0, right = matrix.size() - 1;
    int top = 0, bottom = matrix[0].size() - 1;
    vector<int> res;
    if(right <= 0 || bottom <= 0) return res;
    while(left <= right && top <= bottom){
        for(int i = left; i <= right; i ++){
            res.push_back(matrix[top][i]);
        }
        for(int i = top + 1; i <= bottom; i ++){
            res.push_back(matrix[i][right]);
        }
        if(top != bottom){
            for(int i = right - 1; i >= left; i --){
                res.push_back(matrix[bottom][i]);
            }
        }
        if(left != right){
            for(int i = bottom - 1; i > top; i --){
                res.push_back(matrix[i][left]);
            }
        }
        left ++;
        right --;
        top ++;
        bottom --;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix(4);
    for(int i = 0; i < matrix.size(); i ++){
        matrix[i].resize(3);
    }
    cout<<matrix.size()<<endl;
    cout<<matrix[0].size()<<endl;
    for(int i = 0; i < matrix.size(); i ++){
        for(int j = 0; j < matrix[0].size(); j ++){
            matrix[i][j] = (j + 1) + i * 4;
        }
    }
    for(int i = 0; i < matrix.size(); i ++){
        for(int j = 0; j < matrix[0].size(); j ++){
            cout<<matrix[i][j]<<endl;
        }
    }
    /*vector<int> res;
    res = printMatrix(matrix);
    for(int i = 0; i < res.size(); i ++){
        cout<<res[i]<<",";
    }
    cout<<endl;*/
    
    return 0;
}
