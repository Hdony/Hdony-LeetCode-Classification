
/*
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 */

/*
 * 示例 1：
 * 输入：nums = [10,9,2,5,3,7,101,18]
 * 输出：4
 * 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 */

/*
 * 示例 2：
 * 输入：nums = [0,1,0,3,2,3]
 * 输出：4
 */

/*
 * 示例 3：
 * 输入：nums = [7,7,7,7,7,7,7]
 * 输出：1
 */

/*
 * 提示：
 * 1 <= nums.length <= 2500
 * -104 <= nums[i] <= 104
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> & nums) {
        const int n = nums.size();
        // 以 nums[i] 结尾的最长递增子序列的长度
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
        return *max_element(begin(dp), end(dp));
    }

    void test() {
        vector<int> nums{2,3,1,4,8,5,6};
        cout << lengthOfLIS(nums);
    }
};







