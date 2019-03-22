//
//  main.cpp
//  5
//
//  Created by 马宁 on 2019/3/3.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

stack<int> stack1;
stack<int> stack2;

void push(int node) {
    stack1.push(node);
}

int pop() {
    int p;
    if(stack2.empty()){
    if(stack1.empty()) return NULL;
    while (! stack1.empty()) {
        p = stack1.top();
        stack1.pop();
        stack2.push(p);
    }
    }
    p = stack2.top();
    stack2.pop();
    return p;
}


int main(int argc, const char * argv[]) {
    for(int i = 0; i < 5; i ++){
        push(i);
    }
    for(int i = 0; i < 5; i ++){
    cout<<pop()<<endl;
    }
    return 0;
}
