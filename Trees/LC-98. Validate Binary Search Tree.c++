class Solution {
public:
    bool solve(TreeNode* root , int min , int max){
        if(!root) return true;
        
        if(root->data <= min || root->data >= max){
            return false;
        
        }
        bool left = solve(root->left , min , root->data);
        bool right = solve(root->right , root->data , max);
        
        return (left && right);
        
    }
    bool isValidBST(TreeNode* root) {
        int min  = INT_MIN , max = INT_MAX;
        return solve(root , min , max);
    }
};
