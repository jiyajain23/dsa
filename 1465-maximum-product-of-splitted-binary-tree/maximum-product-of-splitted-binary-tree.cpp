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

    int sum(TreeNode* root){
        if(root==NULL) return 0;
        return root->val+sum(root->right)+sum(root->left);
    }
    long long total = 0;
    long long ans = 0;
    const int MOD = 1e9 + 7;

    long long dfs(TreeNode* root) {
        if (!root) return 0;
        long long left = dfs(root->left);
        long long right = dfs(root->right);
        long long sub = root->val + left + right;
        ans = max(ans, sub * (total - sub));
        return sub;
    }

    int maxProduct(TreeNode* root) {
        total = sum(root);
        dfs(root);
        return ans % MOD;
    }
};