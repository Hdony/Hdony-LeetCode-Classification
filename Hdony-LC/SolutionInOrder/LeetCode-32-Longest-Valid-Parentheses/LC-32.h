
/*
 * 给一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 */

/*
 * 示例 1：
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 */

/*
 * 示例 2：
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 */

/*
 * 示例 3：
 * 输入：s = ""
 * 输出：0
 */

/*
 * 提示：
 * 0 <= s.length <= 3 * 104
 * s[i] 为 '(' 或 ')'
 */

#include <vector>
#include <stack>

using namespace std;

// DP : dp[i] 表示 以s[i] 为结尾的最长连续有效字符串，如 '()(()': dp[4]=2, dp[2]=0
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0, n = s.length();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') { // 以 '(' 结尾的子串一定不是有效子串，只需要考虑以 ')' 结尾的子串
                if (s[i - 1] == '(')
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                // i-dp[i-1]>0 表示 s[i] 之前的括号未完全配对，还有剩余的括号
                // s[i-dp[i-1]-1]表示将 与 s[i] 相邻的最长连续有效子串忽略后，前一个字符为 '(',
                //   例如，'((()())', 对于最后一个字符 ')', 忽略掉相邻的 '()()' 后，前一个字符为 '('
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;

                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }

    void test() {
        cout << longestValidParentheses("()(()");
    }
};


// Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution1{
public:

    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                stk.push(i);
            else {
                stk.pop();
                if (stk.empty()) stk.push(i);
                else ans = max(ans, i - stk.top());
            }
        }
        return ans;
    }

    void test() {
        cout << longestValidParentheses("()(()");
    }
};
