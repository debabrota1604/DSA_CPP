#include<bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) { cout << "Executing default constructor...\n" << endl; }
    ListNode(int x) : val(x), next(nullptr) {cout << "Executing param1 constructor...\n" << endl; }
    ListNode(int x, ListNode *next) : val(x), next(next) {cout << "Executing param2 constructor...\n" << endl; }
 };

 
class Solution {
    ListNode *head;
public:
    ListNode* constructList(vector<int> v){
        for(auto i=0;i<v.size();i++){
            if (i==0){
                head = new ListNode(v[i]);
            }
            else{
                ListNode *tempNode = new ListNode(v[i],head);
                head = tempNode;
            }
        }
        return head;
    }


    bool isPalindrome(ListNode* head) {
        // Algorithm:
        // 1. Measure the length of the linked list. -> in O(n)
        // 2. Declare a stack of len/2 size to match pattern. -> O(1)
        // 3. traverse the list from head to middle to populate the stack. ->O(n)
        // 4. Check if the reverse pattern exists from middle to end by popping off from stack. ->O(n)
        // 5. Take care of even and odd length. ->O(1)
        // Total runtime = O(n), Total Space = O(n)

        //size(n)| n-1 | <n/2 |needed| < (n+1)/2 } | <=(n-1)/2
            // 5       4      2       2       2           2
            // 6       5      2       3       3           2
            // 7       6      3       3       3           3
            // 8       7      3       4       4           3

        int listLen=0, lenItr;

        //measure list size
        for(auto iter = head; iter !=nullptr; iter = iter->next) { listLen +=1; cout << iter->val << " ";}
        cout << "ListLen: " << listLen << endl;
        cout << "Mid: " << (listLen+1)/2 << endl;

        stack<int> st; auto midPtr = head;

        //insert first half list elements to stack
        for(midPtr = head; lenItr <(listLen+1)/2; midPtr = midPtr->next, lenItr+=1){
            st.push(midPtr->val);
        }
        cout << midPtr->val << endl;

        //fix for odd length palindrome
        if (listLen%2==1) midPtr = midPtr->next;

        //pop from stack and check with list value
        for(;midPtr !=nullptr;midPtr = midPtr->next){
            int stackEl = st.top(); st.pop(); cout << stackEl << " " << endl;
            if (stackEl != midPtr->val) return false;
        }
        return true;
    }
};

int main(){
    vector<int> v {1, 2, 3, 4};
    
    Solution s;

    cout << s.isPalindrome(s.constructList(v)) << endl;

    return 0;
}