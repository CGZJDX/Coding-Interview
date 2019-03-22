//
//  main.cpp
//  32
//
//  Created by 马宁 on 2019/2/23.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
static bool cmp(int a, int b){
    string A = to_string(a) + to_string(b);
    string B = to_string(b) + to_string(a);
    return A < B;
}

string PrintMinNumber(vector<int> numbers) {
    if(numbers.size() == 0) return "";
    sort(numbers.begin(), numbers.end(), cmp);
    string res;
    for(int i = 0; i < numbers.size(); i ++){
        res += to_string(numbers[i]);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> a = {3, 32, 321};
    string res = PrintMinNumber(a);
    cout<<res<<endl;
    return 0;
}
