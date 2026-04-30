class Solution {
  public:
    int solve(Node* root){
        if(!root) return 0;
        
        if(!root->left && !root->right){
            int originalValue = root->data;
            root->data = 0;
            return originalValue;
        }
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        int temp = root->data;
        root->data = left + right;
        
        return temp + left + right;
        
    }
    void toSumTree(Node *node) {
        // code here
        solve(node);
        
        
        
    }
};
