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
        int n, k;
        cin >> n >> k;
        k %= n + 1;
        int sidx = (n + 1) - k;
        vi v;
        vector<bool> check;
        v.resize(n);
        check.resize(n + 1);
        for (auto& e : v) {
            cin >> e;
            check[e] = true;
        }
        FOR(i, n + 1) {
            if (check[i] == false) {
                v.push_back(i);
            }
        }
        for (int i = sidx; i < n + 1; ++i) {
            cout << v[i] << " ";
        }
        for (int i = 0; i < sidx - 1; ++i) {
            cout << v[i] << " ";
        }
        cout << "\n";

    }
    return 0;
}

