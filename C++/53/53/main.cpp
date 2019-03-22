//
//  main.cpp
//  53
//
//  Created by 马宁 on 2019/3/18.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string == NULL) return false;
        bool numeric = ScanInteger(string);
        if(*string == '.'){
            string ++;
            numeric = ScanUnsignedInteger(string) || numeric;
        }
        if(*string == 'e' || *string == 'E'){
            string ++;
            numeric = numeric && ScanInteger(string);
        }
        return numeric && *string == '\0';
    }
    
    bool ScanUnsignedInteger(char* &string){
        char *before = string;
        while (*string != '\0' && *string >= '0' && *string <= '9') string ++;
        return string > before;
    }
    bool ScanInteger(char* &string){
        if(*string == '+' || *string == '-') string ++;
        return ScanUnsignedInteger(string);
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    char* string = "123.45e+6";
    cout<<sol.isNumeric(string);
    cout<<endl;
    return 0;
}
