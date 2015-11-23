#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int maxN = 5, BASE_1 = 1e9 + 7, BASE_2 = 1e9 + 3;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long
#define F first
#define S second

map<vector<string>, int> setString;
string s[maxN + 1];
int n, m, res;

int main() {
    scanf("%d\n", &n);
    repu(i, n) {
        cin >> m;
        repu(j, m) cin >> s[j];
        sort(s, s + m);
        foru(j, 1, (1 << m) - 1) { 
            vector<string> temp;
            repu(t, m) 
                if ((j >> t) & 1)
                    temp.push_back(s[t]);
            setString[temp]++;
        }
        getline(cin, s[0]);
    }
    scanf("%d\n", &n);
    repu(i, n) {
        cin >> m;
        vector<string> temp;
        repu(j, m) cin >> s[j];
        sort(s, s + m);
        repu(j, m) temp.push_back(s[j]);
        res = setString[temp];
        printf("%d\n", res);
    }
}
