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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int ans = 0;

        while (!q.empty()) {
            int size = q.size();
            int mmin=q.front().second;
            int first, last;
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                TreeNode* node = p.first;
                long ind = p.second-mmin;
                if (i == 0)
                    first = ind;
                if (i == size - 1)
                    last = ind;

                if (node->left)
                    q.push({node->left, 2 * ind + 1});
                if (node->right)
                    q.push({node->right, 2 * ind + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};