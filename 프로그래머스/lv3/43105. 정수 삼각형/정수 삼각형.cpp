#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp;
    int iend = triangle.size();
    dp.resize(iend);
    for (int i = 0; i < iend; ++i) {
        int jend = triangle[i].size();
        for (int j = 0; j < jend; ++j) {
            int tmp = 0;
            if (j > 0) {
                tmp = max(tmp, dp[i - 1][j - 1]);
            }
            if (j < jend - 1) {
                tmp = max(tmp, dp[i - 1][j]);
            }
            dp[i].push_back(tmp + triangle[i][j]);
            answer = max(answer, dp[i].back());
        }
    }
    
    return answer;
}