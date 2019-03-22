//
//  main.cpp
//  39
//
//  Created by 马宁 on 2019/3/12.
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
    
    /*bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL) return true;
        queue<TreeNode*> node;
        node.push(pRoot);
        while (!node.empty()) {
            int size = node.size();
            for(int i = 0; i < size; i ++){
                TreeNode* tree = node.front();
                node.pop();
                if(TreeDepth(tree -> left) - TreeDepth(tree -> right) > 1 || TreeDepth(tree -> left) - TreeDepth(tree -> right) < -1) return false;
                if(tree -> left) node.push(tree -> left);
                if(tree -> right) node.push(tree -> right);
            }
        }
        return true;
    }
    
    int TreeDepth(TreeNode* pRoot){
        if(pRoot == NULL) return 0;
        int left = TreeDepth(pRoot -> left);
        int right = TreeDepth(pRoot -> right);
        return (left > right) ? left + 1 : right + 1;
    }*/
    
    bool IsBalanced(TreeNode *root, int & dep){
        if(root == NULL){
            return true;
        }
        cout<<dep<<endl;
        int left = 0;
        int right = 0;
        //cout<<left<<endl;
        if(IsBalanced(root->left,left) && IsBalanced(root->right, right)){
            //cout<<"left "<<left<<endl;
            //cout<<"right "<<right<<endl;
            cout<<"dep "<<dep<<endl;
            int dif = left - right;
            if(dif<-1 || dif >1)
                return false;
            dep = (left > right ? left : right) + 1;
            //cout<<dep<<endl;
            return true;
        }
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int dep = 0;
        return IsBalanced(pRoot, dep);
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

void test(int& temp){
    temp ++;
}
 
int main(int argc, const char * argv[]) {
    //vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    //vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
    vector<int> pre = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15};
    vector<int> vin = {8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 15};
    Solution sol;
    TreeNode* root;
    root = sol.reConstructBinaryTree(pre, vin);
    /*print_tree_pre(root);
    cout<<endl;
    print_tree_vin(root);
    cout<<endl;*/
    bool sign;
    sign = sol.IsBalanced_Solution(root);
    //cout<<sign;
    cout<<endl;
    //int b = 0;
    //test(b);
    //cout<<b<<endl;
    return 0;
}

