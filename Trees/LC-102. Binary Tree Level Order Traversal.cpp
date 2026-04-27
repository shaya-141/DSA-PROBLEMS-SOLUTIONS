class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        
        queue<pair<TreeNode* , int>> q;
        map<int,vector<int>> m;
        vector<vector<int>> ans;

        q.push({root,0});

        while(q.size() > 0){
            TreeNode* curr = q.front().first;
            int lvl  = q.front().second;
            q.pop();

            m[lvl].push_back(curr->val);
            if(curr->left) q.push({curr->left,lvl+1});
            if(curr->right) q.push({curr->right,lvl+1});
        }

        for(auto it: m){
            ans.push_back(it.second);
        }
        return ans;

    }
};
