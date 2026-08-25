class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> vals;

            while(size--){
                TreeNode* curr = q.front();
                q.pop();

                vals.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);


            }

            if(lvl % 2 != 0) reverse(vals.begin() , vals.end());

            ans.push_back(vals);
            lvl++;

        }

        return ans;


    }
};
