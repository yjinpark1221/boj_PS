#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <ctime>
#include <list>
#include <numeric> 
#include <deque>
#include <functional>
#include <limits.h>
#include <tuple>

#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FORV(iter, v) for (auto iter = v.begin(); iter != v.end(); ++iter)
#define SWAP(a, b) {auto tmp = a;a = b;b = tmp;}
#define x first
#define y second
#define MAX 2147483647
#define MIN -2147483648
#define MOD 1000000007

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef std::vector<int> vi;
typedef std::vector<ll> vl;
typedef std::pair<int, pii> piii;
typedef std::pair<pii, pii> piiii;
typedef std::vector<char> vc;

typedef std::pair<ll, ll> point;
typedef std::pair<ll, ll> vec;

template<typename T>
using priority_stack = std::priority_queue<T, std::vector<T>, std::greater<T>>;

int a[2][10005];
int comb[3][10005];
int dp[10005][4][4];
int n, w;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool inMap(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

int right(int i) {
    return (i + 1) % n;
}

int updown(int i) {
    return (i + 1) % 2;
}

void combine() {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {  // link0, link1, updown
        comb[0][i] = comb[1][i] = comb[2][i] = 0;
        if (a[0][right(i)] + a[0][i] <= w) comb[0][i] = 1;
        if (a[1][right(i)] + a[1][i] <= w) comb[1][i] = 1;
        if (a[0][i] + a[1][i] <= w) comb[2][i] = 1;
    }
}

int solve(int i, int stype, int etype) {
    if (dp[i][stype][etype]) return dp[i][stype][etype];
    int res = 987654321;
    if (i == n) {
        if (stype == etype) return dp[i][stype][etype] = 0;
        else return dp[i][stype][etype] = 987654321;
    }
    if (i == n - 1) {
        if (etype == 0) {
            if (stype == 0) {
                if (comb[2][i] == 0) res = 2;
                else res = 1;
            }
            else res = 1;
        }
        else if (etype == 1) {
            if (stype == 0) {
                if (comb[1][i] || comb[2][i]) res = 2;
                else res = 3;
            }
            else if (stype == 1) {
                res = 2;
            }
            else {
                if (comb[1][i]) res = 1;
                else res = 2;
            }
        }
        else {
            if (stype == 0) {
                if (comb[0][i] || comb[2][i]) res = 2;
                else res = 3;
            }
            else if (stype == 1) {
                if (comb[0][i]) res = 1;
                else res = 2;
            }
            else {
                res = 2;
            }
        }
        return dp[i][stype][etype] = res;
    }
    if (stype == 0) {
        int r0 = comb[0][i];
        int r1 = comb[1][i];
        int ud = comb[2][i];
        res = std::min(res, 2 + solve(i + 1, 0, etype));
        if (ud) {
            res = std::min(res, 1 + solve(i + 1, 0, etype));
        }
        if (r0 && r1) {
            res = std::min(res, 2 + solve(i + 2, 0, etype));
        }
        if (r0) {
            res = std::min(res, 2 + solve(i + 1, 2, etype));
        }
        if (r1) {
            res = std::min(res, 2 + solve(i + 1, 1, etype));
        }
    }
    else if (stype == 1) {
        int r0 = comb[0][i];
        res = std::min(res, 1 + solve(i + 1, 0, etype));
        if (r0) {
            res = std::min(res, 1 + solve(i + 1, 2, etype));
        }
    }
    else if (stype == 2) {
        int r1 = comb[1][i];
        res = std::min(res, 1 + solve(i + 1, 0, etype));
        if (r1) {
            res = std::min(res, 1 + solve(i + 1, 1, etype));
        }
    }
    return dp[i][stype][etype] = res;
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    for (std::cin >> t; t--;) {
        std::cin >> n >> w;
        FOR(i, 2) {
            FOR(j, n) {
                std::cin >> a[i][j];
            }
        }
        combine();
        int ans = solve(0, 0, 0);
        ans = std::min(ans, solve(0, 1, 1));
        ans = std::min(ans, solve(0, 2, 2));

        if (comb[0][n - 1] == 1 && comb[1][n - 1] == 1) {
            n = n - 1;
            memset(dp, 0, sizeof(dp));
            ans = std::min(ans, solve(1, 0, 0) + 2);
        } 
        std::cout << ans << "\n";
    }

    return 0;
}
