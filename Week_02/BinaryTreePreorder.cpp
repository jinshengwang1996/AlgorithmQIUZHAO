/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  递归的思想，需要创建额外的成员数组 时间复杂度为O(n), 空间复杂度为O(n)
// class Solution {
// public:
//     vector<int> res;
//     vector<int> preorderTraversal(TreeNode* root) {
//         if (root) {
//             res.push_back(root->val);
//             preorderTraversal(root->left);
//             preorderTraversal(root->right);
//         }
//         return res;
//     }
// };
// 递归思想，创建helper函数辅助进行递归
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         helper(root, res);
//         return res;
//     }
//     void helper(TreeNode* root, vector<int>& res) {
//         if (root) {
//             res.push_back(root->val);
//             helper(root->left, res);
//             helper(root->right, res);
//         }
//     }
// };

// 利用堆栈解决问题
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         if (!root) return res;

//         stack<pair<TreeNode*, int>> data;
//         data.push({root, 1});

//         while (!data.empty()) {
//             pair<TreeNode*, int> top = data.top();
//             TreeNode* tmp = top.first;
//             data.pop();

//             if (top.second == 0) res.push_back(tmp->val);
//             else {
//                 if (tmp->right) data.push({tmp->right, 1});
//                 if (tmp->left) data.push({tmp->left, 1});
//                 data.push({tmp, 0});
//             }
//         }
//         return res;
//     }
// };

// 还是利用堆栈来解决问题，思路与之前的有所不同, 也不同于中序遍历的那种思想
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> data;
        data.push(root);
        while (!data.empty()) {
            TreeNode* tmp = data.top();
            data.pop();
            res.push_back(tmp->val);  // 根节点
            // 先让右结点入栈，先出来的肯定就是左结点
            if (tmp->right) data.push(tmp->right);
            if (tmp->left) data.push(tmp->left);
        }
        return res;
    }
};