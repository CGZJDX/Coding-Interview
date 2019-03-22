//
//  main.cpp
//  44
//
//  Created by 马宁 on 2019/2/27.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Reverse(string &str, int begin, int end){
    while(begin < end) swap(str[begin ++], str[end --]);
}

string ReverseSentence(string str) {
    int len = str.size();
    if(len == 0) return str;
    int begin = 0;
    str += ' ';
    for(int i = 0; i <= len; i ++){
        if(str[i] == ' '){
            Reverse(str, begin, i - 1);
            begin = i + 1;
        }
    }
    str = str.substr(0, len);
    Reverse(str, 0, len - 1);
    return str;
}

int main(int argc, const char * argv[]) {
    string str = "student. a am I";
    //string b = "student.";
    //Reverse(b, 0, b.size()-1);
    string b = ReverseSentence(str);
    for(int i = 0; i < b.size(); i ++){
        cout<<b[i];
    }
    /*Reverse(str, 0, str.size() - 1);
    for(int i = 0; i < str.size(); i ++){
        cout<<str[i];
    }*/
    cout<<endl;
    return 0;
}
