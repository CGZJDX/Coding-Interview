//
//  main.cpp
//  62
//
//  Created by 马宁 on 2019/3/16.
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
    
    /*TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(k <= 0) return NULL;
        if(pRoot){
            TreeNode* pNode = KthNode(pRoot -> left, k);
            if(pNode) return pNode;
            if(++ count == k) return pRoot;
            cout<<count<<endl<<"pRoot -> val = "<<pRoot -> val<<endl;
            pNode = KthNode(pRoot -> right, k);
            if(pNode) return pNode;
        }
        return NULL;
    }
    
    int count = 0;*/
    /*TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == NULL || k <= 0) return NULL;
        return KthNodeCore(pRoot, k);
    }
    TreeNode* KthNodeCore(TreeNode* pRoot, int &k){
        TreeNode* pNode = NULL;
        if(pRoot -> left) pNode = KthNodeCore(pRoot -> left, k);
        if(pNode == NULL){
            if(k == 1) pNode = pRoot;
            k --;
        }
        if(pRoot -> right && pNode == NULL) pNode = KthNodeCore(pRoot -> right, k);
        return pNode;
    }*/
    
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == NULL || k <= 0) return NULL;
        int count = 1;
        stack<TreeNode*> Node;
        TreeNode* pNode = pRoot;
        while(pNode || !Node.empty()){
            while(pNode){
                Node.push(pNode);
                pNode = pNode -> left;
            }
            pNode = Node.top();
            Node.pop();
            if(k == count ++) return pNode;
            pNode = pNode -> right;
        }
        return NULL;
    }
    
};

int test(int** a){
    return **a *= 2;
}

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
    //vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    //vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
    //vector<int> pre = {1, 2, 3, 5, 6, 4, 7, 8, 2, 4, 8, 7, 3, 6, 5};
    //vector<int> vin = {5, 3, 6, 2, 7, 4, 8, 1, 8, 4, 7, 2, 6, 3, 5};
    vector<int> pre = {5, 3, 2, 1, 4, 7, 6, 8};
    vector<int> vin = {1, 2, 3, 4, 5, 6, 7, 8};
    Solution sol;
    TreeNode* root;
    root = sol.reConstructBinaryTree(pre, vin);
    root = sol.reConstructBinaryTree(pre, vin);
    TreeNode* p;
    p = sol.KthNode(root, 5);
    cout<<p -> val;
    cout<<endl;
    return 0;
}
