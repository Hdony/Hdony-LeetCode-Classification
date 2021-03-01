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
 * 2. 准备 50 个栈，以每个节点的 val 为基准，栈内存储的数据为当前数据值对应的层数 deep 及节点序号 i 。
 * 3. 遍历到某个节点时，以当前节点为基准，满足 gcd == 1 且层数最深的为最优解，也就是最近的公共祖先节点
 * 4. 满足 gcd 条件可能存在多个节点的数据值，遍历可能的数据值里面，离节点i最近的，通过 level 来识别；这里需要识别数值和 level 两重条件
 * 5. 为啥取栈顶的元素呢，因为我们压栈的时候，level 最大的总是在栈顶的，而这里只需要相同数值里面 level 最大的即可，
 *    因为每轮遍历实际是从根节点到当前节点的，所以计算当前节点时，stack 里存储的应该是所有的祖先节点，只需要在所有祖先节点里面取最近的即可
 */

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> res;
    stack<pair<int, int>> stk[55];

    void dfs(int node, int pre, int depth, vector<int>& nums) {
        int level = -1;
        int i = -1;
        for (int x = 1; x <= 50; x++) {
            if (!stk[x].empty() && stk[x].top().first > level && __gcd(x, nums[node]) == 1) {
                level = stk[x].top().first;
                i = stk[x].top().second;
            }
        }
        res[node] = i;
        for (auto next : adj[node]) {
            if (next != pre) {
                stk[nums[node]].push({depth, node});
                dfs(next, node, depth+1, nums);
                stk[nums[node]].pop();
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
};



struct Node {
    int deep, index;
    Node(int deeps, int indexs) : deep(deeps), index(indexs) {}
};

class TreeOfCoprimes {
public:
    stack<Node> st[100];
    int n;
    vector<vector<int>> u;

    void dfs(int root, int fa, vector<int> &nums, int deep, vector<int> &ret) {
        int ans = -1;
        int bestdeep = 0;
        for (int i = 0; i < 100; i++) {
            if ((__gcd(i, nums[root]) == 1) && !st[i].empty()) {
                Node now = st[i].top();
                if (ans == -1 || bestdeep < now.deep) {
                    ans = now.index;
                    bestdeep = now.deep;
                }
            }
        }
        ret[root] = ans;

        st[nums[root]].push(Node(deep, root));

        for (int i = 0; i < u[root].size(); i++) {
            int son = u[root][i];
            if (son == fa)
                continue;

            dfs(son, root, nums, deep + 1, ret);
        }

        st[nums[root]].pop();
    }

    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges) {
        vector<int> ret;
        for (auto & i : st)
            while (!i.empty())
                i.pop();
        u.clear();
        ret.clear();

        n = nums.size();
        ret.resize(n);
        u.resize(n);

        for (int i = 0; i < n - 1; i++)
        {
            u[edges[i][0]].push_back(edges[i][1]);
            u[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(0, -1, nums, 0, ret);
        return ret;
    }


    void test() {
        time_t start = clock();
        vector<int> nums = {};
        vector<int> res = getCoprimes("abcd", "123456");
        time_t end = clock();
        for (auto i : res)
            cout << "Result = " << i << endl;
        cout <<  "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};