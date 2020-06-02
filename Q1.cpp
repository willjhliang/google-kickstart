#include <bits/stdc++.h>

using namespace std;

int a[110];
void solve(int test) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) ans++;
    }
    cout << "Case #" << test << ": " << ans << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
