#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    void reverseList(ListNode* inp, ListNode* outp){
        if(!inp) return;
        
        ListNode *temp;
        temp = inp;
        inp = inp->next;
        temp->next = outp;
        outp = temp;
    }
    ListNode* addTwoLists(ListNode* l1, ListNode* l2){
        int carry = 0, sum =0;
        ListNode* res;
        while( l1 != nullptr && l2 != nullptr){
            sum = carry + l1->val + l2->val;
            carry = sum/10;
            
            ListNode* temp = new ListNode(sum %10);
            temp->next = res;
            res = temp;            
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            sum = carry + l1->val;
            carry = sum/10;
            
            ListNode* temp = new ListNode(sum %10);            
            temp->next = res;
            res = temp;
            l1 = l1->next;
        }
        while(l2){
            sum = carry + l2->val;
            
            ListNode* temp = new ListNode(sum %10);
            carry = sum/10;
            
            temp->next = res;
            res = temp;
            l2 = l2->next;
        }
        if(carry !=0){
            ListNode* temp = new ListNode(carry);
            temp->next = res;    
            res = temp;        
        }
        
        return res;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1, *t2, *t3;
        
        reverseList(l1,t1);
        reverseList(l2,t2);
        
        ListNode* res = addTwoLists(t1,t2);
        reverseList(res, t3);
        
        return t3;        
    }
};


int main(){
    
}