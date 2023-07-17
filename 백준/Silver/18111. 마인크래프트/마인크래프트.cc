#include <iostream>
int main() {
	int n, m, b, ans_t = 987654321, max_h = 0, ans_h;
	std::cin >> n >> m >> b;
	int height[500][500];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> height[i][j];
			if (max_h < height[i][j]) max_h = height[i][j];
		}
	}
	for (int h = 0; h <= max_h; ++h) {
		int t = 0;
		int b_now = b;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (height[i][j] > h) {
					b_now += height[i][j] - h;
					t += 2 * (height[i][j] - h);
				}
				else {
					b_now -= h - height[i][j];
					t += h - height[i][j];
				}
			}
		}
		if (ans_t >= t && b_now >= 0) {
			ans_t = t;
			ans_h = h;
		}
	}
	std::cout << ans_t << " " << ans_h << "\n";
	return 0;
}