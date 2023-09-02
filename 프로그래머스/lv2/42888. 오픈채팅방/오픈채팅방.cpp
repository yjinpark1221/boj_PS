#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> mp;
    vector<pair<string, string> > v;
    for (string r : record) {
        stringstream stream;
        stream.str(r);
        string q, id, nickname;
        stream >> q;
        if (q == "Enter") {
            stream >> id >> nickname;
            mp[id] = nickname;
            v.push_back({id, "님이 들어왔습니다."});
        }
        else if (q == "Leave") {
            stream >> id;
            v.push_back({id, "님이 나갔습니다."});
        }
        else if (q == "Change") {
            stream >> id >> nickname;
            mp[id] = nickname;
        }
    }
    for (auto a : v) {
        answer.push_back(mp[a.first]+a.second);
    }
    
    return answer;
}