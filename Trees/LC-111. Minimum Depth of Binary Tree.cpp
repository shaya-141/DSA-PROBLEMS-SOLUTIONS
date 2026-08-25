  int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);

        int level = 1;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                TreeNode* curr = q.front();
                q.pop();

                if(!curr->left && !curr->right) return level;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

            }

            level++;
        }

        return level;


    }
