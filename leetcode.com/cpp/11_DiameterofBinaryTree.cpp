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
     int depth(TreeNode *p, int& ans){
        if(not p) return 0;
        int x = 0;
        int y =0;
        x = depth(p->left, ans);
        y = depth(p->right, ans);
       ans = max(ans,x+y);
        return max(x,y)+1;
        
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        depth(root,res);
        return res;
        
    }
   
};