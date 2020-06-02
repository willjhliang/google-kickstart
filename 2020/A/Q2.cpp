
#include <bits/stdc++.h>

using namespace std;

int a[100][100];
int ps[100][100];
int dp[200];

void sol(int test) {
    int n, k, p; cin >> n >> k >> p;
    memset(ps, 0, sizeof ps);
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; ++i) {
         for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
         }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            ps[i][j + 1] = ps[i][j] + a[i][j];
        }
    }
    for (int i = 0; i <= p; ++i) {
        dp[i] = -2000000000;
    }
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int l = p; l >= 0; --l) {
            if (dp[l] == -2000000000) continue;
            for (int j = 0; j <= k; ++j) {
                if (l + j > p) continue;
                dp[l + j] = max(dp[l + j], dp[l] + ps[i][j]);
            }
        }
        // cout << i << endl;
        // for (int l = 0; l <= p; ++l) {
        //     cout << dp[l] << " ";
        // }
        // cout << endl;
    }
    cout << "Case #" << test << ": " << dp[p] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        sol(i + 1);
    }
    
    return 0;
}
