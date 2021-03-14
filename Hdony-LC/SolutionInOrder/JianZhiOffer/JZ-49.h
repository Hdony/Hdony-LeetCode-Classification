/*
 * 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。
 * 求按从小到大的顺序的第 n 个丑数。
 *
 * 示例:
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 *
 * 说明:  
 * 1 是丑数。
 * n 不超过1690。
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue <double, vector<double>, greater<>> q;
        double ans = 1;
        for (int i = 1; i < n; ++i) {
            q.push(ans * 2);
            q.push(ans * 3);
            q.push(ans * 5);
            ans = q.top();
            q.pop();
            while (!q.empty() && ans == q.top())
                q.pop();
        }
        return ans;
    }
};

// DP: 小顶堆的方法是先存再排，dp 的方法则是先排再存
class Solution1 {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0; // 代表的是第几个数的 2 倍、第几个数 3 倍、第几个数 5 倍

        // dp[i] 表示从小到大的顺序的第 i 个丑数
        for (int i = 1; i < n; ++i) {
            dp[i] = min(min(2 * dp[p2], 3 * dp[p3]), 5 * dp[p5]);
            if (dp[i] == 2 * dp[p2])
                ++p2;
            if (dp[i] == 3 * dp[p3])
                ++p3;
            if (dp[i] == 5 * dp[p5])
                ++p5;
        }
        return dp[n - 1];
    }
};
