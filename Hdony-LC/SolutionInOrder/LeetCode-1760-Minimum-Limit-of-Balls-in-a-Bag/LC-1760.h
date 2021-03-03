// Created by wuyou on 2021/3/3.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/*
 * 题目：
 * 给一个整数数组 nums ，其中 nums[i] 表示第 i 个袋子里球的数目。
 * 给一个整数 maxOperations，可以进行如下操作至多 maxOperations 次：
 *     选择任意一个袋子，并将袋子里的球分到 2 个新的袋子中，每个袋子里都有 正整数 个球。
 *         例如，一个袋子里有 5 个球，把它们分到 2 个新袋子里，分别有 1 个和 4 个球，或者分别有 2 个和 3 个球。
 * 你的开销是单个袋子里球数目的 最大值 ，你想要 最小化 开销。
 * 请你返回进行上述操作后的最小开销。
 */

/*
 * 示例 1：
 * 输入：nums = [9], maxOperations = 2
 * 输出：3
 * 解释：
 * - 将装有 9 个球的袋子分成装有 6 个和 3 个球的袋子。[9] -> [6,3] 。
 * - 将装有 6 个球的袋子分成装有 3 个和 3 个球的袋子。[6,3] -> [3,3,3] 。
 * 装有最多球的袋子里装有 3 个球，所以开销为 3 并返回 3 。
 */

/*
 * 示例 2：
 * 输入：nums = [2,4,8,2], maxOperations = 4
 * 输出：2
 * 解释：
 * - 将装有 8 个球的袋子分成装有 4 个和 4 个球的袋子。[2,4,8,2] -> [2,4,4,4,2] 。
 * - 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,4,4,4,2] -> [2,2,2,4,4,2] 。
 * - 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,4,4,2] -> [2,2,2,2,2,4,2] 。
 * - 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2] 。
 * 装有最多球的袋子里装有 2 个球，所以开销为 2 并返回 2 。
 */

/*
 * 示例 3：
 * 输入：nums = [7,17], maxOperations = 2
 * 输出：7
 */

/*
 * 提示：
 * 1 <= nums.length <= 105
 * 1 <= maxOperations, nums[i] <= 109
 */


class MinimumLimitOfBallsInABag {
    using ll = long long;
public:
    bool check(vector<int>& nums, int cost, int maxOperations) {
        ll ans = 0;
        for (int cur : nums) {
            if(cur % cost == 0)
                ans += cur / cost - 1;
            else
                ans += cur / cost;
        }
        return ans <= maxOperations;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        ll l = 1, r = 1e9;
        ll ret = 0;
        while(l <= r) {
            ll mid = (r - l) / 2 + l;
            if(check(nums, mid, maxOperations)) {
                r = mid - 1;
                ret = mid;
            } else
                l = mid + 1;
        }
        return ret;
    }

    void test() {
        time_t start = clock();

        vector<int> nums = {7,17,25};
        int maxOperations = 4;
        int res = minimumSize(nums, maxOperations);

        cout << "Result: " << res << endl;
        time_t end = clock();
        cout <<  "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};
