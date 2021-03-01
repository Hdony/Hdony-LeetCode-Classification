// Created by wuyou on 2021/2/24.

#include <iostream>

using namespace std;

/*
 * 题目：
 * 给你两个字符串 word1 和 word2 ，请你按下述方法构造一个字符串：
 * 从 word1 中选出某个 非空 子序列 subsequence1 。
 * 从 word2 中选出某个 非空 子序列 subsequence2 。
 * 连接两个子序列 subsequence1 + subsequence2 ，得到字符串。
 * 返回可按上述方法构造的最长 回文串 的 长度 。如果无法构造回文串，返回 0 。
 * PS: 字符串 s 的一个 子序列 是通过从 s 中删除一些（也可能不删除）字符而不更改其余字符的顺序生成的字符串。
 *     回文串 是正着读和反着读结果一致的字符串。
 */

/*
 * 示例1：
 * 输入：word1 = "cacb", word2 = "cbba"
 * 输出：5
 * 解释：从 word1 中选出 "ab" ，从 word2 中选出 "cba" ，得到回文串 "abcba" 。
 */

/*
 * 示例 2：
 * 输入：word1 = "ab", word2 = "ab"
 * 输出：3
 * 解释：从 word1 中选出 "ab" ，从 word2 中选出 "a" ，得到回文串 "aba" 。
 */

/*
 * 示例 3：
 * 输入：word1 = "aa", word2 = "bb"
 * 输出：0
 * 解释：无法按题面所述方法构造回文串，所以返回 0 。
*/

/*
 * 解析：
 * 1. 第一个子序列在左，第二个子序列在右，顺序不变
 * 2. word1 和 word2 中有一个为空字符串，结果均为 0，因此每个字符串都最少有一个字符
 * 3. 最长回文子序列的变体，注意子序列的左右边界应落在 word1 和 word2 内
 * */

// DP
class MaximizePalindromeLengthFromSubsequences {
public:
    int dp[100][100];
    int longestPalindrome(const string& word1, const string& word2) {
        string s = word1 + word2;
        int m = word1.length(), n = word2.length(), res = 0;

        for (int j = 0; j < m + n; ++j) {
            dp[j][j] = 1;
            for (int i = j - 1; i >= 0; --i) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                    if (i < m and j >= m)
                        res = max(res, dp[i][j]);
                } else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return res;
    }

    void test(const string& word1, const string& word2) {
        time_t start = clock();
        int res = longestPalindrome(word1, word2);
        time_t end = clock();
        cout << "Result = " << res << endl;
        cout << "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};






