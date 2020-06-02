
#include <bits/stdc++.h>

using namespace std;

int a[100010];

namespace segTree {
    int segTree[1 << 20];
    int n;

    void update(int i, int val, int node = 1, int a = 0, int b = -1) {
        if (b == -1) b = n - 1;
        if (i < a || i > b) return;
        if (a == b && a == i) {
            segTree[node] += i;
            return;
        }
        update(i, val, node * 2, a, (a + b) / 2);
        update(i, val, node * 2 + 1, (a + b) / 2 + 1, b);
        segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
    }
    int query(int i, int j, int node = 1, int a = 0, int b = -1) {
        if (b == -1) b = n - 1;
        if (a > b || a > j || b < i) return 0;
        if (a >= i && b <= j) return segTree[node];
        int one = query(i, j, node * 2, a, (a + b) / 2);
        int two = query(i, j, node * 2 + 1, (a + b) / 2 + 1, b);
        return func(one, two);
    }
};

void sol(int test) {
    int n, s; cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        sol(i + 1);
    }
    
    return 0;
}
