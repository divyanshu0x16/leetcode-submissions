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
    void isBST(TreeNode* root, int& carry, bool& validBST, bool& start){
       if(root){
           isBST(root -> left,carry,validBST,start);
           if(!start){
                carry = root -> val;
                start = true;
           }else if(carry >= root -> val)
               validBST = false;
           else
               carry = root -> val;
           isBST(root ->right,carry,validBST,start);
               
       }
    }
    
    
    bool isValidBST(TreeNode* root) {
        bool isValid = true,start = false;
        int carry = 0;
        isBST(root,carry,isValid,start);
        return isValid;
    }
};