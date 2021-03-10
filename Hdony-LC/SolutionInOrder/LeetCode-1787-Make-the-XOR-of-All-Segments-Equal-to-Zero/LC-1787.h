
/*
 * 给你一个整数数组 nums​​​ 和一个整数 k​​​​​ 。
 * 区间 [left, right]（left <= right）的 异或结果 是对下标位于 left 和 right（包括 left 和 right ）
 * 之间所有元素进行 XOR 运算的结果：nums[left] XOR nums[left+1] XOR ... XOR nums[right]。
 * 返回数组中 要更改的最小元素数 ，以使所有长度为 k 的区间异或结果等于零。
 */

/*
 * 示例 1：
 * 输入：nums = [1,2,0,3,0], k = 1
 * 输出：3
 * 解释：将数组 [1,2,0,3,0] 修改为 [0,0,0,0,0]
 */

/*
 * 示例 2：
 * 输入：nums = [3,4,5,2,1,7,3,4,7], k = 3
 * 输出：3
 * 解释：将数组 [3,4,5,2,1,7,3,4,7] 修改为
 *            [3,4,7,3,4,7,3,4,7]
 */

/*
 * 示例 3：
 * 输入：nums = [1,2,4,1,2,5,1,2,6], k = 3
 * 输出：3
 * 解释：将数组[1,2,4,1,2,5,1,2,6] 修改为
 *           [1,2,3,1,2,3,1,2,3]
 */

/*
 * 提示：
 * 1 <= k <= nums.length <= 2000
 * 0 <= nums[i] < 2^10
 */

// nums[i] = nums[i+k]

#include <vector>

using namespace std;

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        // freq[i][j] 表示 nums[i], nums[i+k], nums[i+2*k], nums[i+3*k] ... 这一序列中，等于 j 的元素个数
        vector<vector<int>> freq(k, vector<int>(1025, 0));
        for (int i = 0; i < n; i++)
            freq[i % k][nums[i]] ++;

        // dp[i][j] 表示 前 i 个数异或后等于 j, 所需要的最少改变次数
        vector<vector<int>> dp(k + 1, vector<int>(9, 2001));
        dp[0][0] = 0;

        for (int i = 0; i < k; i++) {
            int total = (n + (k - (i + 1))) / k; // 在每个周期性位置，最多可能变化几次，即总共有多少元素
            int prev_min_changes = *min_element(dp[i].begin(), dp[i].end());

            for (int j = 0; j <= 8; j++) {
                dp[i+1][j] = total + prev_min_changes;

                for (int index = i; index < n; index += k) {
                    int picked = nums[index];
                    int prev_j = picked ^ j;
                    if (prev_j > 8)
                        continue;
                    dp[i+1][j] = min(dp[i+1][j],
                                     dp[i][prev_j] + total - freq[i][picked]);
                }
            }
        }

        cout << endl;
        for (const auto& f : dp) {
            for (auto item : f){
                cout << item << " ";
            }
            cout << endl;
        }

        return dp[k][0];
    }

    void test() {

        // freq:
        // 0 0 1 2 0 0 0 0 0 0 --> 表示 [3,2,3] 中，2 有 1 个， 3 有 2 个，
        // 0 1 0 0 2 0 0 0 0 0
        // 0 0 0 0 0 1 0 2 0 0
        vector<int> nums1{3,4,5,2,1,7,3,4,7};
        cout << minChanges(nums1, 3) << endl; // 3


//        vector<int> nums2{3,4,5,2,1,7,3,4,7};
//        cout << minChanges(nums2, 4) << endl;
    }
};