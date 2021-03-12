/*
 * 把 n 个骰子扔在地上，所有骰子朝上一面的点数之和为 s。
 * 输入 n，打印出 s 的所有可能的值出现的概率。
 * 你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。
 *
 * 示例 1:
 * 输入: 1
 * 输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
 *
 * 示例 2:
 * 输入: 2
 * 输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
 *        2       3       4       5       6       7       8       9       10      11      12
 * 限制：
 * 1 <= n <= 11
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// [n, n*6]
// dp[i][j] 表示 i 个骰子，点数和为 j 的概率
// dp[i][j] = (dp[i-1][j-1] + dp[i-1][j-2] + dp[i-1][j-3]+ ... + dp[i-1][j-6]) / 6
// Time Complexity: O(n^2)
//   状态转移循环 n−1 轮；每轮中，当 i=2,3,...,n 时，对应循环数量分别为 66×6,11×6,...,[5(n−1)+1]×6
// Space Complexity: O(n)
//   状态转移过程中，辅助数组 tmp 最大长度为 6(n−1)−[(n−1)−1]=5n−4，因此使用 O(5n−4)=O(n) 大小的额外空间。

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> dp(6, 1.0 / 6.0);
        for (int i = 2; i <= n; i++) {
            vector<double> tmp(5 * i + 1, 0); // n 个骰子，共产生 5*n+1 个概率
            for (int j = 0; j < dp.size(); j++)
                for (int k = 0; k < 6; k++)
                    tmp[j + k] += dp[j] / 6.0;
            dp = tmp;
        }
        return dp;
    }

    void test() {
        vector<double> res = dicesProbability(3);
        for (auto r : res)
            cout << r << " ";
    }
};
