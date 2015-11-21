#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int maxN = 100, INF = 1e9;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long

int n, m, c[maxN + 1][maxN + 1], res, f[maxN + 1][maxN + 1];
bool check[maxN + 1][maxN + 1];
vector<int> ans;

int dp(int i, int j) {
    if (j > m) return 0;
    if (i > n) return -INF;
    if (check[i][j]) return f[i][j];
    check[i][j] = true;
    f[i][j] = 0;
    int temp = dp(i + 1, j + 1);
    if (temp != -INF) temp += c[j][i];
    temp = max(temp, dp(i + 1, j));
    f[i][j] = temp;
    return f[i][j];
}

void trace(int i, int j) {
    if (j > m) return;
    if (i > n) return;
    int temp = dp(i + 1, j + 1);
    if (temp != -INF) temp += c[j][i];
    if (temp == res) {
        ans.push_back(i);
        res -= c[j][i];
        trace(i + 1, j + 1);
        return;
    }
    trace(i + 1, j);
}

int main() {
    cin >> m >> n;
    foru(i, 1, m)
        foru(j, 1, n) cin >> c[i][j];
    res = dp(1, 1);
    cout << res << endl;
    trace(1, 1);
    repu(i, ans.size()) cout << ans[i] << " ";
}
