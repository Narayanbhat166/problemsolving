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
class Solution
{
    vector<vector<int>> res;

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        helper(root, targetSum, path);
        return res;
    }

    void helper(TreeNode *root, int targetSum, vector<int> &path)
    {
        if (!root)
            return;

        targetSum -= root->val;
        path.push_back(root->val);

        if (!root->left && !root->right)
        {
            if (targetSum == 0)
                res.push_back(path);
        }

        if (root->left)
            helper(root->left, targetSum, path);
        if (root->right)
            helper(root->right, targetSum, path);

        path.pop_back();
    }
};