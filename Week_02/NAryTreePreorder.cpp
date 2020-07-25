/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// 递归思路，需要创建额外的成员函数，时间复杂度为O(n)，空间复杂度为O(n)
// class Solution {
// public:
//     vector<int> res;
//     vector<int> preorder(Node* root) {
//         if (root) {
//             res.push_back(root->val);
//             for (auto children : root->children) preorder(children);
//         }
//         return res;
//     }
// };

// 递归的另一种思路，构建辅助函数helper
// class Solution {
// public:
//     vector<int> preorder(Node* root) {
//         vector<int> res;
//         helper(root, res);
//         return res;
//     }
//     void helper(Node* root, vector<int>& res) {
//         if (root) {
//             res.push_back(root->val);
//             for (auto children : root->children) helper(children, res);
//         }
//     }
// };

// 迭代法求解, 构造辅助堆栈
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (!root) return res;
        stack<Node*> data;
        data.push(root);
        while (!data.empty()) {
            Node* tmp = data.top();
            data.pop();
            res.push_back(tmp->val);
            for (int i = tmp->children.size() - 1; i >= 0; --i) {
                data.push(tmp->children.at(i));
            }
        }
        return res;
    }
};

