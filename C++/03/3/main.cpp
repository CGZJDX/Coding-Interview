//
//  main.cpp
//  3
//
//  Created by 马宁 on 2019/2/27.
//  Copyright © 2019年 Larry_Ma. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
            int val;
            struct ListNode *next;
            ListNode(int x) :
                  val(x), next(NULL) {
                }
      };
vector<int> printListFromTailToHead(ListNode* head) {
    ListNode *Node = head;
    vector<int> arraylist;
    while(Node != NULL){
        arraylist.push_back(Node -> val);
        Node = Node -> next;
    }
    reverse(arraylist.begin(), arraylist.end());
    return arraylist;
}
int main(int argc, const char * argv[]) {
    vector<int> a = {1,2,3,4,5};
    reverse(a.begin(), a.end());
    for(int i = 0; i < a.size(); i ++){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
