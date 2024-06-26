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
int ans;
class Solution {
public:

    int childsum(TreeNode* root) {
        if( !root ) return 0;
        int right= max(childsum(root->right),0);
        int left = max(childsum(root->left),0);
        ans=max(ans, root->val+right+left );
        cout<<ans<<" ";
        return root->val+ max(right,left);
    }

    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        childsum(root);
        return ans;
    }
};