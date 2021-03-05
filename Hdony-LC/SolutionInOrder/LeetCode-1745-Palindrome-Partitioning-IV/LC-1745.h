/*
 * 给你一个字符串 s ，如果可以将它分割成三个 非空 回文子字符串，那么返回 true ，否则返回 false 。
 */

/*
 * 示例 1：
 * 输入：s = "abcbdd"
 * 输出：true
 * 解释："abcbdd" = "a" + "bcb" + "dd"，三个子字符串都是回文的。
 */

/*
 * 示例 2：
 * 输入：s = "bcbddxy"
 * 输出：false
 * 解释：s 没办法被分割成 3 个回文子字符串。
 */

/*
 * 提示：
 * 3 <= s.length <= 2000
 * s​​​​​​ 只包含小写英文字母。
 */

#include <iostream>
#include <vector>

using namespace std;

// DP
// Time Complexity: O(|s|^2)
// Space Complexity: O(|s|^2)
class Solution {
public:
    bool checkPartitioning(string s) {

        // dp[len][start] 表示从 s[start] 开始，连续 len 个元素是否为回文串
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>());

        dp[1] = vector<bool>(n, true);
        for (int i = 0; i + 1 < n; i ++)
            dp[2].push_back(s[i] == s[i + 1]);

        for (int sz = 3; sz <= n; sz ++)
            for(int i = 0; i + sz <= n; i ++)
                // 两端相同 && 中间剩余的字符也是回文串
                dp[sz].push_back((s[i] == s[i + sz - 1]) && dp[sz - 2][i + 1]);

        // [0 .. i - 1] [i .. j - 1] [j ... n - 1]
        for (int i = 1; i < n; i ++)
            for (int j = i + 1; j < n; j ++)
                // n > j > i
                if (dp[i][0] && dp[j - i][i] && dp[n - j][j])
                    return true;
        return false;
    }
};











