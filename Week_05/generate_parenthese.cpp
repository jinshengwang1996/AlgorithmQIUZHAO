// recursion to solve the problem
// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
//         vector<string> res;
//         generate(0, 0, n, "", res);
//         return res;
//     }
//     void generate(int left, int right, int n, string s, vector<string> &res) {
//         if (left == n && right == n) {
//             res.push_back(s);
//             return;
//         }
//         if (left < n) generate(left + 1, right, n, s + "(", res);
//         if (right < left) generate(left, right + 1, n, s + ")", res);
//     }
// };
// using recursion to solve the problem
// 1. left ( can add at any time but < n
// 2. right ) must add after left (, and left < right
// class Solution {
// public:
//     vector<string> res;
//     void _generateParenthesis(int n, int left, int right, string str) {
//         if (left == n && right == n) {
//             res.push_back(str);
//             return;
//         }
//         if (left < n) _generateParenthesis(n, left + 1, right, str + "(");
//         if (right < left) _generateParenthesis(n, left, right + 1, str + ")");
//     }
//     vector<string> generateParenthesis(int n) {
//         res.clear();
//         if (n <= 0) return res;
//         _generateParenthesis(n, 0, 0, "");
//         return res;
//     }
// };
// using bfs to solve the problem
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0) return res;
        queue<pair<string, pair<int, int>>> data;
        // using a queue to solve, the struct of the queue should be remmbered
        data.push({"", {0, 0}});  
        while (!data.empty()) {
            pair<string, pair<int, int>> top = data.front();
            data.pop();
            if (top.second.first == n && top.second.second == n) res.push_back(top.first);
            else {
                if (top.second.first <= n) {
                    data.push({top.first + "(", {top.second.first + 1, top.second.second}});
                }
                if (top.second.first > top.second.second) {
                    data.push({top.first + ")", {top.second.first, top.second.second + 1}});
                }
            }
        }
        return res;
    }
};

# class Solution:
#     def generateParenthesis(self, n: int) -> List[str]:
#         def dfs(left, right, n, s):
#             if (left == n and right == n):
#                 res.append(s)
#                 return
#             if (left <= n):
#                 dfs(left + 1, right, n, s + "(")
#             if (right < left):
#                 dfs(left, right + 1, n, s + ")")
#         res = []
#         dfs(0, 0, n, "")
#         return res

# class Solution:
#     def generateParenthesis(self, n: int) -> List[str]:
#         self.res = []
#         self.dfs(0, 0, n, "")
#         return self.res
#     def dfs(self, left, right, n, s):
#             if (left == n and right == n):
#                 self.res.append(s)
#                 return
#             if (left <= n):
#                 self.dfs(left + 1, right, n, s + "(")
#             if (right < left):
#                 self.dfs(left, right + 1, n, s + ")")

# class Solution:
#     def generateParenthesis(self, n: int) -> List[str]:
#         res = []
#         if n == 0:
#             return res
#         data = collections.deque([("", 0, 0)])
#         while data:
#             s, left, right = data.popleft()
#             if (left == n and right == n):
#                 res.append(s)
#             else:
#                 if left <= n:
#                     data.append((s + "(", left + 1, right))
#                 if right < left:
#                     data.append((s + ")", left, right + 1))
#         return res

# class Solution:
#     def generateParenthesis(self, n: int) -> List[str]:
#         res = []
#         if n == 0:
#             return res
#         data = collections.deque([("", 0, 0)])
#         while data:
#             s, left, right = data.popleft()
#             if (left == n and right == n):
#                 res.append(s)
#             else:
#                 if left <= n:
#                     data.append((s + "(", left + 1, right))
#                 if right < left:
#                     data.append((s + ")", left, right + 1))
#         return res