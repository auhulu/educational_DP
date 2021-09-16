#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
const long long MOD = 1000000007;
const long long INF = 1LL << 60;
int main() {
  ll n, w;
  cin >> n >> w;
  vector<ll> W(n), V(n);
  rep(i, n) cin >> W[i] >> V[i];
  // dp[ i ][ sum_w ] := i-1 番目までの品物から重さが sum_w
  // を超えないように選んだときの、価値の総和の最大値
  vector<vector<ll>> dp(110, vector<ll>(100100));
  rep(i, n) {
    for (ll sum = 0; sum <= w; sum++) {
      // i番目の品物を選べる場合
      if (sum >= W[i])
        dp[i + 1][sum] = max(dp[i + 1][sum], dp[i][sum - W[i]] + V[i]);
      dp[i + 1][sum] = max(dp[i + 1][sum], dp[i][sum]);
    }
  }
  cout << dp[n][w] << endl;
}