//
//  main.cpp
//  52
//
//  Created by 马宁 on 2019/2/27.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    /*bool match(char* str, char* pattern)
    {
        if(str == NULL || pattern == NULL) return false;
        return matchcore(str, pattern);
    }
    
    bool matchcore(char* str, char* pattern){
        if(*str == '\0' && *pattern == '\0') return true;
        if(*str != '\0' && *pattern == '\0') return false;
        if(*(pattern + 1) == '*'){
            if(*pattern == *str || (*pattern == '.' && *str != '\0')){
                return matchcore(str, pattern + 2) || matchcore(str + 1, pattern + 2) || matchcore(str + 1, pattern);
            }
            else return matchcore(str, pattern + 2);
        }
        if(*pattern == *str || (*pattern == '.' && *str != '\0')) return matchcore(str + 1, pattern + 1);
        return false;
    }*/
    bool match(char* str, char* pattern){
        bool **dp = new bool* [strlen(str) + 1];
        for(int i = 0; i < strlen(str) + 1; i ++) dp[i] = new bool [strlen(pattern) + 1]();
        dp[strlen(str)][strlen(pattern)] = true;
        for(int i = strlen(str); i >= 0; i --){
            for(int j = strlen(pattern) - 1; j >= 0; j --){
                if(pattern[j + 1] == '*'){
                    if(i < strlen(str) && (str[i] == pattern[j] || pattern[j] == '.')){
                        dp[i][j] = dp[i][j + 2] || dp[i + 1][j] || dp[i + 1][j + 2];
                    }
                    else dp[i][j] = dp[i][j + 2];
                }
                else if(i < strlen(str) && (str[i] == pattern[j] || pattern[j] == '.')) dp[i][j] = dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }
};

int* test(int *&a){
    a ++;
    return a;
}
int* Test(int **a){
    (*a) ++;
    return *a;
}

int main(int argc, const char * argv[]) {
    //char* str = "aaa";
    char* str = "a";
    //cout<<strlen(str)<<endl;
    //char pattern[] = "a.a";
    //char pattern[] = "ab*ac*a";
    //char pattern[] = "aaa.";
    char pattern[] = ".*";
    Solution sol;
    //cout<<sol.match(str, pattern);
    //int **a = new int* [3];
    //cout<<a<<endl;
    /*for(int i = 0; i < 3; i ++){
        a[i] = new int[2];
    }
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 2; j ++){
            a[i][j] = (i + 1) * (j + 3);
        }
    }*/
   /*for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 2; j ++){
            cout<<a[i][j]<<",";
        }
        cout<<endl;
    }*/
    /*cout<<**a<<endl;
    cout<<*a[0]<<endl;
    cout<<*a<<endl;
    cout<<a<<endl;
    cout<<endl;*/
    /*int *p[3];
    int b[3][4];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j ++) b[i][j] = (i + 1) * (j + 1);
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j ++){
            cout<<b[i][j]<<",";
        }
        cout<<endl;
    }
    for(int i = 0; i < 3; i++)
        p[i] = b[i];
    cout<<*p<<endl;
    cout<<*p[0]<<endl;*/
    /*cout<<endl;
    char *ss = NULL;
    cout<<(ss == NULL);*/
    int b = 2;
    int *a = &b;
    int *c = a;
    cout<<a<<","<<c<<endl;
    cout<<*a<<endl;
    test(a);
    cout<<*a<<endl;
    cout<<a<<","<<c<<endl;
    cout<<*c<<endl;
    Test(&c);
    cout<<*c<<endl;
    cout<<endl;
    return 0;
}
