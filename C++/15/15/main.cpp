//
//  main.cpp
//  15
//
//  Created by 马宁 on 2019/2/28.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <vector>
using namespace std;
typedef struct ListNode {
    int val = 100;
    struct ListNode *next;
    /*ListNode(int x) :
     val(x), next(NULL) {
     }*/
}LNode, *Linklist;

void create_list(Linklist &L, vector<int> a){
    int len = a.size();
    Linklist p;
    L = (LNode *)new(LNode);
    L -> next = NULL;
    p = (LNode *)new(LNode);
    for(int i =0; i < len; i ++){
        p -> val = a[i];
        p -> next = L -> next;
        L -> next = p;
        p = (LNode *)new(LNode);
    }
}

/*void create_list(Linklist &L, vector<int> a){
    int len = a.size();
    Linklist p;
    L = (LNode *)new(LNode);
    L -> val = a[len - 1];
    L -> next = NULL;
    p = (LNode *)new(LNode);
    for(int i = 0; i < len - 1; i ++){
        p -> val = a[i];
        p -> next = L -> next;
        L -> next = p;
        p = (LNode *)new(LNode);
    }
}*/

void print_list(Linklist L){
    Linklist p;
    cout<<"建立的单链表为"<<endl;
    p = L -> next;
    //p = L;
    while(p != NULL){
        cout<< p -> val;
        p = p -> next;
    }
    cout<<endl;
}

void ReverseList(ListNode* pHead, Linklist &L) {
    //if(pHead == NULL) return NULL;
    L = (LNode *)new(LNode);
    pHead = pHead -> next;
    cout<<"pHead->val="<<pHead->val<<endl;
    ListNode* head = pHead;
    ListNode* next = NULL;
    ListNode* prev = NULL;
    while(head != NULL){
        next = head -> next;
        head -> next = prev;
        prev = head;
        head = next;
    }
    L -> next = prev;
    //return L;
}
int main(int argc, const char * argv[]) {
    vector<int> a = {5, 4, 3, 2, 1};
    Linklist L;
    Linklist J;
    create_list(L, a);
    print_list(L);
    ListNode* p;
    ReverseList(L, J);
    print_list(J);
    //cout<<"p->val="<<p->val<<endl;
    return 0;
}
