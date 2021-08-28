// 配るDP
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

int main() {
  ll n;
  cin >> n;
  vector<ll> H(n), dp(100010);
  rep(i, n) cin >> H[i];
  rep(i, 100010) dp[i] = INF;
  dp[0] = 0;
  rep(i, n) {
    dp[i + 1] = min(dp[i + 1], dp[i] + abs(H[i] - H[i + 1]));
    dp[i + 2] = min(dp[i + 2], dp[i] + abs(H[i] - H[i + 2]));
  }
  cout << dp[n - 1] << endl;
}