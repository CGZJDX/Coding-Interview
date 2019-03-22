//
//  main.cpp
//  59
//
//  Created by 马宁 on 2019/3/14.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//



#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if(pre.size() == 0) return NULL;
        TreeNode* head = new TreeNode(pre[0]);
        vector<int> left_pre, left_vin, right_pre, right_vin;
        int root;
        for(int i = 0; i < pre.size(); i ++){
            if(vin[i] == pre[0]){
                root = i;
                break;
            }
        }
        for(int i = 0; i < root; i ++){
            left_pre.push_back(pre[i + 1]);
            left_vin.push_back(vin[i]);
        }
        for(int i = root + 1; i < pre.size(); i ++){
            right_pre.push_back(pre[i]);
            right_vin.push_back(vin[i]);
        }
        head -> left = reConstructBinaryTree(left_pre, left_vin);
        head -> right = reConstructBinaryTree(right_pre, right_vin);
        return head;
    }
    
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(pRoot == NULL) return res;
        stack<TreeNode*> stack1, stack2;
        stack1.push(pRoot);
        while (!stack1.empty() || !stack2.empty()) {
            vector<int> temp;
            if(!stack1.empty()) {
                while(!stack1.empty()){
                    temp.push_back(stack1.top() -> val);
                    if(stack1.top() -> left) stack2.push(stack1.top() -> left);
                    if(stack1.top() -> right) stack2.push(stack1.top() -> right);
                    stack1.pop();
                }
                res.push_back(temp);
            }
            else{
                while(!stack2.empty()){
                    temp.push_back(stack2.top() -> val);
                    if(stack2.top() -> right) stack1.push(stack2.top() -> right);
                    if(stack2.top() -> left) stack1.push(stack2.top() -> left);
                    stack2.pop();
                }
                res.push_back(temp);
            }
        }
        return res;
    }
    
};

void print_tree_pre(TreeNode * root){
    if(root){
        cout<<root -> val<<",";
        print_tree_pre(root -> left);
        print_tree_pre(root -> right);
    }
}

void print_tree_vin(TreeNode * root){
    if(root){
        print_tree_vin(root -> left);
        cout<<root -> val<<",";
        print_tree_vin(root -> right);
    }
}

int main(int argc, const char * argv[]) {
    vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
    //vector<int> pre = {1, 2, 3, 5, 6, 4, 7, 8, 2, 4, 8, 7, 3, 6, 5};
    //vector<int> vin = {5, 3, 6, 2, 7, 4, 8, 1, 8, 4, 7, 2, 6, 3, 5};
    Solution sol;
    TreeNode* root;
    root = sol.reConstructBinaryTree(pre, vin);
    root = sol.reConstructBinaryTree(pre, vin);
    vector<vector<int>> res;
    res = sol.Print(root);
    for(int i = 0; i < res.size(); i ++){
        for(int j = 0; j < res[i].size(); j ++) cout<<res[i][j]<<",";
    }
    cout<<endl;
    return 0;
}
