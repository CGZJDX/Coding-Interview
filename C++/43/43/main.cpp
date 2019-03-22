//
//  main.cpp
//  43
//
//  Created by 马宁 on 2019/2/27.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;

void Rotate(string &str, int begin, int end){
    while(begin < end){
        swap(str[begin ++], str[end --]);
    }
}
string LeftRotateString(string str, int n) {
    if(str.length() == 0) return str;
    if(n <= 0 || n > str.length() - 1) return str;
    //string res = str;
    int FirstBegin = 0, FirstEnd = n - 1;
    int SecondBegin = n, SecondEnd = str.length() - 1;
    Rotate(str, FirstBegin, FirstEnd);
    Rotate(str, SecondBegin, SecondEnd);
    Rotate(str, FirstBegin, SecondEnd);
    return str;
}

int main(int argc, const char * argv[]) {
    string a = "abcXYZdef";
    //string b = LeftRotateString(a, 2);
    string b = a.substr(2, 5);
    for(int i = 0; i < b.length(); i ++){
        cout<<b[i];
    }
    cout<<endl;
    return 0;
}
