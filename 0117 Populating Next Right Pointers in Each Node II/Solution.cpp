/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
    
    void dfs(Node* root)
    {
        if(root==nullptr)
            return;

        if(root->right)
        {
            root->right->next=GetNext(root);
        }
        dfs(root->right);
        
        if(root->left)
        {
            if(root->right) root->left->next=root->right;
            else root->left->next=GetNext(root);
        }
        dfs(root->left);
    }
    
    Node* GetNext(Node* root)
    {
        Node* next=root->next;
        while(next)
        {
            if(next->left) return next->left;
            else if(next->right) return next->right;
            next=next->next;
        }
        return nullptr;
    }
};