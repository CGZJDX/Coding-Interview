//
//  main.cpp
//  63
//
//  Created by 马宁 on 2019/3/9.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void Insert(int num)
    {
        if(p.empty() || num <= p.top()) p.push(num);
        else q.push(num);
        if(p.size() == q.size() + 2){
            q.push(p.top());
            p.pop();
        }
        if(q.size() == p.size() + 1){
            p.push(q.top());
            q.pop();
        }
    }
    
    double GetMedian()
    {
        return (p.size() > q.size()) ? p.top() : (p.top() + q.top()) / 2.0;
    }
private:
    priority_queue<int, vector<int>, less<int>> p;
    priority_queue<int, vector<int>, greater<int>> q;
};

int main(int argc, const char * argv[]) {
    /*vector<double>numbers{2.5,10.0,3.5,6.5,8.0,12.0,1.5,6.0};
    make_heap(begin(numbers), end(numbers), less<>());
    for(int i = 0; i < numbers.size(); i ++){
        cout<<numbers[i]<<",";
    }
    auto iter = is_heap_until(begin(numbers), end(numbers), less<>());
    if(iter != end(numbers))
        cout<<"numbers is a heap up to "<<*iter<<endl;
    else cout<<"numbers is a perfect heap"<<endl;
    cout<<endl;*/
    Solution sol;
    vector<int> a = {8, 0, 0, 18, 4, 6, 12, 14, 11, 20, 21};
    for(int i = 0; i < a.size(); i ++) sol.Insert(a[i]);
    double res;
    res = sol.GetMedian();
    cout<<res<<endl;
    return 0;
}
