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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> ans;
        vector<int> curr = {};
        
        if( root ){
            int currSum = root -> val;

            if(currSum == targetSum and root->left == NULL and root->right == NULL) {
                curr.push_back(root->val);
                ans.push_back(curr);
                return ans;
            }
            curr.push_back(root->val);

            if( root->left ) helper(ans, root->left, curr, currSum, targetSum);
            if( root->right ) helper(ans, root->right, curr, currSum, targetSum);
        }

        return ans;
    }

    void helper(vector<vector<int>>& ans, TreeNode* node, vector<int>& curr, int currSum, int targetSum){

        if(!node)
            return;
        
        currSum += node->val;
        vector<int> currVector = curr;

        if( currSum == targetSum and node->left == NULL and node->right == NULL){
            currVector.push_back(node->val);
            ans.push_back(currVector);
            return;
        }else{
            currVector.push_back(node->val);
            if( node->left ) helper(ans, node->left, currVector, currSum, targetSum);
            if( node->right ) helper(ans, node->right, currVector, currSum, targetSum);
        }
    };
};