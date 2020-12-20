// Created by George Wu on 2020/12/19.

#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

/*
 * LeetCode-387：给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * PS：假定字符均为小写
 */

class FirstUniqueChar {
public:
    // 双指针：O(n), O(1)
    int firstUniqChar_1(string s) {

        // 若 s 为空串，返回 -1
        if (s.empty())
            return -1;

        for (int i = 0; i < s.size(); i ++)
            // 从左到右查找，第一次出现和最后一次出现的索引不同的第一个字符即为第一个不重复的字符
            if (s.find(s[i]) == s.rfind(s[i]))
                return i;

        return -1;
    }

    // 哈希表：O(n), O(n)；暴力解法：
    int firstUniqChar_21(string s) {

        // rec：<字符，字符出现的频次>， 初始化 rec
        unordered_map<char, int> rec;
        for (auto & c : s)
            rec[c] ++;

        // 找到第一个频次为 1 的字符，返回其索引
        for (int i = 0; i < s.size(); i ++)
            if (rec[s[i]] == 1)
                return i;

        return -1;
    }

    // 当 s 非常长时，我们不想遍历两次 s ，则用 rec 存储<字符，<字符出现的频次，字符索引>>
    int firstUniqChar_22(string s) {

        unordered_map<char, pair<int, int>> rec;
        for (int i = 0; i < s.size(); i ++) {
            rec[s[i]].first ++;
            rec[s[i]].second = i;
        }

        // 遍历 rec 中不重复的字符时，min_idx 表示频次为 1 的最小索引
        int min_idx = s.size();
        for (auto & iter : rec)
            if (iter.second.first == 1)
                min_idx = min(min_idx, iter.second.second);

        // 如果 min_idx 没有变化，则说明所有元素均为重复元素
        return min_idx == s.size() ? -1 : min_idx;
    }

    // 用索引代替字符：a-z -> 0-25
    int firstUniqChar_23(string s) {

        int freq[26] = {};

        for (char c : s)
            freq[c - 'a'] ++;

        for (int i = 0; i < s.size(); i ++)
            if (freq[s[i] - 'a'] == 1)
                return i;
        return -1;
    }

    void test_case() {
        string s1 = "leetcode";
        cout << firstUniqChar_1(s1) << endl;

        string s2 = "leeplcddc";
        cout << firstUniqChar_1(s2) << endl;

        string s3 = "##$#$!";
        cout << firstUniqChar_1(s3) << endl;
    }
};
