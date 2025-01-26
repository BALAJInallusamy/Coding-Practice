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
    bool rec(TreeNode* root, long long left , long long right){
        if(!root) return 1;
        if(root->val<= left) return false;
        if(root->val>= right) return false;
        return rec(root->left,left,root->val) && rec(root->right,root->val,right);
    }
    bool isValidBST(TreeNode* root) {
        long long mini= INT_MIN, maxi = INT_MAX;
        mini--;
        maxi++;
        return rec(root,mini,maxi);
    }
};

//         2,-1e9,1e9
//  1,2,1e9