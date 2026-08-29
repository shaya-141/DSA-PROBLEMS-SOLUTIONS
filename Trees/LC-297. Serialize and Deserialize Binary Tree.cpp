class Codec {
public:
    string res;
    void solve(TreeNode* root){
        if(!root){
            res += "null,";
            return ;
        }
        res += to_string(root->val)+",";
        solve(root->left);
        solve(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        res = "";
        if(!root) return res += "null,";
        solve(root);
        return res;

    }

    TreeNode* built(vector<string> &tokens , int &i){
        if(tokens[i] == "null"){
            i++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(tokens[i]));
        i = i+1;
        root->left = built(tokens ,i);
        root->right = built(tokens , i);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        stringstream ss(data);
        string token;

        while(getline(ss , token , ',')){
            tokens.push_back(token);
        }

        int i = 0;
        TreeNode* root = built(tokens ,i);
        return root;
    }
};
