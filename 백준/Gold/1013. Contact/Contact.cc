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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int check(std::vector<pii>& v, int idx) {
    if (idx > v.size()) return false;
    if (idx == v.size()) return true;
    if (v[idx].first == 1) {
        if (v[idx].second > 1) return false;
        if (idx > v.size() - 3) return false;
        if (v[idx + 1].second < 2) return false;
        bool res = check(v, idx + 3);
        if (v[idx + 2].second > 1) {
            v[idx + 2].second = 1;
            res |= check(v, idx + 2);
        }
        return res;
    }
    if (v[idx].first == 0) {
        if (v[idx].second != 1) {
            return false;
        }
        if (idx > v.size() - 2) return false;
        if (v[idx + 1].second == 1) {
            return check(v, idx + 2);
        }
        else {
            v[idx + 1].second--;
            return check(v, idx + 1);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    for (std::cin >> t; t--;) {
        std::string str;
        std::vector<pii> v;
        std::cin >> str;
        int strlen = str.size();

        int cnt0 = 0, cnt1 = 0;
        int ans = -1;
        for (int i = 0; i < strlen; ++i) {
            if (str[i] == '0') {
                if (cnt1) {
                    v.push_back({1, cnt1});
                    cnt1 = 0;
                }
                ++cnt0;
            }
            else if (str[i] == '1') {
                if (cnt0) {
                    v.push_back({0, cnt0});
                    cnt0 = 0;
                }
                ++cnt1;
            }
        }
        if (cnt0) {
            v.push_back({0, cnt0});
            cnt0 = 0;
        }
        if (cnt1) {
            v.push_back({1, cnt1});
            cnt1 = 0;
        }
        ans = check(v, 0);
        if (ans == 0) std::cout << "NO\n";
        else std::cout << "YES\n";
    }

    return 0;
}
