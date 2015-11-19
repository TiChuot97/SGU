#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>

using namespace std;

const int maxN = 100010;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)

int n, numVertex, edge[10][10], a[maxN], b[maxN], euler[maxN], deg[10];
bool avail[maxN], done[10];

void findEuler() {
    stack<int> s;
    foru(i, 0, 7)
        if (deg[i] != 0) {
            s.push(i);
            break;
        }
    while (!s.empty()) {
        int u = s.top();
        bool check = false;
        foru(v, 0, 7)
            if (edge[u][v] != 0) {
                --edge[u][v];
                --edge[v][u];
                s.push(v);
                check = true;
                break;
            }
        if (!check) {
            euler[numVertex++] = u;
            done[u] = true;
            s.pop();
        }
    }
}

void print(int u, int v) {
    foru(i, 1, n)
        if (avail[i]) 
            if (a[i] == u && b[i] == v) {
                cout << i << " +" << endl;
                avail[i] = false;
                return;
            }
            else
                if (a[i] == v && b[i] == u) {
                    cout << i << " -" << endl;
                    avail[i] = false;
                    return;
                }
}

bool checkEuler() {
    int countOdd = 0;
    foru(i, 0, 6)
        if (deg[i] % 2) ++countOdd;
    return (countOdd <= 2);
}

int main() {
    cin >> n;
    foru(i, 1, n) {
        cin >> a[i] >> b[i];
        edge[a[i]][b[i]]++;
        edge[b[i]][a[i]]++;
        deg[a[i]]++;
        deg[b[i]]++;
        avail[i] = true;
    }
    if (!checkEuler()) puts("No solution");
    else {
        int u = 0, v = 0;
        foru(i, 0, 6)
            if (deg[i] % 2) 
                if (u == 0) u = i;
                else v = i;
        if (u != 0) {
            edge[u][7]++; edge[v][7]++;
            edge[7][u]++; edge[7][v]++;
            deg[7] += 2; deg[u]++; deg[v]++;
        }
        findEuler();
        bool check = true;
        repu(i, 8)
            if (deg[i] != 0 && done[i] == false) check = false;
        if (check) {
            int pos = 0;
            repu(i, numVertex) 
                if (euler[i] == 7) pos = i;
            foru(i, pos, numVertex - 2) 
                if (euler[i] != 7)
                    print(euler[i], euler[(i + 1) % numVertex]);
            foru(i, 0, pos - 1)
                if (euler[i + 1] != 7) 
                    print(euler[i], euler[i + 1]);
        }
        else puts("No solution");
    }
}
