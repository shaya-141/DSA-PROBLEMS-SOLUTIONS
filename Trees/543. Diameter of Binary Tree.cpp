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
    // linear square solution O(n^2)
    // int ans  = 0;
    // int maxDepth(TreeNode* root){
    //     if(!root) return 0;
    //     int left = maxDepth(root->left);
    //     int right = maxDepth(root->right);
    //     return max(left,right) + 1;
    // }
    // void solve(TreeNode* root){
    //     if(!root) return ;
    //     int leftDepth = maxDepth(root->left);
    //     int rightDepth = maxDepth(root->right);

    //     ans = max(ans,leftDepth + rightDepth);
    //     solve(root->left);
    //     solve(root->right);
    // }

    // linear solution O(n)
    int ans = 0;
    int height(TreeNode* root){
        if(!root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        
        ans = max(ans,left + right);
        return max(left,right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
    //  O(n^2) solution 
    //  solve(root); 

    //  O(n) linear solution 
        height(root);
        return ans;
    }
};
