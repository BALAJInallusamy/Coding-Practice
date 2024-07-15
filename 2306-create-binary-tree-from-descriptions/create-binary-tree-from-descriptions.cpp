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
    TreeNode* createBinaryTree(vector<vector<int>>& arr) {
        unordered_map<int,TreeNode *> mp;
        for(auto it:arr){
            if( mp.find(it[1]) == mp.end() ) mp[it[1]] = new TreeNode(it[1]);
            if( mp.find(it[0]) == mp.end() ) mp[it[0]] = new TreeNode(it[0]);
            if(it[2]==1){
                mp[it[0]]->left = mp[it[1]];
            }
            else mp[it[0]]->right = mp[it[1]];
        }
        unordered_map<int,int> all;
        for(auto it:arr){
            all[it[1]]++;
        }
        for(auto it:mp){
            if(all[it.first]==0) return it.second;
        }
        return NULL;
    }
};