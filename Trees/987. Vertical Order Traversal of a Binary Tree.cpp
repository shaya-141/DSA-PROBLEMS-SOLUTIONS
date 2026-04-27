
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> nodes;

        q.push({root,{0,0}});

        while(q.size() > 0){
            TreeNode* curr = q.front().first;
            int HD = q.front().second.first;
            int lvl = q.front().second.second;

            q.pop();

            nodes[HD][lvl].insert(curr->val);

            if(curr->left) q.push({curr->left,   {HD - 1,lvl + 1}});
            if(curr->right) q.push({curr->right, {HD + 1 , lvl + 1}});

        }
        
        vector<vector<int>> ans;
        for(auto i : nodes){
            vector<int> col;
            for(auto j : i.second){
               col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }

        return ans;

    }
};
