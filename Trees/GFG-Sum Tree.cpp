class Solution {
  public:
    pair<int,bool> solve(Node* root){
        if(!root) return {0,true};
        if(!root->left && !root->right) return {root->data, true};
        
        pair<int,bool> left = solve(root->left);
        pair<int,bool> right = solve(root->right);
        
        int sum = left.first + right.first;
        
        if(sum == root->data){
            return {sum + root->data, true};
        }
        
        return {sum , false};
        
    }
    bool isSumTree(Node* root) {
        // Your code here
        pair<int,bool> ans = solve(root);
        
        return ans.second;
    }
};
