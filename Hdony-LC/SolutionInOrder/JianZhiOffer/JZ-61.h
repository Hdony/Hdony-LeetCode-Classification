/*
 * 从扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这 5 张牌是不是连续的。
 * 2-10 为数字本身，A 为 1，J 为 11，Q 为 12，K 为 13，而大、小王为 0 ，可以看成任意数字。
 * A 不能视为 14。
 *
 * 示例 1:
 * 输入: [1,2,3,4,5]
 * 输出: True
 *
 * 示例 2:
 * 输入: [0,0,1,2,5]
 * 输出: True
 *
 * 限制：
 * 数组长度为 5 
 * 数组的数取值为 [0, 13]
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// max-min < 5 如果 >= 0 则即使全部是 0（小王）也不行
// 除了 0 （大小王）外，所有 num 都不能重复，否则无法组成顺子
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        vector<int> existed(14,0);
        int minVal = 13, maxVal = 0;
        for (int num : nums) {
            if (num != 0) {
                if (existed[num] == 0) {
                    existed[num] = 1;
                    minVal = min(minVal, num);
                    maxVal = max(maxVal, num);
                } else
                    return false; // 出现重复了
            }
        }
        return maxVal - minVal < 5;
    }

    void test() {
        vector<int> nums{0,0,1,5,6};
        cout << isStraight(nums);
    }
};

// 排序
class Solution1 {
public:
    bool isStraight(vector<int>& nums) {
        int joker = 0;
        sort(nums.begin(), nums.end()); // 数组排序
        for (int i = 0; i < 4; i++) {
            if (nums[i] == 0)
                joker++; // 统计大小王数量
            else if (nums[i] == nums[i + 1])
                return false; // 若有重复，提前返回 false
        }
        return nums[4] - nums[joker] < 5; // 最大牌 - 最小牌 < 5 则可构成顺子
    }

    void test() {
        vector<int> nums{0,0,1,5,6};
        cout << isStraight(nums);
    }
};
