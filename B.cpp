// 1を拡張した配るDP
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
const long long MOD = 1000000007;
const long long INF = 1LL << 60;
int main() {
  ll n, k;
  vector<ll> H(1100000), dp(1100000);
  cin >> n >> k;
  rep(i, n) cin >> H[i];
  rep(i, 100010) dp[i] = INF;
  dp[0] = 0;
  rep(i, n) {
    rep(j, k + 1) dp[i + j] = min(dp[i + j], dp[i] + abs(H[i] - H[i + j]));
  }
  cout << dp[n - 1] << endl;
}