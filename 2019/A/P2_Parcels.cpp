
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int r, c;
int a[300][300];
int d[300][300];

bool possible(int dist) {
    int d1 = -2000000000, d2 = -2000000000, d3 = 2000000000, d4 = 2000000000;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            if (d[i][j] > dist) {
                d1 = max(d1, i + j);
                d2 = max(d2, i - j);
                d3 = min(d3, i + j);
                d4 = min(d4, i - j);
            }
        }
    }
    if (d1 == -2000000000 && d2 == -2000000000 && d3 == 2000000000 && d4 == 2000000000) return true;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            if (max(max(abs(i + j - d1), abs(i + j - d3)), max(abs(i - j - d2),  abs(i - j - d4))) <= dist) return true;
        }
    }
    return false;
}

void sol(int test) {
    cin >> r >> c;
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < r; ++i) {
        string s; cin >> s;
        for (int j = 0; j < c; ++j) {
            a[j][i] = (s[j] == '1');
            if (a[j][i]) q.push(make_pair(0, make_pair(j, i)));
        }
    }
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            d[i][j] = 2000000000;
        }
    }
    while (!q.empty()) {
        pair<int, pair<int, int>> cur = q.front(); q.pop();
        if (cur.s.f < 0 || cur.s.f >= c || cur.s.s < 0 || cur.s.s >= r) continue;
        if (d[cur.s.f][cur.s.s] <= cur.f) continue;
        d[cur.s.f][cur.s.s] = cur.f;
        for (int i = 0; i < 4; ++i) {
            q.push(make_pair(cur.f + 1, make_pair(cur.s.f + dx[i], cur.s.s + dy[i])));
        }
    }
    int ans = r + c;
    for (int i = r + c; i >= 1; i /= 2) {
        while (ans - i >= 0 && possible(ans - i)) ans -= i;
    }
    cout << "Case #" << test << ": " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        sol(i + 1);
    }
    
    return 0;
}
