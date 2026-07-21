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
 class Solution {
public:
    void prei(TreeNode* root, vector<int> &pre){
        if(!root){
            return;
        }
        prei(root->left, pre);
        pre.push_back(root->val);
        prei(root->right, pre);
    }



    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> pre;
        prei(root, pre);
        return pre;
    }
};