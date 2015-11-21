#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

const int maxN = 300, INF = 1e9;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long
#define F first
#define S second

typedef pair<int, int> edge;

struct node {
    int vertex;
    int time;
    node(int v, int t) {
        vertex = v;
        time = t;
    }
};

struct compareHeap {
    bool operator () (node i, node j) {
        return (j.time < i.time);
    }
};

int n, m, d[maxN + 1], remain[maxN + 1], duration[maxN + 1][2], init[maxN + 1], start, target, pre[maxN + 1];
priority_queue<node, vector<node>, compareHeap> heap;
vector<edge> adj[maxN + 1];
bool done[maxN + 1];
vector<int> ans;

int getLight(int u, int currTime) {
    if (currTime < remain[u]) return init[u];
    else {
        int temp = (currTime - remain[u]) % (duration[u][0] + duration[u][1]);
        if (temp < duration[u][1 - init[u]]) return 1 - init[u];
        else return init[u];
    }
}

int getNext(int u, int currTime) {
    if (currTime < remain[u]) return remain[u] - currTime;
    else {
        int temp = (currTime - remain[u]) % (duration[u][0] + duration[u][1]);
        return (temp < duration[u][1 - init[u]]) ? duration[u][1 - init[u]] - temp : (duration[u][0] + duration[u][1]) - temp;
    }
}

int getTime(int u, int v, int currTime, int count) {
    if (getLight(u, currTime) == getLight(v, currTime)) return 0;
    if (count > 5) return INF;
    int nextU = getNext(u, currTime);
    int nextV = getNext(v, currTime);
    return getTime(u, v, currTime + min(nextU, nextV), count + 1) + min(nextU, nextV);
}

void dijkstra() {
    foru(i, 1, n) d[i] = INF;
    d[start] = 0; heap.push(node(1, 0));
    while (!heap.empty()) {
        node u = heap.top(); heap.pop();
        while (!heap.empty() && done[u.vertex]) {
            u = heap.top();
            heap.pop();
        }
        if (done[u.vertex]) return;
        done[u.vertex] = true;
        repu(i, adj[u.vertex].size()) {
            int v = adj[u.vertex][i].F;
            int w = adj[u.vertex][i].S;
            if (d[v] > d[u.vertex] + w + getTime(u.vertex, v, d[u.vertex], 0)) {
                d[v] = d[u.vertex] + w + getTime(u.vertex, v, d[u.vertex], 0);
                heap.push(node(v, d[v]));
                pre[v] = u.vertex;
            }
        }
    }
}

int main() {
    scanf("%d %d\n", &start, &target);
    scanf("%d %d\n", &n, &m);
    foru(i, 1, n) {
        char c;
        scanf("%c %d %d %d\n", &c, &remain[i], &duration[i][0], &duration[i][1]);
        init[i] = (c == 'B') ? 0 : 1;
    }
    foru(i, 1, m) {
        int u, v, w;
        scanf("%d %d %d\n", &u, &v, &w);
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    dijkstra();
    if (d[target] == INF) cout << 0;
    else {
        cout << d[target] << endl;
        while (target != 0) {
            ans.push_back(target);
            target = pre[target];
        }
        ford(i, ans.size() - 1, 1) cout << ans[i] << " ";
        cout << ans[0];
    }
}
