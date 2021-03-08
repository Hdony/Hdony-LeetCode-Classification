#include <vector>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

/*
 * There is an undirected weighted connected graph.
 * You are given a positive integer n which denotes that the graph has n nodes labeled from 1 to n,
 * and an array edges where each edges[i] = [ui, vi, weighti] denotes that there is an edge
 * between nodes ui and vi with weight equal to weighti.
 * A path from node start to node end is a sequence of nodes [z0, z1, z2, ..., zk] such that
 * z0 = start and zk = end and there is an edge between zi and zi+1 where 0 <= i <= k-1.
 * The distance of a path is the sum of the weights on the edges of the path.
 * Let distanceToLastNode(x) denote the shortest distance of a path between node n and node x.
 * A restricted path is a path that also satisfies that distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1.
 * Return the number of restricted paths from node 1 to node n. Since that number may be too large, return it modulo 109 + 7.
 */

/*
 * Input: n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
 * Output: 3
 * Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The three restricted paths are:
 * 1) 1 --> 2 --> 5
 * 2) 1 --> 2 --> 3 --> 5
 * 3) 1 --> 3 --> 5
 */

/*
 * Input: n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
 * Output: 1
 * Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue.
 * The only restricted path is 1 --> 3 --> 7.
 */

/*
 * Constraints:
 * 1 <= n <= 2 * 104
 * n - 1 <= edges.length <= 4 * 104
 * edges[i].length == 3
 * 1 <= ui, vi <= n
 * ui != vi
 * 1 <= weighti <= 105
 * There is at most one edge between any two nodes.
 * There is at least one path between any two nodes.
 */

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        constexpr int kMod = 1e9 + 7;
        using PII = pair<int, int>; // pair<相邻节点索引，和相邻节点的距离>
        vector<vector<PII>> g(n + 1);

        // 构建邻接表
        for (const auto & e : edges) {
            g[e[0]].emplace_back(e[1], e[2]);
            g[e[1]].emplace_back(e[0], e[2]);
        }

        // dist[u] 表示从 u 节点到 n 节点的最短路径长度
        vector<int> dist(n + 1, INT_MAX / 2); // INT_MAX 防止整形溢出，除以 2
        dist[n] = 0; // 节点 n 与自身的距离为 0
        priority_queue<PII, vector<PII>, greater<>> q;
        q.emplace(0, n); // 先将 节点 n ，以及它到自身的距离存入 q
        // 计算每一个节点到节点 n 的最短路径
        while (!q.empty()) {
            const auto node = q.top(); q.pop();
            int d = node.first, u = node.second;
            if (d > dist[u]) continue;
            for (auto adj : g[u]) {
                int v = adj.first, w = adj.second;
                if (dist[v] > dist[u] + w)
                    q.emplace(dist[v] = dist[u] + w, v);
            }
        }

        // dp[u] 表示节点 u 到节点 n 的限制性路径的条数
        vector<int> dp(n + 1, INT_MAX);
        function<int(int)> dfs = [&](int u) {

            if (u == n) return 1;
            if (dp[u] != INT_MAX) return dp[u];
            int ans = 0;
            for (auto adj : g[u]) {
                int v = adj.first;
                if (dist[u] > dist[v])
                    ans = (ans + dfs(v)) % kMod;
            }
            return dp[u] = ans;
        };
        return dfs(1);
    }
};

