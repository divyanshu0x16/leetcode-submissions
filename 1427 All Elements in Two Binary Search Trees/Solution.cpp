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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;

        vector<int> res;

        while (root1 != NULL or root2 != NULL or !st1.empty() or !st2.empty())
        {
            while (root1 != NULL)
            {
                st1.push(root1);
                root1 = root1 -> left;
            }
            
            while (root2 != NULL)
            {
                st2.push(root2);
                root2 = root2 -> left;
            }


            if( st2.empty() or  ( !st1.empty() and st1.top() -> val <= st2.top() -> val )){
                root1 = st1.top();
                st1.pop();
                res.push_back(root1 -> val);
                root1 = root1 -> right;
            }
            else{
                root2 = st2.top();
                st2.pop();
                res.push_back(root2 -> val);
                root2 = root2 -> right;
            }
        }
        return res;
    }
};