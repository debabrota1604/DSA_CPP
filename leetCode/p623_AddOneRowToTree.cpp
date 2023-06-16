#include<bits/stdc++.h>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
public:
    queue<TreeNode *> getLastLevelNodes(TreeNode* root, int depth){

        //Use queue to maintain the level order
        queue<TreeNode *> q; q.push(root); 
        int currDepth=1; vector<int> nodeCount(currDepth-1, 0); nodeCount[0]=1; //for root Node

        //traverse the nodes at each level
        while(currDepth <depth-1){

            //pop each node and add its child
            while(nodeCount[currDepth]>0){ 
                TreeNode*  tempNode = q.front(); q.pop();
                if(tempNode->left){ q.emplace(tempNode->left); nodeCount[currDepth+1]++;}
                if(tempNode->right) {q.emplace(tempNode->right);  nodeCount[currDepth+1]++;}
                nodeCount[currDepth]--;
            }
        }
        return q;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *t = new TreeNode(val,root,nullptr);
            root = t;
            return root;
        }
        else{
            queue<TreeNode *> lastParents = getLastLevelNodes(root, depth);

            //add new node to every parent in lastParents
            for(int it=0; it<lastParents.size();it++){
                TreeNode *temp = lastParents.front(); lastParents.pop();
                if(temp->left){
                    TreeNode* newLeft= new TreeNode(val, temp->left, nullptr);
                    temp->left = newLeft;
                }
                if(temp->right){
                    TreeNode* newRight= new TreeNode(val, nullptr, temp->right);
                    temp->right = newRight;
                }
            }
        }
        return root;
    }
};
