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

    // 👉 Function to calculate leftmost height
    int getLeftHeight(TreeNode* root) {
        int height = 0;

        while (root) {
            height++;
            root = root->left;
        }

        return height;
    }

    // 👉 Function to calculate rightmost height
    int getRightHeight(TreeNode* root) {
        int height = 0;

        while (root) {
            height++;
            root = root->right;
        }

        return height;
    }

    // 👉 Main function to count nodes in Complete Binary Tree
    int countNodes(TreeNode* root) {
        // Base case
        if (!root) return 0;

        // Get leftmost and rightmost heights
        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        // 🟢 Case 1: Perfect Binary Tree
        // If heights are equal, directly calculate nodes using formula
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1; // equivalent to 2^h - 1
        }

        // 🔴 Case 2: Not perfect
        // Recursively count nodes in left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    
};
