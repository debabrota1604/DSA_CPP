#include<iostream>
#include<list>
using namespace std;

listNode * deleteByLoc(listNode *l, listNode *p){
    ListNode * k = l;
    while(l!=nullptr){

        if (l==p){                  //A B C D            
            ListNode *temp = l->prev;
            if (temp != nullptr){
                temp->next = l->next;
                k = temp;
            }
            l = l->next;
            if (l->next != nullptr){
                l->prev = temp;
            }
            free(p);
            return k;
        }
        l = l->next;
    }
    return k;
}

int main(){


}