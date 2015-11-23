#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxN = 200000;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long

int weight[maxN + 1], cost[maxN + 1], resNumLeft, resNumRight, resSum, n, m, k, sumWeight[maxN + 1], sumCost[maxN + 1];

int main() {
    cin >> n >> m >> k;
    int weightH = 0, weightT = 0, r = n;
    int sum = 0, resSum = 0;
    foru(i, 1, n) scanf("%d %d", &weight[i], &cost[i]);
    foru(i, 1, n - m) weightT += weight[i];
    foru(i, n - m + 1, n) weightH += weight[i];
    foru(i, 1, n) {
        sumWeight[i] = sumWeight[i - 1] + weight[i];
        sumCost[i] = sumCost[i - 1] + cost[i];
    }
    while (weightT * k >= weightH) {
        int tempL = 1, tempR = r - m, tempCost = 0, numLeft = 0;
        while (tempL <= tempR) {
            int tempMid = (tempL + tempR) >> 1;
            if ((weightT - sumWeight[tempMid]) * k >= weightH) tempCost = sumCost[tempMid], tempL = tempMid + 1, numLeft = tempMid;
            else tempR = tempMid - 1;
        }
        if (sum + tempCost > resSum) {
            resSum = sum + tempCost;
            resNumLeft = numLeft;
            resNumRight = n - r;
        }
        weightT -= weight[r - m];
        weightH += weight[r - m];
        weightH -= weight[r];
        sum += cost[r--];
    }
    printf("%d %d\n", resNumLeft + resNumRight, resSum);
    foru(i, 1, resNumRight) printf("H");
    foru(i, 1, resNumLeft) printf("T");
}
