#include<bits/stdc++.h>
using namespace std;

#define ESCKEY -1
class Node{
    public:
    int data;
    Node *l, *r;
    Node(int data){
        this->data = data;
    }
};

class Tree{
    public:
    Node *head;
    Tree(){
        head = nullptr;
    }
    Tree(int data){
        head = new Node(data);
    }
    Node * buildTree(Node *temp){
        int inp;
        cout << "Enter data: ";
        cin >> inp;

        if(inp == ESCKEY) return nullptr;
        temp = new Node(inp);

        cout << "Enter left child of " << inp << endl;
        temp->l = buildTree(temp->l);

        cout << "Enter right child of " << inp << endl;
        temp->r = buildTree(temp->r);

        return temp;
    }
    void levelOrderTraversal(){
        queue<Node *> q;
        Node *temp;
        q.push(head);
        q.push(nullptr);

        while(!q.empty()){
            temp = q.front();
            q.pop();

            if(!temp){ //found seperator
                cout << endl;
                if(!q.empty()){
                    //pushing seperator to print each level at seperate lines
                    q.push(nullptr);
                }
                continue;
            }

            cout << temp->data << " ";
            if(temp->l) q.push(temp->l);
            if(temp->r) q.push(temp->r); 
        }
    }

    void inorderTraversal(Node *root){
        if(root->l) inorderTraversal(root->l);
        cout << root->data << " ";
        if(root->r) inorderTraversal(root->r);
    }
    void preorderTraversal(Node *root){
        cout << root->data << " ";
        if(root->l) inorderTraversal(root->l);
        if(root->r) inorderTraversal(root->r);
    }
    void postorderTraversal(Node *root){
        if(root->l) inorderTraversal(root->l);
        if(root->r) inorderTraversal(root->r);
        cout << root->data << " ";
    }
};


int main(){
    Tree t;

    // 5 3 -1 4 -1 -1 6 7 -1 -1 8 -1 -1 

    t.head = t.buildTree(t.head);
    cout << "Level order traversal: " << endl;
    t.levelOrderTraversal();
    cout << "In order traversal: " << endl;
    t.inorderTraversal(t.head);
    cout << endl;
    cout << "Pre order traversal: " << endl;
    t.preorderTraversal(t.head);
    cout << endl;
    cout << "Post order traversal: " << endl;
    t.postorderTraversal(t.head);
    cout << endl;
}