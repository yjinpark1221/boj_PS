#include <iostream>
int n;
int cnt[2];
int pap[128][128];
void divide(int x, int y, int len) {
	int br = 0; int k = pap[x][y];
	if (len == 1) {
		++cnt[k];
		return;
	}
	for (int i = x; i < x + len; ++i) {
		for (int j = y; j < y + len; ++j) {
			if (pap[i][j] != k) {
				br = 1; break;
			}
			if (i == x + len - 1 && j == y + len - 1) {
				++cnt[k];
				return;
			}
		}
		if (br) break;
	}
	int nextLen = len / 2;
	divide(x, y, nextLen);
	divide(x, y + nextLen, nextLen);
	divide(x + nextLen, y, nextLen);
	divide(x + nextLen, y + nextLen, nextLen);
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> pap[i][j];
		}
	}
	divide(0, 0, n);
	std::cout << cnt[0] << '\n' << cnt[1] << '\n';
	return 0;
}