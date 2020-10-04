
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
    bool isValidSequence(TreeNode* root,int n,int pos,vector<int>& arr)
    {
        if(!root)
            return false;
        else if(pos==n)
            return false;
        else if(root->val!=arr[pos])
            return false;
        else if(!root->left && !root->right && pos==n-1)
            return true;
        
        return (isValidSequence(root->left,n,pos+1,arr) || isValidSequence(root->right,n,pos+1,arr));
    }
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = arr.size();
        int pos = 0;
        return isValidSequence(root,n,pos,arr);
    }
};