/*
 * 一个字符串的 美丽值 定义为：出现频率最高字符与出现频率最低字符的出现次数之差。
 * 比方说，"abaacc" 的美丽值为 3 - 1 = 2 。
 * 给你一个字符串 s ，请你返回它所有子字符串的 美丽值 之和。
 *
 * 示例 1：
 * 输入：s = "aabcb"
 * 输出：5
 * 解释：美丽值不为零的字符串包括 ["aab","aabc","aabcb","abcb","bcb"] ，每一个字符串的美丽值都为 1 。
 *
 * 示例 2：
 * 输入：s = "aabcbaa"
 * 输出：17
 *
 * 提示：
 * 1 <= s.length <= 500
 * s 只包含小写英文字母。
 */

// 子串长度 >= 3,

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

// 枚举子串起点，用 multiset 维护一个子串中不同字符的出现频次。
// Time Complexity: O(n^2*logn)
// Time Complexity: O(n^2*logn)
class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) { // 固定子串开头字母，不断添加新字母进入子串
            multiset<int> st;
            vector<int> cnt(26);
            for (int j = i; j < n; ++j) {
                int c = s[j] - 'a';
                if (st.find(cnt[c]) != st.end()) // 如果某一个字母 c 的频次出现过
                    st.erase(st.find(cnt[c])); // 就删除这个频次，并加 1，再添加回去
                st.insert(++cnt[c]);
                ans += *st.rbegin() - *st.begin();
            }
        }
        return ans;
    }

    void test() {
        cout << beautySum("aabcb");
    }
};

// 滑动窗口
class Solution1 {
public:
    int beautySum(string s) {
        int n = s.size(), sum = 0;
        for(int len = 2; len <= n; ++len) {
            int r = 0, l = 0, minN = INT_MAX, maxN = INT_MIN;
            vector<int> nums(26, 0); // 使用数组存储每个字符的数量
            while (r < n) { // 滑动窗口
                nums[s[r] - 'a'] ++;
                r ++;
                if (r - l == len) {
                    minN = INT_MAX;
                    maxN = INT_MIN;
                    for (int i = 0; i < 26; ++i) {
                        if (nums[i] > 0) {
                            minN = min(minN, nums[i]);
                            maxN = max(maxN, nums[i]);
                        }
                    }
                    sum += maxN - minN;
                    nums[s[l] - 'a'] --;
                    l ++;
                }
            }
        }
        return sum;
    }
};

class Solution2 {
public:
    int beautySum(string s)
    {
        int n = s.size();
        int res = 0;
        for (int L = 0; L < n; L ++) {
            unordered_map<char, int> dic;
            for (int R = L; R < n; R ++) {
                dic[s[R]] ++;
                if (!dic.empty()) {
                    int min_ = 0x3f3f3f3f;
                    int max_ = -0x3f3f3f3f;
                    for (auto [c, freq]: dic) {
                        min_ = min(min_, freq);
                        max_ = max(max_, freq);
                    }
                    res += (max_ - min_);
                }
            }
        }
        return res;
    }
};
