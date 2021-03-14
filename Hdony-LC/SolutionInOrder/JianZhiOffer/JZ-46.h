/*
 * 给定一个数字，按照如下规则把它翻译为字符串：
 * 0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
 * 一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
 *
 * 示例 1:
 * 输入: 12258
 * 输出: 5
 * 解释: 12258 有 5 种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
 *
 * 提示：
 * 0 <= num < 2^31
 */

// 用 dp[i] 表示以第 i 位结尾的前缀串翻译的方案数，
// 考虑第 i 位单独翻译和与前一位连接起来再翻译对 f(i) 的贡献

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string src = to_string(num);
        int p, q = 0, r = 1;
        for (int i = 0; i < src.size(); ++i) {
            p = q;
            q = r;
            r = 0;
            r += q;
            if (i == 0)
                continue;
            auto pre = src.substr(i - 1, 2);
            if (pre <= "25" && pre >= "10")
                r += p;
        }
        return r;
    }
};

class Solution1 {
public:
    int translateNum(int num) {
        if (num < 10) return 1;
        return (num % 100 < 10 || num % 100 > 25) ?
                translateNum(num / 10) :
                translateNum(num / 10) + translateNum(num / 100);
    }
};