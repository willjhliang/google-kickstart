
#include <bits/stdc++.h>

using namespace std;

int a[100010];

void sol(int c) {
    int n, p; cin >> n >> p;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 2000000000, sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (i < (p - 1)) continue;
        if (i > (p - 1)) sum -= a[i - p];
        ans = min(ans, p * a[i] - sum);
    }
    cout << "Case #" << c << ": " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        sol(i + 1);
    }
    
    return 0;
}
