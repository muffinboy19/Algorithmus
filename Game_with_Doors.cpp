#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
#define i(n)         \
    long long int n; \
    cin >> n;
#define ii(a, b)        \
    long long int a, b; \
    cin >> a >> b
#define iii(a, b, c)       \
    long long int a, b, c; \
    cin >> a >> b >> c
#define pb push_back
#define p(v)               \
    for (auto it : v)      \
        cout << it << " "; \
    cout << e;
#define fi first
#define se second
#define ia(a, n)                \
    long long int n;            \
    cin >> n;                   \
    long long int a[n];         \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> a[i];            \
    }
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define de cout << "*****" << endl;
#define pob pop_back
#define sz(x) (x.size())
#define all(x) (x).begin(), (x).end()
#define co(x) cout << x << endl;
#define cot(x) cout << x << " ";
#define fff(i, a, b) for (int i = a; i < b; i++)
#define fo(n) for (int i = 0; i < n; i++)
#define test(t) \
    int t;      \
    cin >> t;   \
    while (t--)
#define e "\n"
#define ce cout << "\n"
#define da(a, n)                \
    long long int a[n];         \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> a[i];            \
    }
#define re return
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pr pair<int, int>
#define input(a)       \
    for (auto &it : a) \
        cin >> it;
#define matrix(n, m)                \
    ll n, m;                        \
    cin >> n >> m;                  \
    ll mat[n][m];                   \
    for (int i = 0; i < n; i++)     \
    {                               \
        for (int j = 0; j < m; j++) \
        {                           \
            cin >> mat[i][j];       \
        }                           \
    }
#define u 1000000007

// Gaurav_Chhetri
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c > b || a > d)
    {
        cout << 1 << endl;
        return;
    }
    if (c < a)
    {
        swap(a, c);
        swap(b, d);
    }
    int ans = 0;
    map<int, int> m;
    for (int i = a; i <= b; i++)
    {
        m[i]++;
    }
    for (int i = c; i <= d; i++)
    {
        m[i]++;
    }
    int l = 1;
    int r = 1;
    for (int i = 1; i <= 100; i++)
    {
        if (m[i] == 2)
        {
            ans++;
            if (l == -1)
            {
                l = i;
            }
            r = i;
        }
    }
    ans--;
    if (min({a, b, c, d}) < l)
    {
        ans++;
    }
    if (max({a, b, c, d}) > r)
    {
        ans++;
    }
    cout << ans << endl;
}
int main()
{
    fast
    test(t)
    {
        solve();
        cout.flush();
    }
    return 0;
}