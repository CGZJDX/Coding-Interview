//
//  main.cpp
//  6
//
//  Created by 马宁 on 2019/3/18.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0){
            return 0;
        }
        int left = 0;
        int right = rotateArray.size() - 1;
        int mid = 0;
        while (rotateArray[right] <= rotateArray[left]){
            if (right - left == 1){
                mid = right;
                break;
            }
            mid = left + (right - left)/2;
            if (rotateArray[left] == rotateArray[mid] && rotateArray[mid] == rotateArray[right]){
                int result = rotateArray[left];
                for(int i = left + 1; i < right; i ++){
                    if(rotateArray[i] <= result){
                        result = rotateArray[i];
                    }
                }
                return result;
            }
            if(rotateArray[left] <= rotateArray[mid]){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        return rotateArray[mid];
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    vector<int> a = {3, 4, 5, 1, 2};
    cout<<sol.minNumberInRotateArray(a);
    cout<<endl;
    return 0;
}
