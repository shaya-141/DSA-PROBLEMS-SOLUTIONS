class Solution {
  public:
    vector<int> bottomView(Node *root) {

        // queue stores pair of (node, horizontal distance)
        queue<pair<Node*, int>> q;

        // map stores: HD -> latest node value at that HD
        // map keeps keys sorted (leftmost HD to rightmost HD)
        map<int, int> m;

        // start BFS from root at HD = 0
        q.push({root, 0});

        while(q.size() > 0){

            Node* curr = q.front().first;
            int HD = q.front().second;
            q.pop();

            // for bottom view:
            // we UPDATE every time we see a node at this HD
            // so the last (deepest) node at this HD remains
            m[HD] = curr->data;

            // left child goes to HD - 1 (move to left column)
            if(curr->left) 
                q.push({curr->left, HD - 1});

            // right child goes to HD + 1 (move to right column)
            if(curr->right) 
                q.push({curr->right, HD + 1});
        }

        vector<int> ans;

        // extract values in sorted order of HD (left to right view)
        for(auto it : m){
            ans.push_back(it.second);
        }

        return ans;
    }
};
