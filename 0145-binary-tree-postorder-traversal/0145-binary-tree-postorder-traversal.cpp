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
        prei(root->right, pre);
        pre.push_back(root->val);
    }



    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> pre;
        prei(root, pre);
        return pre;
    }
};