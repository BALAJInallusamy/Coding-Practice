class Solution {
public:
    int result=0;
    int countPairs(TreeNode* root, int distance) {
        dfs(root,distance);
        return result;
    }
    vector<int>dfs(TreeNode*root,int d){
        if(!root)return {};
        if(!root->left && !root->right)return {1};

        auto left=dfs(root->left,d);
        auto right=dfs(root->right,d);

        for(auto x:left)
        for(auto y:right)if(x+y<=d)result++;

        vector<int>v;
        for(auto x:left)v.push_back(x+1);
        for(auto x:right)v.push_back(x+1);
        return v;
    }
};