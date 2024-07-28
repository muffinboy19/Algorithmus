#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define endl '\n'
const int lim = 2e5;
const ll mod = 1e9 + 7;

void do_test() {
    int n;
    cin >> n;
    vector<int> b(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> b[i];
    }

    vector<int> a(n);
    a[0] = b[0]; // Start with the first element of a
    bool possible = true;

    for (int i = 1; i < n-1; i++) {
        a[i] = b[i-1] | b[i]; // a[i] should be the OR of b[i-1] and b[i]
        if ((a[i] & b[i-1]) != b[i-1]) {
            possible = false;
            break;
        }
    }
    a[n-1] = b[n-2]; // End with the last element of a

    if (possible) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        do_test();
    }

    return 0;
}
