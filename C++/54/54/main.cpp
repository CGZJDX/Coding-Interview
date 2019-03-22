//
//  main.cpp
//  54
//
//  Created by 马宁 on 2019/3/9.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution
{
public:
    void Insert(char ch)
    {
        s += ch;
        hash[ch] ++;
        cout<<ch<<endl;
    }
    
    char FirstAppearingOnce()
    {
        for(int i = 0; i < s.size(); i ++){
            if(hash[s[i]] == 1) return s[i];
        }
        return '#';
    }
private:
    int hash[256] = {0};
    string s;
};

int main(int argc, const char * argv[]) {
    /*Solution solution;
    char ss[] = {"google"};
    for(int i = 0; i < strlen(ss); i ++){
        solution.Insert(ss[i]);
    }
    char s;
    s = solution.FirstAppearingOnce();
    cout<<s<<endl;*/
    return 0;
}
