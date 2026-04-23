class Solution {
public:
    bool match(TreeNode* root, TreeNode* subroot){
        if(root == NULL || subroot == NULL) return root == subroot;
        bool left = match(root->left , subroot->left);
        bool right = match(root->right , subroot->right);

        return  (left && right && root->val == subroot->val);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // if root == NUll 
        if(!root) return false;

        // check if current node is identical
        if(match(root,subRoot)) return true;

        // call for left node check 
        bool left = isSubtree(root->left,subRoot) ;

        // call for left node check 
        bool right = isSubtree(root->right,subRoot) ;
        
        return left || right;
    }
};
