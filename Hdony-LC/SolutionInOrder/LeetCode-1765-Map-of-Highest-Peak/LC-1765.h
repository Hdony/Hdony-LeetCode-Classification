// Created by wuyou on 2021/3/1.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * 题目：
 * 给定一个大小为 m x n 的整数矩阵 isWater ，它代表了一个由 陆地 和 水域 单元格组成的地图。
 *     如果 isWater[i][j] == 0 ，格子 (i, j) 是一个 陆地 格子。
 *     如果 isWater[i][j] == 1 ，格子 (i, j) 是一个 水域 格子。
 * 你需要按照如下规则给每个单元格安排高度：
 *     每个格子的高度都必须是非负的。
 *     如果一个格子是 水域 ，那么它的高度必须为 0 。
 *     任意相邻的格子高度差 至多 为 1 。当两个格子在正东、南、西、北方向上相互紧挨着，就称它们为相邻的格子。
 *     （也就是说它们有一条公共边）
 * 找到一种安排高度的方案，使得矩阵中的最高高度值 最大 。
 * 返回一个大小为 m x n 的整数矩阵 height ，其中 height[i][j] 是格子 (i, j) 的高度。
 * 如果有多种解法，请返回 任意一个 。
 */

/*
 * 示例 1：
 * 输入：isWater = [[0,1],
 *                 [0,0]]
 * 输出：[[1,0],
 *       [2,1]]
 */

/*
 * 示例 2：
 * 输入：isWater = [[0,0,1],
 *                 [1,0,0],
 *                 [0,0,0]]
 * 输出：[[1,1,0],
 *       [0,1,1],
 *       [1,2,2]]
 */

/*
 * 提示：
 * m == isWater.length
 * n == isWater[i].length
 * 1 <= m, n <= 1000
 * isWater[i][j] 要么是 0 ，要么是 1 。
 * 至少有 1 个水域格子
 */

class MapOfHighestPeak {
public:

    // 对 isWater 进行 inplace 修改，得到相同大小的高度矩阵
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size(), dir[5] = {0, 1, 0, -1, 0}, INF = 1e6+1;
        queue<pair<int,int>> q;
        // 将有水的坐标入队，初始化队列元素
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (isWater[i][j]) {
                    isWater[i][j] = 0;
                    q.push({i, j});
                } else
                    isWater[i][j] = INF; // 初始化为无穷大
            }
        }
        int height = 1;
        while (!q.empty()) {
            int size = q.size();
            // 遍历所有相同海拔 height 的区域（共有 size 个），遍历完 height ++
            while (size --) {
                auto cur = q.front();
                q.pop();
                for (int i = 0; i < 4; i ++) {
                    int r = cur.first + dir[i], c = cur.second + dir[i + 1];
                    if (r < 0 || c < 0 || r >= m || c >= n)
                        continue;

                    if (height < isWater[r][c]) { // 有 visited 的作用
                        isWater[r][c] = height;
                        q.push({r,c});
                    }
                }
            }
            height++;
        }
        return isWater;
    }

    void test() {
        time_t start = clock();
        vector<vector<int>> isWater = {{0,0,1},{1,0,0},{0,0,0}};
        vector<vector<int>> results = highestPeak(isWater);
        time_t end = clock();
        for (const auto& result : results) {
            for (auto i : result) {
                cout << i << " ";
            }
            cout << endl;
        }
        cout <<  "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};



