//
//  main.cpp
//  24
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
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == NULL || root -> val > expectNumber) return res;
        temp.push_back(root -> val);
        if(root -> val == expectNumber && root -> left == NULL && root -> right == NULL) res.push_back(temp);
        if(root -> left) FindPath(root -> left, expectNumber - root -> val);
        if(root -> right) FindPath(root -> right, expectNumber - root -> val);
        temp.pop_back();
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> temp;
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
    //vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    //vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
    vector<int> pre = {1, 9, 2, 7, 8};
    vector<int> vin = {9, 1, 7, 2, 8};
    Solution sol;
    TreeNode* root;
    root = sol.reConstructBinaryTree(pre, vin);
    vector<vector<int>> res;
    //res = sol.FindPath(root, 10);
    vector<int> A = {1,2,2};
    vector<int> B = {2,4};
    vector<int> C = {1,2,3,8};
    res.push_back(A);
    res.push_back(B);
    res.push_back(C);
    sort(res.begin(), res.end(), [](vector<int> a, vector<int> b){return a.size() > b.size();});
    for(int i = 0; i < res.size(); i ++){
        for(int j = 0; j < res[i].size(); j ++){
            cout<<res[i][j]<<",";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}

