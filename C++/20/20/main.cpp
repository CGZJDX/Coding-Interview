//
//  main.cpp
//  20
//
//  Created by 马宁 on 2019/3/4.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

stack<int>stack1, stack2;

void push(int value) {
    stack1.push(value);
    if(stack2.empty() || stack2.top() >= value){
        stack2.push(value);
    }
}
void pop() {
    if(stack2.top() == stack1.top()) stack2.pop();
    stack1.pop();
}
int top() {
    return stack1.top();
}
int min() {
    return stack2.top();
}
int main(int argc, const char * argv[]) {
    int a[] = {1,2,3,4,1,2,5,0};
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i ++){
        push(a[i]);
    }
    cout<<min()<<endl;
    for(int i = 0; i < 4; i ++){
        pop();
    }
    cout<<min()<<endl;
    cout<<top()<<endl;
    return 0;
}
