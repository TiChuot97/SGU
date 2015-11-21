#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long

int n;

int main() {
    cin >> n;
    cout << (n / 3) * 2;
}
