// Created by wuyou on 2021/3/2.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
 * 题目：
 * 当一个字符串 s 包含的每一种字母的大写和小写形式 同时 出现在 s 中，
 * 就称这个字符串 s 是 美好 字符串。比方说，"abABB" 是美好字符串，
 * 因为 'A' 和 'a' 同时出现了，且 'B' 和 'b' 也同时出现了。
 * 然而，"abA" 不是美好字符串因为 'b' 出现了，而 'B' 没有出现。
 *
 *
 * 给一个字符串 s ，返回 s 最长的 美好子字符串 。如果有多个答案，请你返回 最早 出现的一个。
 * 如果不存在美好子字符串，请你返回一个空字符串。
 */

/*
 * 示例 1：
 * 输入：s = "YazaAay"
 * 输出："aAa"
 * 解释："aAa" 是一个美好字符串，因为这个子串中仅含一种字母，其小写形式 'a' 和大写形式 'A' 也同时出现了。
 * "aAa" 是最长的美好子字符串。
 */

/*
 * 示例 2：
 * 输入：s = "Bb"
 * 输出："Bb"
 * 解释："Bb" 是美好字符串，因为 'B' 和 'b' 都出现了。整个字符串也是原字符串的子字符串。
 */

/*
 * 示例 3：
 * 输入：s = "c"
 * 输出：""
 * 解释：没有美好子字符串。
 */

/*
 * 示例 4：
 * 输入：s = "dDzeE"
 * 输出："dD"
 * 解释："dD" 和 "eE" 都是最长美好子字符串。
 * 由于有多个美好子字符串，返回 "dD" ，因为它出现得最早。
 */

/*
 * 提示：
 * 1 <= s.length <= 100
 * s 只包含大写和小写英文字母。
 */

class LongestNiceSubstring {
public:

    string longestNiceSubstring(string s) {
        int n = s.length();
        // 计算 26 字母前缀和
        vector<vector<int>> lowercase(26, vector<int> (n + 1, 0)),
                            uppercase(26, vector<int> (n + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {  // 先把 prefix[ch][i] 抄过来
                lowercase[j][i + 1] = lowercase[j][i];
                uppercase[j][i + 1] = uppercase[j][i];
            }
            if ('a' <= s[i] && s[i] <= 'z')
                lowercase[tolower(s[i]) - 'a'][i + 1] ++;
            else
                uppercase[tolower(s[i]) - 'a'][i + 1] ++;
        }

        // 分治区间
        int i = 0, j = 0;  // 答案位置
        stack<pair<int, int>> q;
        q.push({0, n - 1});
        while (!q.empty()) {
            auto top = q.top(); q.pop();
            int start = top.first, end = top.second;
            bool valid = true;
            for (int k = start; k <= end; k ++) {
                // 字符 s[k] 在区间 [start, end] 大小写是否都出现
                int ch = tolower(s[k]) - 'a';
                int lower = lowercase[ch][end + 1] - lowercase[ch][start];
                int upper = uppercase[ch][end + 1] - uppercase[ch][start];
                // 只要 ch 大小写没同时出现，将区间 [start, end] 拆分为 [start,k-1], [k+1, end]
                if (!lower || !upper) {
                    // 注意下面顺序不可改：要最左侧:"dDzeE" 返回为 dD
                    q.push({k + 1, end});
                    q.push({start, k - 1});
                    valid = false;
                    break;  // 跳过，此区间 [start, end] 非法
                }
            }
            if (valid && end - start > j - i)
                i = start, j = end;
        }

        if (i == j)
            return "";
        return s.substr(i, j - i + 1);
    }


    void test() {
        time_t start = clock();
        string res = longestNiceSubstring("abcdefgfedcba");
        cout << "Result: " << res << endl;
        time_t end = clock();
        cout <<  "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};

