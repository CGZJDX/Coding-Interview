//
//  main.cpp
//  61
//
//  Created by 马宁 on 2019/3/15.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
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
    
    char* Serialize(TreeNode *root) {
        if(root == NULL) return NULL;
        string str;
        SerializeCore(root, str);
        char* res = new char[str.length() + 1];
        for(int i = 0; i < str.length(); i ++) res[i] = str[i];
        res[str.length()] = '\0';
        return res;
    }
    
    void SerializeCore(TreeNode *root, string &str){
        if(root == NULL){
            str += ' ';
            str += ',';
            return;
        }
        string r = to_string(root -> val);
        str += r;
        str += ',';
        SerializeCore(root -> left, str);
        SerializeCore(root -> right, str);
    }
    
    TreeNode* Deserialize(char *str) {
        if(str == NULL) return NULL;
        TreeNode* root = DeserializeCore(&str);
        return root;
    }
    
    TreeNode* DeserializeCore(char** str){
        if(**str == ' '){
            (*str) ++;
            (*str) ++;
            return NULL;
        }
        int num = 0;
        while(**str != ',' && **str != '\0') {
            num = num * 10 + (**str - '0');
            (*str) ++;
        }
        TreeNode* root = new TreeNode(num);
        if(**str == '\0') return root;
        (*str) ++;
        root -> left = DeserializeCore(str);
        root -> right = DeserializeCore(str);
        return root;
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
    char* res;
    res = sol.Serialize(root);
    for(int i = 0; i < strlen(res); i ++) cout<<res[i];
    cout<<endl;
    TreeNode* p;
    p = sol.Deserialize(res);
    print_tree_pre(p);
    cout<<endl;
    print_tree_vin(p);
    cout<<endl;
    char a[4] = {'a', 'b', 'c', 'd'};
    cout<<strlen(a)<<endl;
    char b[] = "abc";
    cout<<strlen(b)<<endl;
    return 0;
}
