//
//  main.cpp
//  4
//
//  Created by 马宁 on 2019/3/10.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
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
    Solution sol;
    TreeNode* root;
    root = sol.reConstructBinaryTree(pre, vin);
    print_tree_pre(root);
    cout<<endl;
    print_tree_vin(root);
    cout<<endl;
    return 0;
}
