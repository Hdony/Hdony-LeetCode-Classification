// Created by wuyou on 2021/3/1.

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
 * 题目：
 * 给定一个 n 个节点的树，节点编号从 0 到 n-1 ，且恰好有 n-1 条边，每个节点有一个值。
 * 树的根节点为 0 号点。
 * 给定一个整数数组 nums 和一个二维数组 edges 来表示这棵树。nums[i] 表示第 i 个点的值，edges[j] = [uj, vj] 表示节点 uj 和节点 vj 在树中有一条边。
 * 当 gcd(x, y) == 1 ，称两个数 x 和 y 是互质的，其中 gcd(x, y) 是 x 和 y 的最大公约数 。
 * 从节点 i 到根最短路径上的点都是节点 i 的祖先节点。
 * 一个节点不是它自己的祖先节点。
 * 返回一个大小为 n 的数组 ans，其中 ans[i] 是离节点 i 最近的祖先节点且满足 nums[i] 和 nums[ans[i]] 是互质的，如果不存在这样的祖先节点，ans[i] 为 -1。
 */

/*
 * 1. 邻接表 adj[a][b] 表示每个节点 a 关联了节点 b 。
 * 2. 准备 50 个栈，以每个节点的 val 为基准，栈内存储的数据为当前数据值对应的层数 depth 及节点序号 i 。
 * 3. 遍历到某个节点时，以当前节点为基准，满足 gcd == 1 且层数最深的为最优解，也就是最近的公共祖先节点
 * 4. 满足 gcd 条件可能存在多个节点的数据值，遍历可能的数据值里面，离节点i最近的，通过 level 来识别；这里需要识别数值和 level 两重条件
 * 5. 为啥取栈顶的元素呢，因为我们压栈的时候，level 最大的总是在栈顶的，而这里只需要相同数值里面 level 最大的即可，
 *    因为每轮遍历实际是从根节点到当前节点的，所以计算当前节点时，stack 里存储的应该是所有的祖先节点，只需要在所有祖先节点里面取最近的即可
 */

class TreeOfCoprimes {
public:
    vector<vector<int>> adj;
    vector<int> res;
    stack<pair<int, int>> stk[55];

    void dfs(int id, int pre, int depth, vector<int>& nums) {
        int level = -1;
        int i = -1;

        for (int x = 1; x <= 50; x ++) {
            if (!stk[x].empty() && stk[x].top().first > level && __gcd(x, nums[id]) == 1) {
                level = stk[x].top().first;
                i = stk[x].top().second;
            }
        }
        res[id] = i;
        cout << "id= " << id << " i= " << i << endl;
        for (auto next : adj[id]) {
            if (next != pre) {
                stk[nums[id]].push({depth, id});
                dfs(next, id, depth + 1, nums);
                stk[nums[id]].pop();
            }
        }
    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        adj.resize(n);

        for (auto & edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        res.resize(n);
        dfs(0, -1, 0, nums);
        return res;
    }

    void test() {
        time_t start = clock();
        vector<int> nums = {5,6,10,2,3,6,15};
        vector<vector<int>> edges = {{0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {2,6}};
        vector<int> result = getCoprimes(nums, edges);
        time_t end = clock();
        for (auto i : result)
            cout << "Result = " << i << endl;
        cout <<  "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};