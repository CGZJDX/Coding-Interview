//
//  main.cpp
//  60
//
//  Created by 马宁 on 2019/3/15.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
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
    
    /*vector<vector<int>> Print(TreeNode* pRoot) {
     vector<vector<int>> res;
     if(pRoot == NULL) return res;
     queue<TreeNode*> Node;
     Node.push(pRoot);
     while(!Node.empty()){
     vector<int> temp;
     int size = Node.size();
     for(int i = 0; i < size; i ++){
     temp.push_back(Node.front() -> val);
     if(Node.front() -> left) Node.push(Node.front() -> left);
     if(Node.front() -> right) Node.push(Node.front() -> right);
     Node.pop();
     }
     res.push_back(temp);
     }
     return res;
     }*/
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(pRoot == NULL) return res;
        PrintCore(pRoot, 0, res);
        return res;
    }
    
    void PrintCore(TreeNode* pRoot, int depth, vector<vector<int>> &res){
        if(pRoot == NULL) return;
        if(depth == res.size()) res.push_back(vector<int>{});
        res[depth].push_back(pRoot -> val);
        depth ++;
        PrintCore(pRoot -> left, depth, res);
        PrintCore(pRoot -> right, depth, res);
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

