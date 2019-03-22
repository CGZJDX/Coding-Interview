//
//  main.cpp
//  13
//
//  Created by 马宁 on 2019/3/18.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        /*for(int i = 0; i < array.size(); i ++){
         if(abs(array[i]) % 2 == 1){
         int k = i;
         int temp = array[i];
         for(int j = i; j >= 1; j --){
         if(abs(array[j - 1]) % 2 == 0){
         array[j] = array[j - 1];
         k = j - 1;
         }
         else break;
         }
         array[k] = temp;
         }
         }*/
        deque<int>res;
        int len = array.size();
        for(int i = 0; i < len; i ++){
            if(abs(array[i]) % 2 == 0){
                res.push_back(array[i]);
            }
            if(abs(array[len - 1 - i]) % 2 == 1){
                res.push_front(array[len - 1 - i]);
            }
        }
        array.assign(res.begin(), res.end());
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
