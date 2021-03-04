#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * 给一个数组 nums 。nums 的源数组中，所有元素与 nums 相同，但按非递减顺序排列。
 * 如果 nums 能够由源数组轮转若干位置（包括 0 个位置）得到，则返回 true ；否则，返回 false 。
 * 源数组中可能存在 重复项 。
 * 注意：我们称数组 A 在轮转 x 个位置后得到长度相同的数组 B ，
 * 当它们满足 A[i] == B[(i+x) % A.length] ，其中 % 为取余运算。
 */

// Linear Scan
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
    bool check(vector<int>& nums) {

        int i, n = nums.size();

        // 如果找到了 nums 递减的位置 i，则停止循环
        for (i = 1; i < n; i ++)
            if (nums[i - 1] > nums[i])
                break;
        // 如果递减的位置是末尾，则直接可以将这个单一元素和前面的序列换位，返回 true
        if (i == n)
            return true;

        // 如果除了 i 还有递减的位置，则说明无论如何换位都不能保证源序列递增
        for (int j = i + 1; j < n; j ++)
            if (nums[j - 1] > nums[j])
                return false;
        // 运行到此，说明 nums 是由两个递增序列组成的，如果前面的递增序列的最小值大于后面递增序列的最大值
        // 则说明可以对调两个序列的顺序，否则，序列存在交叉，不能转化为递增源序列
        return nums[0] >= nums.back();
    }
};

