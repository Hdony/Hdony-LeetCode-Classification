// Created by wuyou on 2021/2/25.

#include <iostream>
#include <vector>

using namespace std;

/*
 * 给你两个长度分别 n 和 m 的整数数组 nums 和 multipliers ，其中 n >= m ，数组下标从 1 开始计数。
 * 初始时，你的分数为 0 。你需要执行恰好 m 步操作。在第 i 步操作（从 1 开始计数）中，需要：
 *  选择数组 nums 开头处或者末尾处的整数 x 。
 *  你获得 multipliers[i] * x 分，并累加到你的分数中。
 *  将 x 从数组 nums 中移除。
 *  在执行 m 步操作后，返回最大分数。
 */

/*
 * 示例 1：
 * 输入：nums = [1,2,3], multipliers = [3,2,1]
 * 输出：14
 * 解释：一种最优解决方案如下：
 * - 选择末尾处的整数 3 ，[1,2,3] ，得 3 * 3 = 9 分，累加到分数中。
 * - 选择末尾处的整数 2 ，[1,2] ，得 2 * 2 = 4 分，累加到分数中。
 * - 选择末尾处的整数 1 ，[1] ，得 1 * 1 = 1 分，累加到分数中。
 * 总分数为 9 + 4 + 1 = 14 。
 */

/*
 * 示例 2：
 * 输入：nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
 * 输出：102
 * 解释：一种最优解决方案如下：
 * - 选择开头处的整数 -5 ，[-5,-3,-3,-2,7,1] ，得 -5 * -10 = 50 分，累加到分数中。
 * - 选择开头处的整数 -3 ，[-3,-3,-2,7,1] ，得 -3 * -5 = 15 分，累加到分数中。
 * - 选择开头处的整数 -3 ，[-3,-2,7,1] ，得 -3 * 3 = -9 分，累加到分数中。
 * - 选择末尾处的整数 1 ，[-2,7,1] ，得 1 * 4 = 4 分，累加到分数中。
 * - 选择末尾处的整数 7 ，[-2,7] ，得 7 * 6 = 42 分，累加到分数中。
 * 总分数为 50 + 15 - 9 + 4 + 42 = 102 。
 */

/*
 * 提示：
 *  n == nums.length
 *  m == multipliers.length
 *  1 <= m <= 103
 *  m <= n <= 105
 *  -1000 <= nums[i], multipliers[i] <= 1000
 */

/*
 * 解析：
 * 一共从 nums 数组中选取 m 个数字，将其与 multipliers 中的 m 个数字对应相乘，取最大分数即可。
 * multipliers 中每一个数字对应有一头一尾两个选择，由于 n >= m ， 那么暴力法（dfs或者bfs），
 * 可能性将达到2^1000次，超时。如何剪枝是关键。
 * 这里采用动态规划的解法，关键点在于如何定义状态。
 *
 * 定义二维数组 MaxFromNums[m + 1][m + 1]。
 *   dp[i][j]：表示nums数组中前i个数和后j个数组成的最大分数。
 *   dp[0][0] = 0;
 *   dp[i][0]：此状态表示 nums 数组中前 i 个数和后 0 个数组成的最大分数，
 *             此状态只可能由 dp[i - 1][0] 转移得到。
 *   dp[0][j]：此状态表示 nums 数组中前 0 个数和后 j 个数组成的最大分数，
 *             此状态只可能由 dp[0][j - 1] 转移得到。
 *   dp[i][j]：该状态表示nums数组中前 i 个数和后 j 个数组成的最大分数，
 *             可能由状态 dp[i - 1][j] 和状态 dp[i][j - 1] 转移得到，取其中得分最大的一个。
 *             遍历所有可能的组合（满足 i + j = m ）获得最大得分。
 */

class MaximumScoreFromPerformingMultiplicationOperations {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {

        int n = nums.size(), m = multipliers.size();
        int dp[100][100] = {};

        // 如果都从 nums 的前面取数字，直接对应索引位置相乘即可
        for (int i = 1; i <= m; ++i)
            dp[i][0] = dp[i - 1][0] + nums[i - 1] * multipliers[i - 1];

        // 如果都从 nums 的后面取数字，直接对应倒序索引位置相乘即可
        for (int j = 1; j <= m; ++j)
            dp[0][j] = dp[0][j - 1] + nums[n - j] * multipliers[j - 1];

        for (int i = 1; i <= m; ++i)
            for (int j = 1; i + j <= m; ++j)
                dp[i][j] = max(dp[i - 1][j] + nums[i - 1] * multipliers[i + j - 1],
                               dp[i][j - 1] + nums[n - j] * multipliers[i + j - 1]);

        int res = INT_MIN;
        for (int i = 0; i <= m; ++i)
            res = max(res, dp[i][m - i]);

        return res;
    }

    void test() {
        time_t start = clock();
        vector<int> nums = {-5,-3,-3,-2,7,1,7}, multipliers = {-10,-5,3,4,6};

        int res = maximumScore(nums, multipliers);
        time_t end = clock();
        cout << "Result = " << res << endl;
        cout << "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};
