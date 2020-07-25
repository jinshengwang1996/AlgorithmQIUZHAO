/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  递归代码
// class Solution {
// public:
//     vector<int> res;
//     vector<int> inorderTraversal(TreeNode* root) {
//         if (root) {
//             inorderTraversal(root->left);
//             res.push_back(root->val);
//             inorderTraversal(root->right);
//         }
//         return res;
//     }
// };

// 递归代码
// class Solution {
// public:
//     vector<int> res;
//     vector<int> inorderTraversal(TreeNode* root) {
//         if (root == NULL) return res;  // 递归终止条件
//         // 处理当前逻辑
//         else {
//             inorderTraversal(root->left);
//             res.push_back(root->val);
//             inorderTraversal(root->right);
//         }
//         return res;
//     }
// };

// 利用函数进行递归，避免在函数体外定义变量
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         helper(root, res);
//         return res;
//     }
//     void helper(TreeNode* root, vector<int> &res) {
//         if (root) {
//             helper(root->left, res);
//             res.push_back(root->val);
//             helper(root->right, res);
//         }
//     }
// };

// 迭代代码
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         if (root == NULL) return res;
//         stack<pair<TreeNode*, int>> data;  // 利用堆栈来维护
//         data.push({root, 0});
//         while (!data.empty()) {
//             pair<TreeNode*, int> top = data.top();
//             TreeNode* tmp = top.first;
//             data.pop();

//             if (top.second == 1) res.push_back(tmp->val);
//             else {
//                 // 中序遍历
//                 if (tmp->right != NULL) data.push({tmp->right, 0});  // 这里一定是先右边子树，因为栈是先进后出的
//                 data.push({tmp, 1});  
//                 if (tmp->left != NULL ) data.push({tmp->left, 0});

//                 // 前序遍历
//                 // if (tmp->right != NULL) data.push({tmp->right, 0});  // 这里一定是先右边子树，因为栈是先进后出的
//                 // if (tmp->left != NULL ) data.push({tmp->left, 0});
//                 // data.push({tmp, 1});

//                 // 后序遍历
//                 // data.push({tmp, 1});
//                 // if (tmp->right != NULL) data.push({tmp->right, 0});  // 这里一定是先右边子树，因为栈是先进后出的
//                 // if (tmp->left != NULL ) data.push({tmp->left, 0});
//             }
//         }
//         return res;
//     }
// };

// 迭代法，利用堆栈实现，个人觉得这里的循环条件比较难想到，特别是堆栈中的数据在不为空的时候也要进行循环
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         stack<TreeNode*> data;
//         TreeNode* cur = root;
//         while (cur != NULL || !data.empty()) {
//             while (cur != NULL) {
//                 data.push(cur);
//                 cur = cur->left;
//             }
//             cur = data.top();
//             res.push_back(cur->val);
//             cur = cur->right;
//             data.pop();
//         }
//     return res;
//     }
// };