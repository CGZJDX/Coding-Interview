//
//  main.cpp
//  49
//
//  Created by 马宁 on 2019/2/27.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        int n = str.size();
        if(not n) return 0;
        int s = 1;
        int res = 0;
        int test = 0;
        if(str[0] == '-') s = -1;
        for(int num = (str[0] == '+' || str[0] == '-') ? 1 : 0; num < n; num ++){
            if(str[num] < '0' || str[num] > '9') return 0;
            test = test * 10 + (int)(str[num] - '0') * s;
            if(test / 10 != res) return 0;
            res = res * 10 + (int)(str[num] - '0') * s;
            //if(res > INT_MAX || res < (INT_MAX + 1)) return 0;
        }
        return (int)res;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    string str = "2147483647";
    cout<<sol.StrToInt(str)<<endl;
    //char ss[100] = "0123456789";
    cout<<INT_MAX<<endl;
    return 0;
}
