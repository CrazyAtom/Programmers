#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

enum key { kLan, kJop, kCareer, kFood, kMax };
unordered_map<string, vector<int>> condition_scores;

string condition(string* key, int mask) {
	string s = "";
	for (int i = 0; i < kMax; ++i)
		s += (mask & (1 << i)) ? "-" : key[i];
	return s;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
	// 가능한 모든 조건 생성
	string key[kMax];
	int point = 0;
	for (const auto& val : info) {
		istringstream iss(val);
		iss >> key[kLan] >> key[kJop] >> key[kCareer] >> key[kFood] >> point;
		for (int i = 0; i < 16; ++i) condition_scores[condition(key, i)].push_back(point);
	}

	// 각 조건에 대한 점수 정렬 (이진 탐색을 위해)
	for (auto& val : condition_scores) {
		sort(val.second.begin(), val.second.end());
	}

	string tmp = "";
	for (const auto& val : query) {
		istringstream iss(val);
		iss >> key[kLan] >> tmp >> key[kJop] >> tmp >> key[kCareer] >> tmp >> key[kFood] >> point;
		tmp = key[kLan] + key[kJop] + key[kCareer] + key[kFood];
		vector<int>& scores = condition_scores[tmp];
		// 조건에 만족하는 점수 이상 개수 (end - find iterator)
		answer.push_back(scores.end() - lower_bound(scores.begin(), scores.end(), point));
	}
    
    return answer;
}