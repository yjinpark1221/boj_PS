#include <iostream>
#include <algorithm>
int dp[100001][101];
int wv[100][2];
int maxValue(int weight, int obj) {
	if (dp[weight][obj] >= 0) return dp[weight][obj];
	int val = wv[obj][1];
	int wei = wv[obj][0];
	if (weight >= wei) {
		int ret = std::max(maxValue(weight, obj - 1), maxValue(weight - wei, obj - 1) + val);
		return dp[weight][obj] = ret;
	}
	return dp[weight][obj] = maxValue(weight, obj - 1);
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);
	int N, K;
	std::cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		std::cin >> wv[i][0] >> wv[i][1];
	}
	for (int i = 1; i <= K; ++i) {
		for (int j = 1; j < N; ++j) {
			dp[i][j] = -1;
		}
	}
	for (int i = wv[0][0]; i <= K; ++i) {
		dp[i][0] = wv[0][1];
	}
	std::cout << maxValue(K, N - 1) << "\n";
	return 0;
}