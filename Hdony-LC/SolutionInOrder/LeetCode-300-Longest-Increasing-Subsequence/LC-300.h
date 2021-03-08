
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

// DP
// Time Complexity: O(n^2)
// Space Complexity: O(n)
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

// DP + Greedy + Binary Search
// Time Comlexity: O(nlogn)
// Space Complexity: O(n)
class Solution1 {
public:
    int lengthOfLIS(vector<int> & nums) {
        vector<int> dp; // dp[i]: 长度为 i 的最长上升子序列的最小末尾数字为 dp[i]
        for (int x : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), x);
            if (it == dp.end())
                dp.push_back(x);
            else
                *it = x;
        }
        return dp.size(); // 不关心除末尾以外的数字，dp 的长度即为 LIS
    }

    void test() {
        vector<int> nums{2,3,1,4,8,5,6};
        cout << lengthOfLIS(nums);
        /*
         * 2
         * 2 3
         * 1 3
         * 1 3 4
         * 1 3 4 8
         * 1 3 4 5
         * 1 3 4 5 6
         */
    }
};





