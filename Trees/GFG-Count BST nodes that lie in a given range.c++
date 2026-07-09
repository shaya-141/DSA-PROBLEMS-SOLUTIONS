
class Solution {
  public:
    int getCount(Node *root, int l, int h) {
        // your code here
        int count  = 0;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                Node* curr = q.front();
                q.pop();
                int val = curr->data;
                if(val >= l && val <= h) count++;
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        
        return count;
    }
};
