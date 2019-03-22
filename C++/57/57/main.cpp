//
//  main.cpp
//  57
//
//  Created by 马宁 on 2019/3/13.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};*/

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if(pre.size() == 0) return NULL;
        TreeLinkNode* head = new TreeLinkNode(pre[0]);
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
    
    void createnext(TreeLinkNode* root){
        if(root == NULL) return;
        if(root -> left){
            TreeLinkNode* rootleft = root -> left;
            rootleft -> next = root;
        }
        if(root -> right){
            TreeLinkNode* rootright = root -> right;
            rootright -> next = root;
        }
        createnext(root -> left);
        createnext(root -> right);
    }
    
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        TreeLinkNode* pNext;
        if(pNode -> right){
            pNext = pNode -> right;
            while(pNext -> left) pNext = pNext -> left;
        }
        else{
            TreeLinkNode* pCur = pNode;
            TreeLinkNode* pPar = pNode -> next;
            while (pPar != NULL && pCur == pPar -> right) {
                pCur = pPar;
                pPar = pCur -> next;
            }
            pNext = pPar;
        }
        return pNext;
    }
    
    TreeLinkNode* FindNode(TreeLinkNode* pNode, int val){
        queue<TreeLinkNode*> treenode;
        TreeLinkNode* Node;
        treenode.push(pNode);
        while (!treenode.empty()) {
            Node = treenode.front();
            treenode.pop();
            if(Node -> val == val) return Node;
            if(Node -> left) treenode.push(Node -> left);
            if(Node -> right) treenode.push(Node -> right);
        }
        return Node;
    }

};

void print_tree_pre(TreeLinkNode * root){
    if(root){
        cout<<root -> val<<",";
        print_tree_pre(root -> left);
        print_tree_pre(root -> right);
    }
}

void print_tree_vin(TreeLinkNode * root){
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
    vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
    //vector<int> pre = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15};
    //vector<int> vin = {8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 15};
    Solution sol;
    TreeLinkNode* root;
    root = sol.reConstructBinaryTree(pre, vin);
    TreeLinkNode *p, *q;
    sol.createnext(root);
    //cout<<p -> right -> right -> left -> next -> val;
    //cout<<root -> right -> right -> left -> val;
    //cout<<p -> left -> left -> right -> val;
    p = sol.FindNode(root, 7);
    cout<<"p -> val = "<<p -> val<<endl;
    q = sol.GetNext(p);
    cout<<"q -> val = "<<q -> val;
    cout<<endl;
    return 0;
}

