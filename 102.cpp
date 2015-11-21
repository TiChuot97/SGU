#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long

int n, res;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin >> n;
    foru(i, 1, n)
        if (gcd(i, n) == 1) ++res;
    cout << res << " ";
}
