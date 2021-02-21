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
#include "Hdony-LC/DP/LeetCode-343-Integer-Break/LC-343-Basic-Solu.h"
//#include "Hdony-LC/Knapsack/Knapsack01/Basic-Solu.h"
//#include "Hdony-LC/Knapsack/Knapsack01/Space-Compression.h"
//#include "Hdony-LC/Knapsack/Knapsack01/Advanced-Solu.h"
//#include "Hdony-LC/Knapsack/Knapsack01/LC-279-DP-Solu.h"

using namespace std;

void sumArraysOnHost(float *A, float *B, float *C, const int N) {
    for (int idx = 0; idx < N; idx ++)
        C[idx] = A[idx] + B[idx];
}

void initialData(float *ip, int size) {
    time_t t;
    srand((unsigned int) time(&t));
    for (int i = 0; i < size; i ++)
        ip[i] = (float)(rand() & 0xFF)/10.0f;
}

int main() {

    int nElem = 1024;
    size_t nBytes = nElem * sizeof(float);
    float *h_A, *h_B, *h_C;
    h_A = (float *)malloc(nBytes);
    h_B = (float *)malloc(nBytes);
    h_C = (float *)malloc(nBytes);

    initialData(h_A, nElem);
    initialData(h_B, nElem);

    sumArraysOnHost(h_A, h_B, h_C, nElem);

    free(h_A);
    free(h_B);
    free(h_C);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
