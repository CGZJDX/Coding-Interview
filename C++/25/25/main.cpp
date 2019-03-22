//
//  main.cpp
//  25
//
//  Created by 马宁 on 2019/2/28.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
typedef struct RandomListNode {
    int label;
    struct RandomListNode *next, *random = NULL;
}RandomNode, *RandomList;

void create_list(RandomList &L, vector<int> a){
    int len = a.size();
    RandomList p;
    L = (RandomNode *)new(RandomNode);
    L -> label = a[len - 1];
    L -> next = NULL;
    p = (RandomNode *)new(RandomNode);
    for(int i = 0; i < len - 1; i ++){
        p -> label = a[i];
        p -> next = L -> next;
        L -> next = p;
        p = (RandomNode *)new(RandomNode);
    }
}

void print_list(RandomList L){
    RandomList p;
    //cout<<"建立的单链表为"<<endl;
    //p = L -> next;
    p = L;
    while(p != NULL){
        cout<< p -> label;
        p = p -> next;
    }
    cout<<endl;
}
void print_random(RandomList L){
    RandomList p;
    //cout<<"建立的单链表为"<<endl;
    //p = L -> next;
    p = L;
    while(p != NULL){
        if(p -> random != NULL)
        cout<< p -> random -> label;
        p = p -> next;
    }
    cout<<endl;
}

void cloneNodes(RandomListNode* pHead){
    RandomListNode* pNode = pHead;
    while(pNode != NULL){
        RandomListNode* Node = (RandomNode *)new(RandomNode);
        Node -> next = pNode -> next;
        Node -> label = pNode -> label;
        Node -> random = NULL;
        pNode -> next = Node;
        pNode = Node -> next;
    }
}

void ConnectRandomNodes(RandomListNode* pHead){
    RandomListNode* pNode = pHead;
    while (pNode != NULL) {
        RandomListNode* Node = pNode -> next;
        if(pNode -> random != NULL){
            Node -> random = pNode -> random -> next;
        }
        pNode = Node -> next;
    }
}

RandomListNode* ReConnectNodes(RandomListNode* pHead){
    RandomListNode* pNode = pHead;
    RandomListNode* FirstHead = NULL;
    RandomListNode* SecondHead = NULL;
    if(pNode != NULL){
        pNode = pNode -> next;
        FirstHead = SecondHead = pNode;
        pNode -> next = SecondHead -> next;
        pNode = pNode -> next;
        //pNode = pNode -> next -> next;
    }
    if(pNode == SecondHead -> next) cout<<"相等"<<endl;
    while(pNode != NULL){
        SecondHead -> next = pNode -> next;
        SecondHead = SecondHead -> next;
        pNode -> next = SecondHead -> next;
        pNode = pNode -> next;
    }
    return FirstHead;
}

/*RandomListNode* Clone(RandomListNode* pHead)
{
    CloneNodes(pHead);
    ConnectRandomNodes(pHead);
    return ReConnectNodes(pHead);
}*/

int main(int argc, const char * argv[]) {
    vector<int> a = {9, 8, 6, 4, 3, 0};
    //vector<int> b = {8, 5, 5, 4, 2, 2};
    RandomList L;
    //RandomList J;
    //Linklist k;
    create_list(L, a);
    //create_list(J, b);
    cout<<"创建的单链表L为"<<endl;
    print_list(L);
    L -> next -> next -> random = L -> next;
    L -> next -> next -> next -> random = L -> next -> next -> next -> next;
    L -> next -> next -> next -> next -> random = L -> next -> next;
    L -> random = L -> next -> next -> next -> next -> next;
    cout<<"L的random为"<<endl;
    print_random(L);
    cout<<"复制后的单链表L为"<<endl;
    cloneNodes(L);
    print_list(L);
    cout<<"复制后L的random为"<<endl;
    print_random(L);
    cout<<"复制random后L的random为"<<endl;
    ConnectRandomNodes(L);
    print_random(L);
    cout<<"拆分后得到的单链表p为"<<endl;
    RandomListNode* p;
    p = ReConnectNodes(L);
    print_list(p);
    cout<<"拆分后p的random为"<<endl;
    print_random(p);
    //cout<<"创建的单链表J为"<<endl;
    //print_list(J);
    //cout<<L ->next ->next -> label<<endl;
    //p = ReConnectNodes(L);
    //p = Clone(L);
    /*cout<<"创建的单链表p为"<<endl;
    print_list(p);
    cout<<"p的random为"<<endl;
    print_random(p);*/
    return 0;
}
