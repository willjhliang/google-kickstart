#include <bits/stdc++.h>

using namespace std;

long long n, d; 
long long a[1010];

bool func(long long t) {
    for (long long i = 0; i < n; i++) {
        if (t % a[i] == 0) continue;
        t = (t - t % a[i] + a[i]);
    }
    return t <= d;
}

void solve(long long test) {
    cin >> n >> d;
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long p = 1;
    for (long long i = d; i >= 1; i /= 2) {
        while (p + i <= d && func(p + i)) p += i;
    }
    cout << "Case #" << test << ": " << p << endl;
}

int main() {
    long long t; cin >> t;
    for (long long i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
