//
//  main.cpp
//  16
//
//  Created by 马宁 on 2019/2/28.
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
    cout<<"L -> val = "<<L -> val<<endl;
    cout<<"L -> next = "<<L -> next<<endl;
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

/*ListNode* Merge(ListNode* pHead1, ListNode* pHead2, Linklist &L)
{
    L = (LNode *)new(LNode);
    L -> val = NULL;
    L -> next = NULL;
    ListNode* head;
    ListNode* p;
    if(pHead1 -> val <= pHead2 -> val){
        head = pHead1;
        pHead1 = pHead1 -> next;
    }
    else{
        head = pHead2;
        pHead2 = pHead2 -> next;
    }
    p = head;
    cout<<&p<<endl<<&head<<endl;
    L -> next = p;
    while(pHead1 != NULL && pHead2 != NULL){
        if(pHead1 -> val <= pHead2 -> val){
            p -> next = pHead1;
            p = pHead1;
            if(head -> next == NULL) head -> next = p;
            pHead1 = pHead1 -> next;
        }
        else{
            p -> next = pHead2;
            p = pHead2;
            if(head -> next == NULL) head -> next = p;
            pHead2 = pHead2 -> next;
        }
    }
    while(pHead1 != NULL){
        p -> next = pHead1;
        p = pHead1;
        pHead1 = pHead1 -> next;
    }
    while(pHead2 != NULL){
        p -> next = pHead2;
        p = pHead2;
        pHead2 = pHead2 -> next;
    }
    L = L -> next;
    return head;
}*/
ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
    ListNode* head;
    if(pHead1 == NULL){
        return pHead2;
    }
    if(pHead2 == NULL){
        return pHead1;
    }
    if(pHead1 -> val <= pHead2 -> val){
        head = pHead1;
        pHead1 = pHead1 -> next;
        head -> next = Merge(pHead1, pHead2);
    }
    else{
        head = pHead2;
        pHead2 = pHead2 -> next;
        head -> next = Merge(pHead1, pHead2);
    }
    return head;
}

int main(int argc, const char * argv[]) {
    vector<int> a = {9, 8, 6, 4, 4, 0};
    vector<int> b = {8, 5, 5, 4, 2, 2};
    Linklist L;
    Linklist J;
    //Linklist k;
    create_list(L, a);
    create_list(J, b);
    cout<<"创建的单链表L为"<<endl;
    print_list(L);
    cout<<"创建的单链表J为"<<endl;
    print_list(J);
    /*ListNode* p;
    p = Merge(L, J);
    cout<<"合并后的单链表k为"<<endl;
    print_list(k);
    cout<<p -> next -> val<<endl;*/
    /*Linklist a, b, c, d;
    a = (Linklist)new(LNode);
    c = (Linklist)new(LNode);
    d = (Linklist)new(LNode);
    (*a).val = 4;
    c -> val = 2;
    d -> val = 3;
    a -> next = c;
    //cout<<a -> next -> val<<endl;
    cout<<(a -> val)<<endl;
    b = a;
    cout<<(a -> next)<<endl;
    cout<<(b -> next)<<endl;
    b -> next = d;
    //cout<<a -> next -> val<<endl;
    cout<<(a -> next)<<endl;
    cout<<(b -> next)<<endl;
    cout<<&(*c)<<endl<<&(*d)<<endl;
    cout<<c<<endl<<d<<endl;
    
    cout<<(a -> next)<<endl;
    cout<<(b -> next)<<endl;
    int aa = 2;
    int *bb = &aa;
    int *cc;
    cc = bb;
    cout<<cc<<endl<<&(*cc)<<endl<<&aa<<endl;
    cc += 1;
    cout<<*cc<<endl;
    cout<<*bb<<endl;*/
    return 0;
}
