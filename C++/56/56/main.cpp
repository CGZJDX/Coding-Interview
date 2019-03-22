//
//  main.cpp
//  56
//
//  Created by 马宁 on 2019/3/2.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
typedef struct ListNode {
    int val = NULL;
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

ListNode* deleteDuplication(ListNode* pHead)
{
    if(pHead == NULL) return NULL;
    ListNode* Head = pHead;
    ListNode* First = NULL;
    ListNode* Second = NULL;
    while (Head != NULL) {
        if(Head -> next != NULL && Head -> val == Head -> next -> val){
            First = Head -> next;
            while(First -> next != NULL && First ->next -> val == Head -> val){
                    First = First -> next;
            }
            if(pHead == Head) pHead = First -> next;
            else Second -> next = First -> next;
            Head = First -> next;
        }
        else{
            Second = Head;
            Head = Head -> next;
        }
    }
    return pHead;
}
int main(int argc, const char * argv[]) {
    vector<int> a = {9, 8, 7, 7, 7, 6, 5, 4, 4, 3, 2, 2, 1, 1};
    //vector<int> b = {8, 5, 5, 4, 2, 2};
    Linklist L;
    //Linklist J;
    //Linklist k;
    create_list(L, a);
    //create_list(J, b);
    cout<<"创建的单链表L为"<<endl;
    print_list(L);
    //cout<<"创建的单链表J为"<<endl;
    //print_list(J);
    ListNode* p;
    p = deleteDuplication(L);
    cout<<"删除重复元素后得到的单链表p为"<<endl;
    print_list(p);
    return 0;
}
