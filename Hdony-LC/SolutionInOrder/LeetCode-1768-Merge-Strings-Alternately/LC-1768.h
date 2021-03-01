// Created by wuyou on 2021/2/26.

#include <iostream>
#include <vector>

using namespace std;

/*
 * 题目：
 * 给你两个字符串 word1 和 word2 。
 * 从 word1 开始，通过交替添加字母来合并字符串。
 * 如果一个字符串比另一个字符串长，就将多出来的字母追加到合并后字符串的末尾。
 * 返回 合并后的字符串 。
 */

/*
 * 示例 1
 * 输入：word1 = "abc", word2 = "pqr"
 * 输出："apbqcr"
 * 解释：字符串合并情况如下所示：
 * word1：  a   b   c
 * word2：    p   q   r
 * 合并后：  a p b q c r
 */

/*
 * 示例 2：
 * 输入：word1 = "ab", word2 = "pqrs"
 * 输出："apbqrs"
 * 解释：注意，word2 比 word1 长，"rs" 需要追加到合并后字符串的末尾。
 * word1：  a   b
 * word2：    p   q   r   s
 * 合并后：  a p b q   r   s
 */

/*
 * 示例 3：
 * 输入：word1 = "abcd", word2 = "pq"
 * 输出："apbqcd"
 * 解释：注意，word1 比 word2 长，"cd" 需要追加到合并后字符串的末尾。
 * word1：  a   b   c   d
 * word2：    p   q
 * 合并后：  a p b q c   d 
 */

/*
 * 提示：
 * 1 <= word1.length, word2.length <= 100
 * word1 和 word2 由小写英文字母组成
 */

class MergeStringsAlternately {
public:
    // 双指针
    string mergeAlternately(string w1, string w2) {
        int i = 0, j = 0;
        string res;
        while (i < w1.size() && j < w2.size())
            res += string() + w1[i++] + w2[j++];
        return res + w1.substr(i) + w2.substr(j);
    }

    // 单指针
    string mergeAlternately_1Pointer(string w1, string w2) {
        int p = 0, sz = min(w1.size(), w2.size());
        string res;
        while (p < sz) {
            res += string() + w1[p] + w2[p];
            p ++;
        }
        return res + w1.substr(p) + w2.substr(p);
    }

    // 不需要创建临时string
    string mergeAlternately_0TempString(string w1, string w2) {
        int i = 0, j = 0, sz1 = w1.size(), sz2 = w2.size();
        string res;
        while (i < sz1 || j < sz2) {
            if (i < sz1)
                res += w1[i++];
            if (j < sz2)
                res += w2[j++];
        }
        return res;
    }

    void test() {
        time_t start = clock();
//        string res = mergeAlternately("abcd", "123456");
//        string res_1p = mergeAlternately_1Pointer("abcd", "123456");
        string res_0s = mergeAlternately_0TempString("abcd", "123456");
        time_t end = clock();
        cout << "Result = " << res_0s << endl;
        cout <<  "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }

};