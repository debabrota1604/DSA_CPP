// C++ program to insert a Node in a BST
#include <bits/stdc++.h>
using namespace std;

// Given Node
struct Node{
	int key;
	struct Node *left, *right;
    Node(int data):key(data), left(nullptr), right(nullptr){}
};

// Function to insert a new Node with given key in BST
Node* insert(Node* Node, int key){
	
	// If the tree is empty, return a new Node
	if (Node == nullptr) return new struct Node(key);

	// Otherwise, recur down the tree
	if (key < Node->key) Node->left = insert(Node->left, key);
	else if (key > Node->key) Node->right = insert(Node->right, key);

	// Return the Node pointer
	return Node;
}

// Utility function to search a key in a BST
Node* search(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == nullptr || root->key == key) return root;
 
    // Key is greater than root's key
    if (root->key < key) return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to do inorder traversal of BST
void inorder(Node* root){
	if (root != nullptr) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

// Function that returns the node with minimum key value found in that tree
Node* minValueNode(Node* node){
    Node* current = node;
 
    // Loop down to find the leftmost leaf
    while (current && current->left != nullptr) current = current->left;
 
    return current;
}
 
// Returns height of the BST
int height( Node* Node)
{
    if (Node == nullptr) return 0;
    else {
        // Compute the depth of each subtree
        int lDepth = height(Node->left);
        int rDepth = height(Node->right);
 
        // Use the larger one
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
 
// Print Nodes at a given level
void printGivenLevel( Node* root, int level){
    if (root == nullptr) return;
    if (level == 1) cout <<"  "<< root->key;
    else if (level > 1) { // Recursive Call
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}
 
// Function to line by line print level order traversal a tree
void printLevelOrder( Node* root){
    int i, h = height(root);
    for (i = 1; i <= h; i++) {
        printGivenLevel(root, i);
        cout <<"\n";
    }
}

// Function to print leaf Nodes from left to right
void printLeafNodes( Node* root)
{
    // If Node is null, return
    if (!root) return;
 
    // If Node is leaf Node, print its data
    if (!root->left && !root->right) {
        cout <<" "<< root->key;
        return;
    }
 
    // If left child exists, check for leaf recursively
    if (root->left) printLeafNodes(root->left);
 
    // If right child exists, check for leaf recursively
    if (root->right) printLeafNodes(root->right);
}

// Function to print all non-leaf nodes in a tree
void printNonLeafNode(Node* root){
    // Base Cases
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return;
 
    // If current node is non-leaf,
    if (root->left != nullptr || root->right != nullptr) cout <<" "<< root->key;
 
    // If root is Not nullptr and its one of its child is also not nullptr
    printNonLeafNode(root->left);
    printNonLeafNode(root->right);
}

// Function to print the right view of a binary tree.
void rightViewUtil(Node* root, int level, int* max_level){
    // Base Case
    if (root == nullptr) return;
 
    // If this is the last Node of its level
    if (*max_level < level) {
        cout <<"\t"<< root->key;
        *max_level = level;
    }
 
    // Recur for right subtree first, then left subtree
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}
 
// Wrapper over rightViewUtil()
void rightView(Node* root){
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}

// Function to print left view of binary tree
void leftViewUtil(Node* root, int level, int* max_level){
    if (root == nullptr) return;// Base Case
 
    // If this is the first node of its level
    if (*max_level < level) {
        cout <<"  "<< root->key;
        *max_level = level;
    }
 
    // Recur for left and right subtrees
    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
}
 
// Wrapper over leftViewUtil()
void leftView(Node* root) {
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}

// Function to get the total count of nodes in a binary tree
int nodeCount(Node* node){
    if (node == nullptr) return 0;
    else return nodeCount(node->left) + nodeCount(node->right) + 1;
}


// Function that deletes the key and returns the new root
Node* deleteNode(Node* root, int key){
    if (root == nullptr) return root;// base Case
 
    // If the key to be deleted is smaller than the root's key, then it lies in left subtree
    if (key < root->key) root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the root's key, then it lies in right subtree
    else if (key > root->key) root->right = deleteNode(root->right, key);
 
    // If key is same as root's key, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
 
        // Node with two children: Get the inorder successor(smallest in the right subtree)
        Node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to delete the BST
Node* emptyBST(Node* root){
    Node* temp;
    if (root != nullptr) {
        // Traverse to left subtree
        emptyBST(root->left);
 
        // Traverse to right subtree
        emptyBST(root->right);
 
        cout<<"\nDeleting Node: "<< root->key;
        temp = root;
 
        // Require for free memory
        delete temp;
    }
    return root;
}


/*
Balance a Binary Search Tree:
    A Simple Solution is to traverse nodes in Inorder and one by one insert into a self-balancing BST like AVL tree. Time complexity of this solution is O(n Log n) and this solution doesn’t guarantee the minimum possible height as in the worst case the height of the AVL tree can be 1.44*logn.

    An Efficient Solution can be to construct a balanced BST in O(n) time with minimum possible height. Below are steps. 
        Traverse given BST in inorder and store result in an array. This step takes O(n) time. Note that this array would be sorted as inorder traversal of BST always produces sorted sequence.
        Build a balanced BST from the above created sorted array using the recursive approach discussed here. This step also takes O(n) time as we traverse every element exactly once and processing an element takes O(1) time.
*/

/* This function traverse the skewed binary tree and stores its nodes pointers in vector nodes[] */
void storeBSTNodes(Node* root, vector<Node*> &nodes){
    if (root==nullptr) return; // Base case
   
    // Store nodes in Inorder (which is sorted order for BST)
    storeBSTNodes(root->left, nodes);
    nodes.push_back(root);
    storeBSTNodes(root->right, nodes);
}
 
/* Recursive function to construct binary tree */
Node* buildTreeUtil(vector<Node*> &nodes, int start, int end){
    if (start > end) return nullptr;    // base case
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    Node *root = nodes[mid];
 
    /* Using index in Inorder traversal, construct left and right subtress */
    root->left  = buildTreeUtil(nodes, start, mid-1);
    root->right = buildTreeUtil(nodes, mid+1, end);
 
    return root;
}
 
// This functions converts an unbalanced BST to a balanced BST
Node* buildTree(Node* root){
    // Store nodes of given BST in sorted order
    vector<Node *> nodes;
    storeBSTNodes(root, nodes);
 
    // Constructs BST from nodes[]
    int n = nodes.size();
    return buildTreeUtil(nodes, 0, n-1);
}

// Driver Code
int main()
{
	
	/* Let us create following BST 
		  50 
		/	 \ 
	   30	 70 
	  / \    / \ 
	20  40  60  80

    */
	struct Node* root = nullptr;

	// Inserting value 50
	root = insert(root, 50);

	// Inserting value 30
	insert(root, 30);

	// Inserting value 20
	insert(root, 20);

	// Inserting value 40
	insert(root, 40);

	// Inserting value 70
	insert(root, 70);

	// Inserting value 60
	insert(root, 60);

	// Inserting value 80
	insert(root, 80);

	// Print the BST
    cout << "Inorder traversal: ";
	inorder(root);
    cout << endl;

    cout << "Level order traversal: " << endl;
    printLevelOrder(root);

    cout << "Leaf Nodes: ";
    printLeafNodes(root);

    cout << "Non-leaf Nodes: ";
    printNonLeafNode(root);

    cout << "Smallest value Node: " << minValueNode(root) << endl;

    cout << "Searching for key 60: " << (search(root, 60) == nullptr ? "Absent":"Present") << endl;
    cout << "Searching for key 55: " << (search(root, 55) == nullptr ? "Absent":"Present") << endl;

    emptyBST(root);

	return 0;
}