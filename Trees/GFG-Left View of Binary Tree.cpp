
class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        
        if(!root) return {};
        
        queue<Node*> q; 
        q.push(root);
        
        vector<int> ans;
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i <size; i++){
                Node* curr = q.front();
                q.pop();
                if(i == 0) ans.push_back(curr->data);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        
        
        return ans;
        
    }
};
