//メモ化再帰
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
const long long MOD = 1000000007;
const long long INF = 1LL << 60;

ll n;
vector<ll> H(100010), dp(100010);

ll rec(ll i) {
  if (dp[i] != INF) return dp[i];
  if (i == 0) return dp[i] = 0;
  ll res = INF;
  if (i > 0) res = min(res, rec(i - 1) + abs(H[i] - H[i - 1]));
  if (i > 1) res = min(res, rec(i - 2) + abs(H[i] - H[i - 2]));
  return dp[i] = res;
}

int main() {
  cin >> n;
  rep(i, n) cin >> H[i];
  rep(i, 100010) dp[i] = INF;
  cout << rec(n - 1) << endl;
}