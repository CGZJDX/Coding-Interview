//
//  main.cpp
//  1
//
//  Created by 马宁 on 2019/3/18.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows = array.size();
        int cols = array[0].size();
        if(rows > 0 and cols > 0){
            int row = 0;
            int col = cols - 1;
            while(row < rows && col >= 0){
                if(array[row][col] == target){
                    return true;
                }
                else if(array[row][col] > target){
                    col --;
                }
                else{
                    row ++;
                }
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    vector<vector<int>> a(4);
    for(int i = 0; i < a.size(); i ++) a[i].resize(4);
    for(int i = 0; i < a.size(); i ++){
        for(int j = 0; j < a[i].size(); j ++) a[i][j] = i * 4 + j;
    }
    for(int i = 0; i < a.size(); i ++){
        for(int j = 0; j < a[i].size(); j ++){
            cout<<a[i][j]<<",";
        }
        cout<<endl;
    }
    cout<<sol.Find(16, a);
    cout<<endl;
    return 0;
}
