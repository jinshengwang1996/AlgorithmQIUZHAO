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

// 递归解法，需要手动创建一个成员数组，时间复杂度为O(n),空间复杂度为O(n)
// class Solution {
// public:
//     vector<int> res;
//     vector<int> postorder(Node* root) {
//         if (!root) return res;
//         for (auto children : root->children) postorder(children);
//         res.push_back(root->val);
//         return res;
//     }
// };

// 递归的另一种实现形式, 通过创建一个额外的递归函数
// class Solution {
// public:
//     vector<int> postorder(Node* root) {
//         vector<int> res;
//         helper(root, res);
//         return res;
//     }
//     void helper(Node* root, vector<int>& res) {
//         if (!root) return;
//         for (auto children : root->children) helper(children, res);
//         res.push_back(root->val);
//     }
// };

// 迭代方法实现，利用栈来模拟，
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (!root) return res;
        stack<Node*> data;
        data.push(root);

        while (!data.empty()) {
            Node* node = data.top();
            res.push_back(node->val);  // 先将根节点入栈
            data.pop();

            for (int i = 0; i < node->children.size(); ++i) {
                // 如果结点非空，那么入栈，第一次入栈分别为3， 2， 4
                if (node->children.at(i)) data.push(node->children.at(i));
            }
        }
        // 这里需要进行reverse一下
        reverse(res.begin(), res.end());
        return res;
    }
};