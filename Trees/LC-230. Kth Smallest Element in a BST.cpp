class Solution {
public:
    void solve(TreeNode* root , vector<int> &ans){
        if(!root) return;
        solve(root->left , ans);
        ans.push_back(root->val);
        solve(root->right , ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> ans;
        solve(root, ans);
        return ans[k - 1];


        // vector<int> ans;
        // queue<TreeNode*> q;
        // q.push(root);

        // while(!q.empty()){
        //     int size = q.size();
        //     while(size--){
        //         TreeNode* curr = q.front();
        //         q.pop();
        //         ans.push_back(curr->val);
        //         if(curr->left) q.push(curr->left);
        //         if(curr->right) q.push(curr->right);
        //     }
        // }

        // sort(ans.begin() , ans.end());

        // return ans[k - 1];

    }
};
