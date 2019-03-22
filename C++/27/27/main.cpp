//
//  main.cpp
//  27
//
//  Created by 马宁 on 2019/2/26.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> result;
void PermutationCore(string str, int begin){
    if(begin == str.length() - 1){
        result.push_back(str);
        return;
    }
    int length = str.length();
    for(int i = begin; i < length; i ++){
        if(i != begin && str[i] == str[begin]) continue;
        swap(str[begin], str[i]);
        PermutationCore(str, begin + 1);
    }
}

vector<string> Permutation(string str) {
    
    if(str.length() == 0) return result;
    PermutationCore(str, 0);
    sort(result.begin(), result.end());
    return result;
}

int main(int argc, const char * argv[]) {
    string str = {"abc"};
    Permutation(str);
    /*for(int i = 0; i < 6; i ++){
        cout<<result[i]<<endl;
    }*/
    //cout<<sizeof(result)<<endl;
    return 0;
}
