// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int size = s.length();
//         vector<int> dp(size, 0);

//         int maxVal = 0;
//         for(int i = 1; i < size; i++) {
//             if (s[i] == ')') {
//                 if (s[i - 1] == '(') {
//                     dp[i] = 2;
//                     if (i - 2 >= 0) {
//                         dp[i] = dp[i] + dp[i - 2];
//                     }
//                 } else if (dp[i - 1] > 0) {
//                     if ((i - dp[i - 1] - 1) >= 0 && s[i - dp[i - 1] - 1] == '(') {
//                         dp[i] = dp[i - 1] + 2;
//                         if ((i - dp[i - 1] - 2) >= 0) {
//                             dp[i] = dp[i] + dp[i - dp[i - 1] - 2];
//                         }
//                     }
//                 }
//             }
//             maxVal = max(maxVal, dp[i]);
//         }
//         return maxVal;
//     }
// };

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() < 2)
            return 0;
        int ans = 0;
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                st.push(i);
            else {
                st.pop();
                if(st.empty())
                    st.push(i); //重新开始记录
                else
                    ans = max(ans, i - st.top());
            }
        }
        return ans;
    }
};