//
//  main.cpp
//  14
//
//  Created by 马宁 on 2019/2/27.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

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

void print_list(Linklist L){
    Linklist p;
    cout<<"建立的单链表为"<<endl;
    p = L -> next;
    while(p != NULL){
        cout<< p -> val;
        p = p -> next;
    }
    cout<<endl;
}

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    /*int i = 0;
    ListNode* Node = pListHead;
    ListNode* node = pListHead;
    while(Node != NULL){
        i ++;
        Node = Node -> next;
    }
    cout<<"i="<<i<<endl;
    if(k > i) return NULL;
    int j = i - k;
    while(j > 0){
        node = node -> next;
        j --;
    }
    return node;*/
    cout<<"pListHead值为"<<pListHead -> val<<endl;
    if(pListHead == NULL) cout<<"pListHead为NULL"<<endl;
    if(pListHead == NULL || k == 0) return NULL;
    ListNode* FirstPointer = pListHead;
    ListNode* SecondPointer = pListHead;
    for(int i = 1; i < k; i ++){
        if(FirstPointer -> next == NULL) return NULL;
        FirstPointer = FirstPointer -> next;
    }
    while(FirstPointer -> next != NULL){
        FirstPointer = FirstPointer -> next;
        SecondPointer = SecondPointer -> next;
    }
    return SecondPointer;
}

int main(int argc, const char * argv[]) {
    Linklist L;
    vector<int> a = {5,4,3,2,1};
    create_list(L, a);
    cout<<"L的值为"<<L -> val<<endl;
    print_list(L);
    ListNode* node;
    node = FindKthToTail(L, 1);
    //node = FindKthToTail(NULL, 1);
    if(node != NULL) cout<<node->val<<endl;
    return 0;
}
