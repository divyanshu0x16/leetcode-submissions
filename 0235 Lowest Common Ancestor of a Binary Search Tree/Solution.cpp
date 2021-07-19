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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)
            swap(p, q); //makes the thinking process easier if we know p < q
        while(root){
            if(root->val >= p->val && root->val <= q->val)
                return root;
            if(root == p || root == q)
                return root;
            if( p->val < root->val )
                root = root->left;
            else
                root = root->right;
        }
        return root;
    }
};