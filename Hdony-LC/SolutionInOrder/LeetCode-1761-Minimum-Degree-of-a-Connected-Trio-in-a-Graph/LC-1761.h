// Created by wuyou on 2021/3/2.

#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
 * 题目：
 * 给你一个无向图，整数 n 表示图中节点的数目，edges 数组表示图中的边，其中 edges[i] = [ui, vi] ，表示 ui 和 vi 之间有一条无向边。
 * 一个 连通三元组 指的是 三个 节点组成的集合且这三个点之间 两两 有边。
 * 连通三元组的度数 是所有满足此条件的边的数目：一个顶点在这个三元组内，而另一个顶点不在这个三元组内。
 * 返回所有连通三元组中度数的 最小值 ，如果图中没有连通三元组，那么返回 -1 。
 */

/*
 * 示例 1：
 * 输入：n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]
 * 输出：3
 * 解释：只有一个三元组 [1,2,3] 。构成度数的边在上图中已被加粗。
 */

/*
 * 示例 2：
 * 输入：n = 7, edges = [[1,3],[4,1],[4,3],[2,5],[5,6],[6,7],[7,5],[2,6]]
 * 输出：0
 * 解释：有 3 个三元组：
 *   1. [1,4,3]，度数为 0
 *   2. [2,5,6]，度数为 2
 *   3. [5,6,7]，度数为 2
 */

/*
 * 提示：
 *   2 <= n <= 400
 *   edges[i].length == 2
 *   1 <= edges.length <= n * (n-1) / 2
 *   1 <= ui, vi <= n
 *   ui != vi
 *   图中没有重复的边
 */


class MinimumDegreeOfAConnectedTrioInAGraph {
public:
    // 邻接表
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<set<int>> al(n + 1); // Adjacency List
        vector<int> cnt(n + 1);
        int res = INT_MAX;

        // 初始化邻接表
        for (auto & e: edges) {
            al[min(e[0], e[1])].insert(max(e[0], e[1])); // 有向邻接表
            cnt[e[0]] ++;
            cnt[e[1]] ++;
        }

        // 遍历邻接表的每一行
        for (auto t1 = 1; t1 <= n; t1 ++)
            for (auto it2 = begin(al[t1]); it2 != end(al[t1]); it2 ++) // 和 t1 连通的 t2
                for (auto it3 = next(it2); it3 != end(al[t1]); it3 ++) // 和 t1 连通 且 和 t2 不重复的 t3
                    if (al[*it2].count(*it3)) // 如果 t2 与 t3 也联通，说明找到了一个连通三元组
                        res = min(res, cnt[t1] + cnt[*it2] + cnt[*it3] - 6);
        return res == INT_MAX ? -1 : res;
    }

    // 邻接矩阵
    int minTrioDegree_(int n, vector<vector<int>>& edges) {
        vector<vector<int>> am(n + 1, vector<int>(n + 1)); // Adjacency Matrix
        vector<int> cnt(n + 1);
        int res = INT_MAX;
        for (auto & e: edges) {
            am[min(e[0], e[1])][max(e[0], e[1])] = 1;
            cnt[e[0]] ++;
            cnt[e[1]] ++;
        }
        for (int t1 = 1; t1 <= n; t1 ++)
            for (int t2 = t1 + 1; t2 <= n; t2 ++)
                if (am[t1][t2])
                    for (int t3 = t2 + 1; t3 <= n; t3 ++)
                        if (am[t1][t3] && am[t2][t3])
                            res = min(res, cnt[t1] + cnt[t2] + cnt[t3] - 6);
        return res == INT_MAX ? -1 : res;
    }

    void test() {
        time_t start = clock();
//        vector<vector<int>> edges = {{1,3},{4,1},{4,3},{2,5},{5,6},{6,7},{7,5},{2,6}};
        vector<vector<int>> edges_ = {{1,2},{1,3},{3,2},{4,1},{5,2},{3,6}};
//        int res = minTrioDegree(7, edges);
        int res_ = minTrioDegree(6, edges_);
        cout << "Result: " << res_ << endl;
        time_t end = clock();
        cout <<  "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};
