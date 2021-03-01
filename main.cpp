#include <iostream>
#include <cmath>
#include <ctime>
//#include "Hdony-LC/Set_Map/LeetCode-387-First-Unique-Character-in-a-String/LC-387-Basic-Solu.h"
//#include "Hdony-LC/DP/JZOffer-1-Fibonacci-Sequence/JZ-1-Basic-Solu.h"
//#include "Hdony-LC/DP/LeetCode-70-Climbing-Stairs/LC-70-Basic-Solu.h"
//#include "Hdony-LC/DP/LeetCode-70-Climbing-Stairs/LC-70-Basic-Solu.h"
//#include "Hdony-LC/DP/LeetCode-120-Triangle/LC-120-Basic-Solu.h"
//#include "Hdony-LC/DP/LeetCode-64-Minimum-Path-Sum/LC-64-Basic-Solu.h"
//#include "Hdony-LC/DP/LeetCode-343-Integer-Break/LC-343-Basic-Solu.h"
//#include "Hdony-LC/DP/LeetCode-343-Integer-Break/LC-343-Basic-Solu.h"
//#include "Hdony-LC/Knapsack/Knapsack01/Basic-Solu.h"
//#include "Hdony-LC/Knapsack/Knapsack01/Space-Compression.h"
//#include "Hdony-LC/Knapsack/Knapsack01/Advanced-Solu.h"
//#include "Hdony-LC/Knapsack/Knapsack01/LC-279-DP-Solu.h"

//#include "Hdony-LC/SolutionInOrder/LeetCode-1771-Maximize-Palindrome-Length-From-Subsequences/LC-1771-DP.h"
//#include "Hdony-LC/SolutionInOrder/LeetCode-1770-Maximum-Score-from-Performing-Multiplication-Operations/LC-1770-DP.h"
//#include "Hdony-LC/SolutionInOrder/LeetCode-1769-Minimum-Number-of-Operations-to-Move-All-Balls-to-Each-Box/LC-1769-DP.h"
#include "Hdony-LC/SolutionInOrder/LeetCode-1768-Merge-Strings-Alternately/LC-1768.h"


using namespace std;

//class Solution {
//public:
//    int numberOf2sInRange(int n) {
//        int cur2Times = 0;
//        for (int i = 0; i <= n; i ++) {
//            int curNum = i;
//            while(curNum > 0) {
//                int endNum = curNum % 10;
//                if (endNum == 2) {
//                    cur2Times ++;
//                    cout << cur2Times << " " << i << endl;
//                }
//                curNum = (curNum - endNum) / 10;
//            }
//        }
//        return cur2Times;
//    }
//};

int main() {

//    Solution solution;
//    std::cout << solution.numberOf2sInRange(22);

    MergeStringsAlternately minimumNumberOfOperationsToMoveAllBallsToEachBox;

    minimumNumberOfOperationsToMoveAllBallsToEachBox.test();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
