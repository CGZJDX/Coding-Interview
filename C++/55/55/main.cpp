//
//  main.cpp
//  55
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
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    if(pHead == NULL) return NULL;
    ListNode* slow = pHead;
    ListNode* fast = pHead;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(fast == slow) break;
    }
    if (fast != slow) return NULL;
    ListNode* label = fast;
    int i = 1;
    while(label != fast -> next){
        fast = fast -> next;
        i ++;
    }
    slow = fast = pHead;
    while(i > 0){
        fast = fast -> next;
        i --;
    }
    while(fast != slow){
        fast = fast -> next;
        slow = slow -> next;
    }
    return fast;
}

int main(int argc, const char * argv[]) {
    vector<int> a = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
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
    ListNode* p = L;
    while(p -> next != NULL){
        p = p -> next;
    }
    p -> next = L -> next -> next -> next -> next -> next;
    //cout<<p -> next -> val<<endl;
    ListNode* t;
    t = EntryNodeOfLoop(L);
    cout<<"链表的环的入口结点为"<<t -> val<<endl;
    return 0;
}

