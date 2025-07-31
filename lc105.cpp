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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd) {
        if (preStart >= preorder.size() || inStart > inEnd) return nullptr;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = -1;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                inIndex = i;
                break;
            }
        }

        int leftTreeSize = inIndex - inStart;

        root->left = build(preorder, inorder, preStart + 1, inStart, inIndex - 1);
        root->right = build(preorder, inorder, preStart + 1 + leftTreeSize, inIndex + 1, inEnd);

        return root;
    }
};
