// バグるなぜ？
// n+3を100010にするとサンプルは通るが一部WA
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
const long long MOD = 1000000007;
const long long INF = 1LL << 60;
int main() {
  ll n;
  cin >> n;
  ll a[n + 3][3];
  ll dp[n + 3][3];
  rep(i, n) { rep(j, 3) cin >> a[i][j]; }
  rep(i, 3) dp[0][i] = a[0][i];
  rep(i, n) {
    rep(j, 3) {
      rep(k, 3) {
        if (j == k) continue;
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][k] + a[i + 1][j]);
      }
    }
  }

  ll ans = 0;
  rep(i, 3) ans = max(ans, dp[n - 1][i]);
  cout << ans << endl;
}