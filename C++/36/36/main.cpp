//
//  main.cpp
//  36
//
//  Created by 马宁 on 2019/3/2.
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
    //L -> val = 100;
    //cout<<"L -> val = "<<L -> val<<endl;
    //cout<<"L -> next = "<<L -> next<<endl;
    L -> val = a[len - 1];
    L -> next = NULL;
    p = (LNode *)new(LNode);
    for(int i = 0; i < len - 1; i ++){
        p -> val = a[i];
        p -> next = L -> next;
        L -> next = p;
        p = (LNode *)new(LNode);
    }
}

void print_list(Linklist L){
    Linklist p;
    //cout<<"建立的单链表为"<<endl;
    //p = L -> next;
    p = L;
    while(p != NULL){
        cout<< p -> val;
        p = p -> next;
    }
    cout<<endl;
}

int ListLen(ListNode* pHead){
    if(pHead == NULL) return 0;
    int len = 1;
    while(pHead != NULL){
        pHead = pHead -> next;
        len ++;
    }
    return len;
}

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    /*if(pHead1 == NULL || pHead2 == NULL) return NULL;
    int len1 = ListLen(pHead1);
    int len2 = ListLen(pHead2);
    int lendiff = len1 - len2;
    ListNode* longlist = pHead1;
    ListNode* shortlist = pHead2;
    if(len1 < len2){
        lendiff = len2 - len1;
        longlist = pHead2;
        shortlist = pHead1;
    }
    while(lendiff > 0){
        longlist = longlist -> next;
        lendiff --;
    }
    while(longlist != NULL && shortlist != NULL && longlist != shortlist){
        longlist = longlist -> next;
        shortlist = shortlist -> next;
    }
    if(longlist != NULL) return longlist;
    return NULL;*/
    if(pHead1 == NULL || pHead2 == NULL) return NULL;
    ListNode* p1 = pHead1;
    ListNode* p2 = pHead2;
    while(p1 != p2){
        p1 = (p1 -> next != NULL) ? p1 -> next : pHead2;
        p2 = (p2 -> next != NULL) ? p2 -> next : pHead1;
    }
    return (p1 != NULL) ? p1 : NULL;
}

int main(int argc, const char * argv[]) {
    vector<int> a = {9, 8, 6, 4, 4, 0};
    vector<int> b = {8, 5, 5, 4, 2, 2};
    Linklist L;
    Linklist J;
    //Linklist k;
    create_list(L, a);
    create_list(J, b);
    /*cout<<"创建的单链表L为"<<endl;
    print_list(L);
    cout<<"创建的单链表J为"<<endl;
    print_list(J);*/
    J -> next -> next -> next -> next = L -> next -> next -> next;
    cout<<"创建的单链表L为"<<endl;
    print_list(L);
    cout<<"创建的单链表J为"<<endl;
    print_list(J);
    ListNode* p;
    p = FindFirstCommonNode(L, J);
    cout<<"P -> val = "<<p -> val<<endl;
    return 0;
}
