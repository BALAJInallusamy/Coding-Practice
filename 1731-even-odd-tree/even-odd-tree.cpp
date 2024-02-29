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
bool isEvenOddTree(TreeNode* root) {
queue<TreeNode*> q;
q.push(root);
int level=0,n=0;
TreeNode* temp=NULL;
while(!q.empty() ){
n=q.size();
for(int i=0;i<n;i++){
if(i>0 && level%2==1 && temp->val<=q.front()->val) return false;
if(i>0 && level%2==0 && temp->val>=q.front()->val) return false;
temp=q.front();
q.pop();
if(level%2==1 && temp->val%2==1)    return false;

if(level%2==0 && temp->val%2==0)    return false;

if(temp->left) q.push(temp->left);
if(temp->right) q.push(temp->right);
}
level++;
}
return true;
}
};