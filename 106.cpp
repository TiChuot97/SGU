#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long

int a, b, c, x_1, x_2, y_1, y_2, res;

int main() {
    cin >> a >> b >> c >> x_1 >> x_2 >> y_1 >> y_2;
    foru(i, x_1, x_2) {
        ll temp = i; 
        temp *= a;
        temp += c;
        if (temp % (-b) == 0 && temp / (-b) >= y_1 && temp / (-b) <= y_2) ++res;
    }
    cout << res;
}
