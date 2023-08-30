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
int mat[1001][1001];
int n, m;
pii start;
int dist[1001][1001];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool inMap(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

void bfs(pii point) {
    queue<piii> q;
    q.push({0, point});
    for (; !q.empty();) {
        piii fr = q.front();
        q.pop();
        int d = fr.first;
        int i = fr.second.first;
        int j = fr.second.second;
        FOR(k, 4) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (!inMap(ni, nj) || make_pair(ni, nj) == point || mat[ni][nj] == 0) {
                continue;
            }
            int nd = d + 1;
            if (dist[ni][nj] == -1 || dist[ni][nj] > nd) {
                dist[ni][nj] = nd;
                q.push({nd, {ni, nj}});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    FOR(i, n) {
        FOR(j, m) {
            cin >> mat[i][j];
            dist[i][j] = -1;
            if (mat[i][j] == 1) {
                dist[i][j] = -1;
            }
            else {
                dist[i][j] = 0;
            }
            if (mat[i][j] == 2) {
                start = {i, j};
                dist[i][j] = 0;
            }
        }
    }
    bfs(start);
    FOR(i, n) {
        FOR(j, m) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

