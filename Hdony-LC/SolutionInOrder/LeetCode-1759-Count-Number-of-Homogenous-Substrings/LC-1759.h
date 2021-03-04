// Created by wuyou on 2021/3/3.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/*
 * 题目：
 * 给一个仅由字符 '0' 和 '1' 组成的字符串 s 。
 * 一步操作中，你可以将任一 '0' 变成 '1' ，或者将 '1' 变成 '0' 。
 * 交替字符串 定义为：如果字符串中不存在相邻两个字符相等的情况，那么该字符串就是交替字符串。
 * 例如，字符串 "010" 是交替字符串，而字符串 "0100" 不是。
 * 返回使 s 变成 交替字符串 所需的 最少 操作数。
 */

/*
 * 示例 1：
 * 输入：s = "abbcccaa"
 * 输出：13
 * 解释：同构子字符串如下所列：
 * "a"   出现 3 次。
 * "aa"  出现 1 次。
 * "b"   出现 2 次。
 * "bb"  出现 1 次。
 * "c"   出现 3 次。
 * "cc"  出现 2 次。
 * "ccc" 出现 1 次。
 * 3 + 1 + 2 + 1 + 3 + 2 + 1 = 13
 */

/*
 * 示例 2：
 * 输入：s = "xy"
 * 输出：2
 * 解释：同构子字符串是 "x" 和 "y" 。
 */

/*
 * 示例 3：
 * 输入：s = "zzzzz"
 * 输出：15
 */

/*
 * 提示：
 * 1 <= s.length <= 105
 * s 由小写字符串组成
 */

class CountNumberOfHomogenousSubstrings {
public:
    int countHomogenous(string s) {
        int n = s.size();
        long long res = 0;
        long long L = 0,  R = 0;
        while (R < n) {
            if (s[L] == s[R])
                R += 1;
            else {
                long long window_len = R - L;
                res +=  window_len * (window_len + 1) / 2;
                res %= 1000000007;
                L = R;
            }
        }
        long long window_len = R - L;             //最后一段窗口
        res += window_len * (window_len + 1 ) / 2;
        res %= 1000000007;
        return int(res);
    }

    int countHomogenous_(string s) {
        // cur is the previous character in type integer, count the number of continuous same character.
        int res = 0, cur = 0, count = 0, mod = 1e9 + 7;
        for (int ch : s) {
            cout << ch << endl;
            count = ch == cur ? count + 1 : 1;
            cur = ch;
            res = (res + count) % mod;
        }
        return res;
    }

    void test() {
        time_t start = clock();

        int res = countHomogenous_("abbcccaa");

        cout << "Result: " << res << endl;
        time_t end = clock();
        cout <<  "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};
