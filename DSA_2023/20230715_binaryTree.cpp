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
    void levelOrderTraversal(Node *root){
        queue<Node *> q;
        Node *temp;
        q.push(root);
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

    void mirrorImage(Node *root,Node *mirror){
        if(!root) return;
        mirror = new Node(root->data);
        mirrorImage(root->l, mirror->r);
        mirrorImage(root->r, mirror->l);
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

    void leftView(){
        // Idea is to do level order traversal and include seperators at each level.
        // After whole tree is inserted into the queue, print only the first element after seperators.

        queue<Node *> q;
        q.push(head);
        q.push(nullptr);

        // flag to identify starting node at each level
        bool f = true; // set to true initially to print the root node

        while(!q.empty()){
            Node *temp =  q.front();
            q.pop();
            if(!temp){
                if(!q.empty()) q.push(nullptr);
                f = true;
            }
            else{
                if(f) cout << temp->data << endl;
                f = false;
                if(temp->l) q.push(temp->l);
                if(temp->r) q.push(temp->r);
            }
        }
    }

    void rightView(){
        // Idea is to do level order traversal and include seperators at each level.
        // After whole tree is inserted into the queue, print only the last element before seperators.

        queue<Node *> q;
        q.push(head);
        q.push(nullptr);

        //This var holds the data of the last node before any seperator is encountered.
        int lastNode = head->data;

        while(!q.empty()){
            Node *temp =  q.front();
            q.pop();
            if(!temp){
                cout << lastNode << endl; //prints last node upon reaching a seperator
                if(!q.empty()) q.push(nullptr);
            }
            else{
                lastNode = temp->data; // Update the last node everytime a node is encountered before seperator
                if(temp->l) q.push(temp->l);
                if(temp->r) q.push(temp->r);
            }
        }
    }

    int height(Node *root){
        if(!root) return 0;
        return max(height(root->l), height(root->r)) +1;
    }

    int diameter(Node *root){
        if(!root) return 0;
        return max(diameter(root->l), max(diameter(root->r), height(root->l) + height(root->r) +1));
    }

    // This function reduces the extra O(n) call to height by passing the height value internally. 
    // Otherwise each node would call height function and total completexity would reach O(n^2).
    pair<int,int> fastDiameter(Node *root){
        if(!root) return make_pair(0,0);

        //first element in the pair is the diameter of the node, second is the height of the node
        //Check with the O(n^2) function for better understanding about final pair computation.
        auto res1 = fastDiameter(root->l);
        auto res2 = fastDiameter(root->r);
        int op1, op2, op3;
        op1 = res1.first;
        op2 = res2.first;
        op3 = res1.second + res2.second +1;
        return make_pair( max(op1,max(op2,op3)) , max(res1.second,res2.second) +1); 
    }

    bool isBalanced(Node *root){
        if(!root) return true;

        // The conditions for a balanced tree are:
        // 1. Both the subtrees should be balanced
        // 2. Height of both subtrees should be <=1
        
        bool cond = abs(height(root->l) -height(root->r)) <=1;
        return isBalanced(root->l) & isBalanced(root->r) & cond;
    }

    pair<bool, int> isBalancedFast(Node *root){
        // This function applies same trick like the fastDiameter function.
        // Check the O(n^2) function to get the algorithm. This version is optimization over that.
        if(!root) return make_pair(true, 0);
        auto p1 = isBalancedFast(root->l);
        auto p2 = isBalancedFast(root->r);

        bool cond = abs(p1.second - p2.second) <=1;

        return make_pair(p1.first & p2.first & cond, max(p1.second, p2.second));
    }

    pair<bool,int> isSumTree(Node *root){
        if(!root) return make_pair(true,0);

        auto p1 = isSumTree(root->l);
        auto p2 = isSumTree(root->r);

        bool cond = root->data == p1.second + p2.second;
        return make_pair(p1.first & p2.first & cond, root->data);
    }
};


int main(){
    Tree t;

    // 5 3 -1 4 -1 -1 6 7 2 -1 -1 -1 8 -1 -1 
    // Sum Tree: 14 7 3 1 -1 -1 2 -1 -1 4 -1 4 -1 -1 7 -1 7 3 -1 -1 4 4 -1 -1 -1

    t.head = t.buildTree(t.head);
    cout << "Level order traversal: " << endl;
    t.levelOrderTraversal(t.head);
    cout << "In order traversal: " << endl;
    t.inorderTraversal(t.head);
    cout << endl;
    cout << "Pre order traversal: " << endl;
    t.preorderTraversal(t.head);
    cout << endl;
    cout << "Post order traversal: " << endl;
    t.postorderTraversal(t.head);
    cout << endl;
    
    cout << "Left view of the tree: " << endl;
    t.leftView();
    cout << "Right view of the tree: " << endl;
    t.rightView();

    cout << "Mirror of the tree: " << endl;
    Node *mirror = nullptr;
    t.mirrorImage(t.head, mirror);
    // cout << "Level order traversal of mirror: " << endl;
    // t.levelOrderTraversal(mirror);


    cout << "Height of the tree: " << t.height(t.head) << endl;
    cout << "Diameter of the tree: " << t.diameter(t.head) << endl;
    cout << "Fast Diameter of the tree: " << t.fastDiameter(t.head).first << endl;
    cout << "is this tree balanced? " << t.isBalanced(t.head) << endl;
    cout << "is this tree balanced? [Optimal Computation] " << t.isBalancedFast(t.head).first << endl;
    cout << "is this sum Tree [sum of child is equal to parent]? " << t.isSumTree(t.head).first << endl;
}