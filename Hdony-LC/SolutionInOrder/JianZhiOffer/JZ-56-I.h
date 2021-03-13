/*
 * 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
 * 请写程序找出这两个只出现一次的数字。
 * 要求时间复杂度是 O(n) ，空间复杂度是 O(1) 。
 *
 * 示例 1：
 * 输入：nums = [4,1,4,6]
 * 输出：[1,6] 或 [6,1]
 *
 * 示例 2：
 * 输入：nums = [1,2,10,4,1,4,3,3]
 * 输出：[2,10] 或 [10,2]
 *
 * 限制：
 * 2 <= nums.length <= 10000
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 异或
// [7,3,5,3,5] -> 7^3^5^3^5 = 7
// 如果我们可以把所有数字分成两组，使得：
//   1. 两个只出现一次的数字在不同的组中；
//   2. 相同的数字会被分到相同的组中。
//
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        for (int n : nums)
            ret ^= n;
        int div = 1;
        while ((div & ret) == 0)
            div <<= 1;
        int a = 0, b = 0;
        for (int n : nums)
            if (div & n) {
                a ^= n;
                cout << " a:" << n << ", ";
            }

            else {
                cout << " b:" << n << ", ";
                b ^= n;
            }

        return vector<int>{a, b};
    }

    void test() {
        vector<int> nums{9,1,2,10,4,1,4,3,9,3};
        singleNumbers(nums);
    }
};