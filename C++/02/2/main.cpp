//
//  main.cpp
//  2
//
//  Created by 马宁 on 2019/2/26.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;
void replaceSpace(char *str,int length) {
    int strlength = 0;
    int replacelength = 0;
    int originallength = length;
    for(int i = 0; i < length; i ++){
        if(str[i] != ' ') continue;
        else strlength ++;
    }
    replacelength = length + 2 * strlength;
    originallength --;
    replacelength --;
    while(originallength >= 0 and replacelength > originallength){
        if(str[originallength] != ' ') str[replacelength --] = str[originallength --];
        else{
            originallength --;
            str[replacelength --] = '0';
            str[replacelength --] = '2';
            str[replacelength --] = '%';
        }
    }
}
int main(int argc, const char * argv[]) {
    char a[] = {'W', 'e', ' ', 'A', 'r', 'e', ' ', 'H', 'a', 'p', 'p', 'y'};
    int length = sizeof(a);
    cout<<length<<endl;
    replaceSpace(a, length);
    /*for(int i = 0; i < 17; i ++){
        cout<<a[i];
    }
    cout<<endl;*/
    return 0;
}
