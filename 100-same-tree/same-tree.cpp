class Solution {
public:
bool isSameTree(TreeNode* p, TreeNode* q) {
if(!q || !p) return p==q;
bool left=isSameTree(p->left,q->left);
bool right=isSameTree(p->right,q->right);
return (p->val==q->val) && left && right;
}
};