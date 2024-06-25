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
    TreeNode* bstToGst(TreeNode* root) {
        vector<TreeNode* > pre;
        TreeNode* temp=root;
        stack<TreeNode*> st;
        while(true){
            if(temp){
                st.push(temp);
                temp=temp->left;
            }
            else{
                    if(st.empty()) break;
                    temp=st.top();
                    st.pop();
                    pre.push_back(temp);
                    temp=temp->right;  
            }
        }
        for(int i=pre.size()-2;i>=0;i--){
            pre[i]->val+=pre[i+1]->val;
        }
        return root;
    }
};