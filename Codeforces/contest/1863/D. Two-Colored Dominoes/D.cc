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

char mat[500][500];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for (cin >> t; t--;) {
        int n, m;
        cin >> n >> m;
        FOR(i, n) {
            FOR(j, m) {
                cin >> mat[i][j];
            }
        }
        bool impossible = false;
        FOR(i, n - 1) {
            int cnt = 0;
            FOR(j, m) {
                if (mat[i][j] == 'U') {
                    ++cnt;
                    if (cnt % 2) {
                        mat[i][j] = 'W';
                        mat[i + 1][j] = 'B';
                    }
                    else {
                        mat[i][j] = 'B';
                        mat[i + 1][j] = 'W';
                    }
                }
            }
            if (cnt % 2) {
                impossible = true;
                break;
            }
        }
        FOR(j, m - 1) {
            int cnt = 0;
            FOR(i, n) {
                if (mat[i][j] == 'L') {
                    ++cnt;
                    if (cnt % 2) {
                        mat[i][j] = 'W';
                        mat[i][j + 1] = 'B';
                    }
                    else {
                        mat[i][j] = 'B';
                        mat[i][j + 1] = 'W';
                    }
                }
            }
            if (cnt % 2) {
                impossible = true;
                break;
            }
        }
        if (impossible) {
            cout << "-1\n";
            continue;
        }
        FOR(i, n) {
            FOR(j, m) {
                cout << mat[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}

