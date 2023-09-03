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
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for (cin >> t; t--;) {
        int n, a, q;
        string str;
        cin >> n >> a >> q >> str;
        int cnt = a, plus = a, guar = a;
        for (auto c : str) {
            if (c == '-') {
                --cnt;
            }
            else {
                ++cnt;
                ++plus;
                guar = max(guar, cnt);
            }
        }
        if (guar == n) {
            cout << "YES\n";
        }
        else if (plus >= n) {
            cout << "MAYBE\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}

