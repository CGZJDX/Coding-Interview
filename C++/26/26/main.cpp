//
//  main.cpp
//  26
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
    
    /*TreeNode* Convert(TreeNode* pRootOfTree){
        if(pRootOfTree == NULL) return NULL;
        TreeNode* pNode = NULL;
        ConvertCore(pRootOfTree, pNode);
        while(pNode -> left) pNode = pNode -> left;
        return pNode;
    }
    void ConvertCore(TreeNode* pRootOfTree, TreeNode* &pNode){
        if(pRootOfTree == NULL) return;
        ConvertCore(pRootOfTree -> left, pNode);
        pRootOfTree -> left = pNode;
        if(pNode) pNode -> right = pRootOfTree;
        pNode = pRootOfTree;
        ConvertCore(pRootOfTree -> right, pNode);
    }*/
    TreeNode* Convert(TreeNode* pRootOfTree){
        if(pRootOfTree == NULL) return NULL;
        stack<TreeNode*> pNode;
        TreeNode* pCur = pRootOfTree;
        TreeNode* pPre = NULL;
        bool isfirst = true;
        while(pCur || !pNode.empty()){
            while (pCur) {
                pNode.push(pCur);
                pCur = pCur -> left;
            }
            pCur = pNode.top();
            pNode.pop();
            if(isfirst){
                pRootOfTree = pCur;
                pPre = pRootOfTree;
                isfirst = false;
            }
            else{
                pPre -> right = pCur;
                pCur -> left = pPre;
                pPre = pCur;
            }
            pCur = pCur -> right;
        }
        return pRootOfTree;
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
    TreeNode* pNode;
    TreeNode* pnode;
    pNode = sol.Convert(root);
    while (pNode) {
        pnode = pNode;
        cout<<pNode -> val<<",";
        pNode = pNode -> right;
    }
    cout<<endl;
    while (pnode) {
        cout<<pnode -> val<<",";
        pnode = pnode -> left;
    }
    cout<<endl;
    return 0;
}

