/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int ans = 0;
        int maxi = INT_MIN;
        while (!q.empty()) {
            int size = q.size();
            int sum = 0;
            level++;
            while (size--) {
                TreeNode* temp = q.front();
                sum+=temp->val;
                q.pop();
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            if (sum > maxi) {
                maxi = sum;
                ans = level;
            }
        }
        return ans;
    }
};