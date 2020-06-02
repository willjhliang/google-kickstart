
#include <bits/stdc++.h>

using namespace std;

int ps[100010][26];

void sol(int test) {
    memset(ps, 0, sizeof ps);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            ps[i + 1][j] = ps[i][j];
        }
        ps[i + 1][s[i] - 65]++;
    }
    int res = 0;
    for (int i = 0; i < q; ++i) {
        int a, b; cin >> a >> b;
        int odd = 0;
        for (int j = 0; j < 26; ++j) {
            if ((ps[b][j] - ps[a - 1][j]) % 2 == 1) odd++;
        }
        if (odd <= 1) res++;
    }
    cout << "Case #" << test << ": " << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        sol(i + 1);
    }
    
    return 0;
}
