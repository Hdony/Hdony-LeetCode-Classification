/*
 * 有 n 个小球，编号从 lowLimit 开始，到 highLimit 结束
 * （包括 lowLimit 和 highLimit ，即 n == highLimit - lowLimit + 1）。
 * 另有无限数量的盒子，编号从 1 到 infinity 。
 * 将每个小球放入盒子中，其中盒子的编号应当等于小球编号上每位数字的和。
 * 例如，编号 321 的小球应当放入编号 3 + 2 + 1 = 6 的盒子，
 * 编号 10 的小球应当放入编号 1 + 0 = 1 的盒子。
 *
 * 给你两个整数 lowLimit 和 highLimit ，返回放有最多小球的盒子中的小球数量。
 * 如果有多个盒子都满足放有最多小球，只需返回其中任一盒子的小球数量。
 */

/*
 * 示例 1：
 * 输入：lowLimit = 1, highLimit = 10
 * 输出：2
 * 解释：
 * 盒子编号：1 2 3 4 5 6 7 8 9 10 11 ...
 * 小球数量：2 1 1 1 1 1 1 1 1 0  0  ...
 * 编号 1 的盒子放有最多小球，小球数量为 2 。
 */

/*
 * 示例 2：
 * 输入：lowLimit = 5, highLimit = 15
 * 输出：2
 * 解释：
 * 盒子编号：1 2 3 4 5 6 7 8 9 10 11 ...
 * 小球数量：1 1 1 1 2 2 1 1 1 0  0  ...
 * 编号 5 和 6 的盒子放有最多小球，每个盒子中的小球数量都是 2 。
 */

/*
 * 示例 3：
 * 输入：lowLimit = 19, highLimit = 28
 * 输出：2
 * 解释：
 * 盒子编号：1 2 3 4 5 6 7 8 9 10 11 12 ...
 * 小球数量：0 1 1 1 1 1 1 1 1 2  0  0  ...
 * 编号 10 的盒子放有最多小球，小球数量为 2 。
 */

/*
 * 提示：
 * 1 <= lowLimit <= highLimit <= 105
 */

#include <iostream>
#include <unordered_map>

using namespace std;

// Using HashMap
// Time Complexity: O((h - l) * log(h))
// Space Complexity: O(h - l)
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {

        unordered_map<int, int> f;
        int res = 0;
        for (int i = lowLimit; i <= highLimit; i ++) {
            int k = hash(i);
            f[k] ++;
            res = max(res, f[k]);
        }
        return res;
    }

private:
    int hash(int x) {

        int sum = 0;
        while(x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
};

















