//
//  main.cpp
//  23
//
//  Created by 马宁 on 2019/3/15.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        return IsBST(sequence, 0, sequence.size() - 1);
    }
    bool IsBST(vector<int> &sequence, int begin, int end){
        if(begin == end) return true;
        while(sequence[begin] < sequence[end]) begin ++;
        for(int i = begin; i < end; i ++){
            if(sequence[i] < sequence[end]) return false;
        }
        return IsBST(sequence, 0, begin - 1) && IsBST(sequence, begin, end - 1);
    }*/
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        int size = sequence.size();
        while (-- size) {
            int i = 0;
            while(sequence[i] < sequence[size]) i ++;
            while(sequence[i] > sequence[size]) i ++;
            if(i < size) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    /*int a[] = {1, 2, 3};
    int i = 0;
    while(a[i] < a[2]) i ++;
    cout<<i<<endl;*/
    vector<int> bst = {1, 3, 2, 6, 5, 4};
    Solution sol;
    cout<<sol.VerifySquenceOfBST(bst);
    cout<<endl;
    return 0;
}
