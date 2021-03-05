/*
 * 有一个立方体房间，其长度、宽度和高度都等于 n 个单位。
 * 请你在房间里放置 n 个盒子，每个盒子都是一个单位边长的立方体。
 * 放置规则如下：
 *   你可以把盒子放在地板上的任何地方。
 *   如果盒子 x 需要放置在盒子 y 的顶部，那么盒子 y 竖直的四个侧面都 必须 与另一个盒子或墙相邻。
 *   给你一个整数 n ，返回接触地面的盒子的 最少 可能数量。
 */

#include <iostream>

using namespace std;

// Mathematics
// Time Complexity: O(sqrt(n))
// Space Complexity: O(1)
class Solution {
public:
    int minimumBoxes(int n) {

        int total = 0, res = 0;
        for (int h = 1; h <= n && total < n; h ++)
            for (int x = 1; x <= h && total < n; x ++)
                total += x, res ++;
        return res;
    }
};

class Solution1 {
public:
    int minimumBoxes(int n) {
        // 堆在墙角的话，每一层放满的数量依次为 1+3+6+10+ ... +k*(k+1)/2
        int k = 1, sum = 0;
        // 如果打算用 k 层去放置这 n 个箱子，放不下，就用 k+1 层试一试，直到可以放下为止
        while (sum + (k * (k + 1)) / 2 < n) {
            sum = sum + (k * (k + 1)) / 2;
            k ++;
        }
        k --;
        int res = (k * (k + 1)) / 2; // 此时 k 为箱子摞起来的高度

        cout << "k: " << k << " res:" << res;

        // 剩下不足一层的箱子直接
        k = 1;
        while (sum < n) {
            sum = sum + k;
            k ++;
            res ++;
        }
        return res;
    }
};

