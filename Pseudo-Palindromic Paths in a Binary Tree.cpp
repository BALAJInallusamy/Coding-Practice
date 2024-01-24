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
    int rec(TreeNode* root, int odd, int mask){
        
        if(mask>>root->val &1) mask=mask^(1<<root->val), odd--;
        else odd++, mask+=1<<root->val;

        if(!root->left && !root->right){
            if(odd <=1) return 1;
            return 0;
        }

        int ans=0;
        if(root->left ) ans+= rec(root->left,odd,mask);
        if(root->right ) ans+=rec(root->right,odd,mask);
        return ans;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int mask=0;
        return rec(root,0,mask);
    }
};
