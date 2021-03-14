/*
 * 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
 *
 * 示例 1:
 * 输入: "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 * 示例 2:
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 * 示例 3:
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 *      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 * 提示：
 * s.length <= 40000
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>

using namespace std;

// Sliding Window
// Time Complexity: O(len(s))
// Space Complexity: O(len(charset))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int freq[256] = {0};

        int l = 0, r = -1; // sliding window: s[l...r]
        int res = 0;

        while (r + 1 < s.size()) {

            if ( freq[s[r + 1]] == 0 )
                freq[s[++r]] ++;
            else    //freq[s[r+1]] == 1
                freq[s[l++]] --;

            res = max(res, r - l + 1);
        }

        return res;
    }
};


// Sliding Window
// Another Implementation
//
// Time Complexity: O(len(s))
// Space Complexity: O(len(charset))
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {

        int freq[256] = {0};

        int l = 0, r = -1; // sliding window: s[l...r]
        int res = 0;

        while (r + 1 < s.size()) {

            while (r + 1 < s.size() && freq[s[r + 1]] == 0)
                freq[s[++r]] ++;

            res = max(res, r - l + 1);

            if (r + 1 < s.size()) {
                freq[s[++r]] ++;
                assert(freq[s[r]] == 2);
                while (l <= r && freq[s[r]] == 2)
                    freq[s[l++]] --;
            }
        }
        return res;
    }
};