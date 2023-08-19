#include<iostream>
using namespace std;

struct listNode{
    int data;
    struct listNode *next;
};

class linkedListNoSTL{
    listNode *l;
    public:
        linkedListNoSTL(){l= new listNode;}
        linkedListNoSTL(int data){l= new listNode; l->data=data;}

        int leng(){
            int leng=0;
            for(auto cur=l;cur!=NULL; cur=cur->next){leng++;}
            return leng;
        }
        
        int disp(){
            int leng=0;
            for(auto cur=l;cur!=NULL; cur=cur->next) { cout << cur->data << " "; leng++; }
            cout <<endl;
            return leng;
        }
        
        int disp(listNode *t){
            int leng=0;
            for(auto cur=t;cur!=NULL; cur=cur->next) { cout << cur->data << " "; leng++; }
            cout <<endl;
            return leng;
        }
        
        listNode* insert(int pos, int data){
            cout << "Insert " << data << " at pos " << pos <<endl;
            listNode *temp= new listNode;
            temp->data = data;
            if (l==NULL){
                cout << "Creating first Node..." << endl;
                return temp;
            }
            else if (pos==0){ //insert at head
                temp->next = l; l=temp;
                return l;
            }
            else if (pos==-1){ //insert at tail
                auto i = l;
                for(;i->next!=NULL;i=i->next);
                i->next = temp;  
                return l;
            }
            else{//insert at middle
                if (pos> leng()){return l;}
                else{
                    int leng=pos; auto curr=l;
                    for(int i=0;i!=pos-1;i++){ curr = curr->next; }
                    temp->next = curr->next; curr->next = temp;
                    return l;
                }        
            }
            return NULL;
        }
        
        listNode* reverse(listNode *begl, listNode *endl){
            listNode *temp=begl, *newBeg=NULL;
            while (temp!=endl){
                if (l!= NULL) { begl=begl->next; }//change head to next node            
                temp->next=newBeg; //change temp next to new beg to reverse the node order
                newBeg = temp;    
                temp=begl; 
            }
            return newBeg;
        }
        
        void reverse(){
            listNode *temp=l, *newBeg=NULL;
            while (temp!=NULL){
                if (l!= NULL) { l=l->next; }//change head to next node            
                temp->next=newBeg; //change temp next to new beg to reverse the node order
                newBeg = temp;    
                temp=l; 
            }
            l = newBeg;
        }

        listNode* returnPointerToNodePosition(int position){
            if (position==0){
                return l;
            }
            else if (position==-1){
                auto temp=l;
                for (;temp->next!=NULL; temp=temp->next);
                return temp;
            }
            else{
                auto temp=l;
                while (position >0){
                    temp=temp->next;
                    position--;
                }
                return temp;
            }
        }
        
        int dataAtElement(listNode *n){ return n->data; }
        
        int isPalindrome(){ //O(n) runtime...
            //1. Traverse till node just before mid point
            //2. Reverse the future nodes and add to the list
            //3. take two pointers at head and mid and check one-by-one till the end.
            if ((leng()%2==0)){// type abba
                auto midPointerIndex = leng()/2 -1; auto tempPointer=l;
                for(auto index=midPointerIndex;index>0;--index) {tempPointer = tempPointer->next;} //reach the node pointing to the middle node. Here is the first b (index 1) in [a b b a]
                tempPointer->next  = reverse(tempPointer->next,NULL); //reverses the last half and add the reversed list to the first half.
                auto startPointer=l,midPointer=tempPointer->next;
                for(auto index=midPointerIndex;index>=0;--index){
                    if (startPointer->data != midPointer->data)
                        return false;
                }
                return true;
            }
            else{//type abcba
                auto midPointerIndex = int(leng()/2) -1; auto tempPointer=l;
                for(auto index=midPointerIndex;index>0;--index) {tempPointer = tempPointer->next;} //reach the node pointing to the middle node. Here is the first b (index 1) in [a b b a]
                tempPointer->next->next  = reverse(tempPointer->next->next,NULL); //reverses the last half and add the reversed list to the first half.
                auto startPointer=l,midPointer=tempPointer->next->next;
                for(auto index=midPointerIndex;index>=0;--index){
                    if (startPointer->data != midPointer->data)
                        return false;
                }
                return true;
            }
        }
};

int main(){
    linkedListNoSTL l(5);
    l.insert(-1,5);   l.disp();
    l.insert(0,1);    l.disp();
    l.insert(-1,1);   l.disp();
    l.insert(0,3);    l.disp();
    l.insert(-1,2);   l.disp();
    l.insert(3,7);    l.disp();
    l.reverse();      cout << "After reverse the list is: "; l.disp();

    //cout << "Element at 0 position is: " << l.dataAtElement(l.returnPointerToNodePosition(0)) <<endl;

    cout << "Palindrome or  not: " << (l.isPalindrome()? "Palindrome":"Not a palindrome!");


    return 0;
}