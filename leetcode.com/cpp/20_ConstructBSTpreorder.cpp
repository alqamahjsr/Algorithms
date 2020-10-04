/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildBST(TreeNode* &root, int ele) {
        if(!root)
            return root = new TreeNode(ele);
        
        if(root->val > ele)
            root->left = buildBST(root->left, ele);
        else
            root->right = buildBST(root->right, ele);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode *root = NULL;
        
        for(auto x : pre)
            buildBST(root, x);
        
        return root;
    }

};