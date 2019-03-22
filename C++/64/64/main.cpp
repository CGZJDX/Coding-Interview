//
//  main.cpp
//  64
//
//  Created by 马宁 on 2019/3/10.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        deque<int> win;
        vector<int> res;
        for(unsigned int i = 0; i < num.size(); i ++){
            while(!win.empty() && num[win.back()] < num[i]) win.pop_back();
            win.push_back(i);
            if(!win.empty() && i - win.front() + 1 > size) win.pop_front();
            if(size && i + 1 >= size) res.push_back(num[win.front()]);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    vector<int> num = {2, 3, 4, 2, 6, 2, 5, 1};
    unsigned int size = 3;
    vector<int> res;
    res = sol.maxInWindows(num, size);
    for(int i = 0; i < res.size(); i ++) cout<<res[i]<<",";
    cout<<endl;
    return 0;
}
