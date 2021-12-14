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
    int sum = 0;
    
    void dfs(TreeNode* root, int low, int high){
        //Base case
        if(!root) return;
        //If the value is in range, we add
        if(root -> val >= low and root->val <= high) sum += root->val;
        //Going further into the depth of the tree
        if(root->val > low) dfs(root->left, low, high);
        if(root->val < high) dfs(root->right, low, high);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0;
        dfs(root, low, high);
        return sum;
    }
};