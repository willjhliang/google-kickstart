
#include <bits/stdc++.h>

using namespace std;

int a[100010];
int d[100010];

int n, k;
bool func(int len) {
    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
        res += ceil(1.0 * d[i] / len) - 1;
    }
    return res <= k;
}

void sol(int test) {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
        d[i] = a[i + 1] - a[i];
        res = max(res, d[i]);
    }
    int k = res;
    for (int i = k; i >= 1; i /= 2) {
        while (res - i > 0 && func(res - i)) {
            res -= i;
        }
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
