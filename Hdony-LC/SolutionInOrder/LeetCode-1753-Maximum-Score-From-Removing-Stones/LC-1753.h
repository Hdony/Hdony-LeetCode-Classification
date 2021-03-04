// Created by wuyou on 2021/3/4.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * 你正在玩一个单人游戏，面前放置着大小分别为 a​​​​​​、b 和 c​​​​​​ 的 三堆 石子。
 * 每回合你都要从两个 不同的非空堆 中取出一颗石子，并在得分上加 1 分。当存在 两个或更多 的空堆时，游戏停止。
 * 给你三个整数 a 、b 和 c ，返回可以得到的 最大分数 。
 */

// Greedy + Priority Queue
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
class Solution {
public:
    int maximumScore_(int a, int b, int c) {

        priority_queue<int> pq;
        pq.push(a), pq.push(b), pq.push(c);
        int res = 0;
        while (true) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if (y == 0) break;

            int z = pq.top();
            if (z == 0) {
                res += min(x, y);
                break;
            }

            int t = y - (z - 1);
            res += t;
            pq.push(x - t), pq.push(y - t);
        }
        return res;
    }

    int maximumScore(int a, int b, int c) {

        priority_queue<int> pq;
        pq.push(a), pq.push(b), pq.push(c);
        int res = 0;
        while (true){
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if (y == 0) break;
            res += 1;
            pq.push(x - 1), pq.push(y - 1);
        }
        return res;
    }
};
