
#include <bits/stdc++.h>

using namespace std;

bool a[1010][1010];
/* vector<pair<int, pair<int, int>>> v; */
/* vector<pair<int, pair<int, int>>> h; */
vector<pair<int, int>> v[1010];
vector<pair<int, int>> h[1010];
/* int v[1010][1010]; */
/* int h[1010][1010]; */

void solve(int C) {
    memset(a, 0, sizeof a);
    memset(v, 0, sizeof v);
    memset(h, 0, sizeof h);

    int r, c; cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[j][i];
        }
    }
    for (int i = 0; i < r; i++) {
        int lo = -1; int hi = -1;
        for (int j = 0; j < c; j++) {
            if (a[j][i])
                hi = j;
            else {
                if (hi - (lo + 1) >= 1) {
                    /* h[lo + 1][i]++; */
                    /* h[hi][i]++; */
                    h[i].emplace_back(lo + 1, hi);
                    /* h.push_back(make_pair(i, make_pair(lo + 1, hi))); */
                }
                lo = j; hi = j;
            }
        }
        if (hi - (lo + 1) >= 1) {
            /* h[lo + 1][i]++; */
            /* h[hi][i]++; */
            h[i].emplace_back(lo + 1, hi);
            /* h.push_back(make_pair(i, make_pair(lo + 1, hi))); */
        }
    }
    for (int j = 0; j < c; j++) {
        int lo = -1; int hi = -1;
        for (int i = 0; i < r; i++) {
            if (a[j][i])
                hi = i;
            else {
                if (hi - (lo + 1) >= 1) {
                    /* v[j][lo + 1]++; */
                    /* v[j][hi]++; */
                    v[j].emplace_back(lo + 1, hi);
                    /* v.push_back(make_pair(j, make_pair(lo + 1, hi))); */
                }
                lo = i; hi = i;
            }
        }
        if (hi - (lo + 1) >= 1) {
            /* v[j][lo + 1]++; */
            /* v[j][hi]++; */
            v[j].emplace_back(lo + 1, hi);
            /* v.push_back(make_pair(j, make_pair(lo + 1, hi))); */
        }
    }
    int res = 0;
    /* for (int i = 0; i < r; i++) { */
    /*     for (int j = 0; j < c; j++) { */
    /*         res += v[j][i] * h[j][i]; */
    /*     } */
    /* } */
    
    cout << "Case #" << C << ": " << res << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
