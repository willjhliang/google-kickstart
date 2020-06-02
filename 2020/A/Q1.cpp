
#include <bits/stdc++.h>

using namespace std;

int a[100000];

void sol(int test) {
    int n, b; cin >> n >> b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        b -= a[i];
        if (b < 0) {
            cout << "Case #" << test << ": " << i << endl;
            return;
        }
    }
    cout << "Case #" << test <<": " << n << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        sol(i + 1);
    }
    
    return 0;
}
