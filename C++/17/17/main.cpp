//
//  main.cpp
//  17
//
//  Created by 马宁 on 2019/3/11.
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

    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool res = false;
        if(pRoot1 != NULL && pRoot2 != NULL){
            if(pRoot1 -> val == pRoot2 -> val) res = HasSubTreeCore(pRoot1, pRoot2);
            if(!res) res = HasSubtree(pRoot1 -> left, pRoot2);
            if(!res) res = HasSubtree(pRoot1 -> right, pRoot2);
        }
        return res;
    }
    
    bool HasSubTreeCore(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2 == NULL) return true;
        if(pRoot1 == NULL) return false;
        if(pRoot1 -> val != pRoot2 -> val) return false;
        return HasSubTreeCore(pRoot1 -> left, pRoot2 -> left) && HasSubTreeCore(pRoot1 -> right, pRoot2 -> right);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
    Solution sol;
    TreeNode* root;
    root = sol.reConstructBinaryTree(pre, vin);
    vector<int> sub_pre = {3, 5, 6, 8};
    vector<int> sub_vin = {5, 3, 6, 8};
    TreeNode* sub_root;
    sub_root = sol.reConstructBinaryTree(sub_pre, sub_vin);
    bool sign;
    sign = sol.HasSubtree(root, sub_root);
    cout<<sign;
    cout<<endl;
    return 0;
}
