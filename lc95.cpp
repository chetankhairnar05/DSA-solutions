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
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> dp(n+1 , vector<vector<TreeNode*>>(n+1));
        for(int len = 1;len<=n;len++){
            for(int i = 1;i<=n;i++){
                int j = i+len-1;
                if(j>n){
                    break;
                }
                if(i==j){
                    dp[i][j].push_back(new TreeNode(i));
                    continue;
                }

                for(int k = i;k<=j;k++){
                    

                    vector<TreeNode*>lefts ;
                    if(k-1<i){
                        lefts.push_back(NULL);
                    }else{
                        lefts = dp[i][k-1];
                    }

                    vector<TreeNode*>rights ;
                    if(k+1>j){
                        rights.push_back(NULL);
                    }else{
                        rights = dp[k+1][j];
                    }

                    for(TreeNode* l:lefts){
                        for(TreeNode* r:rights){
                            TreeNode* node = new TreeNode(k);
                            node->left = l;
                            node->right = r;
                            dp[i][j].push_back(node);
                        }
                    }

                }
            }
        }

        return dp[1][n];

    }
};