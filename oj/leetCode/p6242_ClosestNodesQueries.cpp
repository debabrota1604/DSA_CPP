#include<bits/stdc++.h>
using namespace std;


//  Definition for a binary tree node.
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
    void getLargestMin(TreeNode* root, int q, int& res){
        if(root == nullptr) return;
        else if(root->val <=q && root->val >res) res= root->val;
        getLargestMin(root->left,q,res);
        getLargestMin(root->right,q,res);
    }
    void getSmallestMax(TreeNode* root, int q, int& res){
        cout << "getSmallestMax: RootVal: " << root->val << " Res: " << res << endl;
        if(root == nullptr) return;
        else if(root->val >=q){ 
            if(res==-1 || root->val <res) res= root->val;
        }
        getLargestMin(root->left,q,res);
        getLargestMin(root->right,q,res);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> res;
        for(int i=0; i<queries.size(); i++){
            vector<int> subRes; int lMin=-1, sMax=-1; 
            getLargestMin(root, queries[i], lMin);
            getSmallestMax(root, queries[i], sMax);
            subRes.emplace_back(lMin);
            subRes.emplace_back(sMax);
            res.emplace_back(subRes);
        }
        return res;
    }
};


int main(){




    return 0;
}