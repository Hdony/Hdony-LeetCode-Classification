// Created by wuyou on 2021/2/25.

#include <iostream>

using namespace std;

/*
 * 题目：最长回文子序列
 * 给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。
 */

/*
 * 示例 1:
 * 输入: "bbbab"
 * 输出: 4
 * 一个可能的最长回文子序列为 "bbbb"。

 * 示例 2:
 * 输入: "cbbd"
 * 输出: 2
 * 一个可能的最长回文子序列为 "bb"。 

 * 提示：
 * 1 <= s.length <= 1000, s 只包含小写英文字母
 */

/*
 * 解析：
 * L[i][j] 表示 s[i,j] 的最大回文子序列，n 为 s 的长度，len 为子序列长度
 * 如果 s[i]
 * 3.
 * */

class LongestPalindromicSubsequence {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int L[n][n];

        for (int i = 0; i < n; i ++)
            L[i][i] = 1;

        for (int len = 2; len <= n; len ++) {
            for (int i = 0; i < n - len + 1; i ++) {
                int j = i + len - 1;
                if (s[i] == s[j] && len == 2)
                    L[i][j] = 2;
                else if (s[i] == s[j])
                    L[i][j] = L[i + 1][j - 1] + 2;
                else
                    L[i][j] = max(L[i][j - 1], L[i + 1][j]);
            }
        }

        return L[0][n - 1];
    }

    void test(string s) {
        time_t start = clock();
        int res = longestPalindromeSubseq(s);
        time_t end = clock();
        cout << "Result = " << res << endl;
        cout << "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;

    }
};