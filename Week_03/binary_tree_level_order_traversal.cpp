/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  using queue into level order
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> res;
//         if (!root) return res;
//         queue<TreeNode*> data;
//         data.push(root);

//         while (!data.empty()) {
//             int data_size = data.size();
//             res.push_back(vector<int> ());
//             for (int i = 0; i < data_size; ++i) {
//                 TreeNode* front = data.front();
//                 data.pop();
//                 res.back().push_back(front->val);

//                 if (front->left) data.push(front->left);
//                 if (front->right) data.push(front->right);
//             }
//         }
//         return res;
//     }
// };

// using recrsion to solve
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res, 0);        
        return res;
    }
    void dfs(TreeNode* root, vector<vector<int>>& res, int level) {
        if (!root) return;
        if (level >= res.size()) res.push_back(vector<int> ());
        res[level].push_back(root->val);
        dfs(root->left, res, level + 1);
        dfs(root->right, res, level + 1);
    }
};