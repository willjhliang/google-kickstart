#include <bits/stdc++.h>

using namespace std;

void solve(long long test) {
    long long mod = 1000000000;
    long long maxVal = 1000000000;
    string st; cin >> st;
    long long x = 0, y = 0;
    pair<long long, long long> mult = make_pair(0, 1);
    vector<long long> v;
    for (long long i = 0; i < st.length(); i++) {
        if (st[i] == 'N') y = (y - mult.second % mod + mod) % mod;
        if (st[i] == 'S') y = (y + mult.second % mod) % mod;
        if (st[i] == 'E') x = (x + mult.second % mod) % mod;
        if (st[i] == 'W') x = (x - mult.second % mod + mod) % mod;
        if (isdigit(st[i])) {
            int num = int(st[i]) - '0';
            v.push_back(num);
            if (maxVal / (int(st[i]) - '0') <= mult.second) {
                /* cout << i << endl; */
                long long prod = mult.second * num;
                /* cout << prod << endl; */
                mult.first *= num;
                mult.first += prod / maxVal;
                mult.second = prod % maxVal;
                /* cout << "*"; */
                /* cout << i << " " << mult.first << " " << mult.second << endl; */
            } else {
                mult.second *= num;
            }
            /* cout << mult.first << " " << mult.second << endl; */
        }
        if (st[i] == ')') {
            int num = v[v.size() - 1];
            long long left = mult.first % num;
            mult.first /= num;
            long long res = left * maxVal / num + mult.second / num; 
            /* cout << res << endl; */
            mult.first += res / maxVal;
            mult.second = res % maxVal;
            v.pop_back();
            /* cout << "/" << mult.first << " " << mult.second << endl; */
        }
    }
    
    cout << "Case #" << test << ": " << (x + 1) << " " << (y + 1) << endl;
}

int main() {
    long long t; cin >> t;
    for (long long i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
