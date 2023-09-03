#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<pair<int, int>> maxs;
    priority_queue<pair<int, int>> mins;
    vector<bool> isPopped;
    
    int index = 0;
    for (auto o : operations) {
        string q;
        int num;
        stringstream stream;
        stream.str(o);
        stream >> q >> num;
        if (q == "I") {
            maxs.push({num, index});
            mins.push({-num, index});
            ++index;
            isPopped.push_back(false);
        }
        else if (q == "D") {
            if (num == 1) {
                
                for (; !maxs.empty();) {
                    if (isPopped[maxs.top().second]) {
                        maxs.pop();
                    }
                    else {
                        isPopped[maxs.top().second] = true;
                        maxs.pop();
                        break;
                    }
                }
            }
            else if (num == -1) {
                for (; !mins.empty();) {
                    if (isPopped[mins.top().second]) {
                        mins.pop();
                    }
                    else {
                        isPopped[mins.top().second] = true;
                        mins.pop();
                        break;
                    }
                }
            }
            else {

            }
        }
    }
    for (; !maxs.empty();) {
        if (isPopped[maxs.top().second]) {
            maxs.pop();
        }
        else {
            break;
        }
    }
    for (; !mins.empty();) {
        if (isPopped[mins.top().second]) {
            mins.pop();
        }
        else {
            break;
        }
    }
    if (maxs.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(maxs.top().first);
        answer.push_back(-mins.top().first);
    }
    return answer;
}