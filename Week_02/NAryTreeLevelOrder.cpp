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

class Solution {
public:
    vector<vector<int>> result;

    void dfs(Node* root, int dep){
        if(!root) return;
        if(dep == result.size()) result.emplace_back();
        result[dep].push_back(root->val);
        auto children = root->children;
        for(auto ele:children){
            dfs(ele, dep+1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        dfs(root, 0);
        return result;
    }
};