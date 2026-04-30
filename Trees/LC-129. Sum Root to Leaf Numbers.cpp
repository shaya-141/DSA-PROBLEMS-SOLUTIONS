
class Solution {
public:
    int solve(TreeNode* root , int prev){
        if(!root) return 0;
        int curr = 10 * prev + root->val;

        if(!root->left && !root->right){
            return curr;
        }

        int left  = solve(root->left,curr);
        int right = solve(root->right , curr);

        return left + right;

    }
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};
