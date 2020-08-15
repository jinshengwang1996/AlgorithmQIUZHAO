# class Solution:
#     def climbStairs(self, n: int) -> int:
#         if n <2: return 1
#         dp = [1] * (n + 1)
#         for i in range(2, n + 1):
#             dp[i] = dp[i - 1] + dp[i - 2]
#         return dp[-1]

# class Solution:
#     def climbStairs(self, n: int) -> int:
#         if n < 2: return 1
#         return self.climbStairs(n - 1) + self.climbStairs(n - 2)

# class Solution:
#     def climbStairs(self, n: int) -> int:
#         if n < 2: return 1
#         first, second = 1, 1
#         for i in range(2, n + 1):
#             total = first + second
#             first = second
#             second = total
#         return total

// 动态规划方法 时间复杂度为O(n)
// class Solution {
// public:
//     int climbStairs(int n) {
//         int f1 = 0, f2 = 1, f3 = 1;
//         for (int i = 1; i <= n; ++i) {
//             f3 = f1 + f2;

//             f1 = f2;
//             f2 = f3;
//         }
//         return f3;
//     }
// };

// 也可以利用通项公式求解 时间复杂度为O(1)


// 这里很巧妙的利用了斐波那契数列之间的关系
// class Solution {
// public:
//     int climbStairs(int n) {
//         int pre = 0, cur = 1;
//         for (int i = 1; i <= n; ++i) {
//             cur += pre;
//             pre = cur - pre;
//         }
//         return cur;
//     }
// };


// f(1) = 1, f(2) = 2;
// f(3) = f(1) + f(2); f(3) 只可能是经过f(1) 跳两步上来，或者f(2) 跳一步上来
// 所以DP方程：
//           f(n) = f(n-1) + f(n-2)
// 1. 傻递归
// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n <= 2) return n;
//         return climbStairs(n - 1) + climbStairs(n - 2);
//     }
// };
// 2. 缓存中间结果
// class Solution {
// public:
//     int climbStairs(int n) {
//         // 新建一个全1的数组，目的是为了让f(1) 和 f(0) 都为1；
//         vector<int> tmp_res(n + 1, 1);
//         for (int i = 2; i < n + 1; ++i) {
//             tmp_res[i] = tmp_res[i - 1] + tmp_res[i - 2];
//         }
//         return tmp_res[n];
//     }
// };
// 3. 将中间两步的结果保存就可以了
// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n <= 2) return n;
//         int first = 1, second = 2;
//         int sum = 0;
//         for (int i = 3; i <= n; ++i) {
//             sum = first + second;
//             first = second;
//             second = sum;
//         }
//         return sum;
//     }
// };
// 4. dp 简洁代码
// class Solution {
// public:
//     int climbStairs(int n) {
//         int first = 0, second = 1;
//         int sum = 0;
//         for (int i = 1; i <= n; ++i) {
//             sum = first + second;
//             first = second;
//             second = sum;
//         }
//         return sum;
//     }
// };

// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n <= 1) return 1;
//         vector<int> dp(n + 1, 1);
//         for (int i = 2; i <= n; ++i) {
//             dp.at(i) = dp.at(i - 1) + dp.at(i - 2);
//         }
//         return dp.at(n);
//     }
// };


class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        vector<int> dp(n + 1, 1);
        for (int i = 2; i < n + 1; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};