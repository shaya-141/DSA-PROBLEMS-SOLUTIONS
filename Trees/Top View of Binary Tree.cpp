class Solution {
  public:
    vector<int> topView(Node *root) {

        // queue stores pair of (node, horizontal distance)
        queue<pair<Node*, int>> q;

        // map stores: HD -> first node value seen at that HD
        // map keeps keys sorted (left HD to right HD)
        map<int, int> m;

        // start BFS from root at HD = 0
        q.push({root, 0});

        while(q.size() > 0){

            Node* curr = q.front().first;
            int HD = q.front().second;
            q.pop();

            // if this horizontal distance is seen for the first time
            // then store it (this is topmost node for that HD)
            if(m.find(HD) == m.end()){
                m[HD] = curr->data;
            }

            // left child goes to HD - 1 (move left column)
            if(curr->left) 
                q.push({curr->left, HD - 1});

            // right child goes to HD + 1 (move right column)
            if(curr->right) 
                q.push({curr->right, HD + 1});
        }

        vector<int> arr;

        // extract values in sorted order of HD (left to right view)
        for(auto it : m){
            arr.push_back(it.second);
        }

        return arr;
    }
};
