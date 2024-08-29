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
    
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* right = root->right, * left = root->left;

        if(!right && !left){
            return;
        }

        if(!left){
            flatten(right);
            return;
        }
        if(!right){
            flatten(left);
            root->left = NULL;
            root->right = left;
            return;
        }

        flatten(right);
        flatten(left);

        TreeNode* end = left;
        while(end && end->right) end= end->right;
        end->right = right; 
        root->right = left;
        root->left = NULL;

        return;
    }
};