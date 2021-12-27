
#include <bits/stdc++.h>

using namespace std;

void solve(int C) {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int score = 0;
    for (int i = 0; i < (n / 2); i++) {
        if (s[i] != s[n - i - 1])
            score++;
    }

    cout << "Case #" << C << ": " << abs(k - score) << endl;
}

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
