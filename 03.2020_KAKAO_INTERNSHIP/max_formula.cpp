#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector exp = {'*', '+', '-'};

long long calc(const long long& lhs, const long long& rhs, const char& exp) {
	switch (exp)
	{
	case '*':
		return lhs * rhs;
	case '+':
		return lhs + rhs;
	case '-':
		return lhs - rhs;
	}
	return 0;
}

long long solution(string expression) {
	long long answer = 0;

	vector<long long> nums;
	vector<char> exps;
	string tmp = "";
	for (const char &c : expression) {
		if (isdigit(c)) tmp += c;
		else {
			exps.push_back(c);
			nums.push_back(stoi(tmp));
			tmp.clear();
		}
	}
	nums.push_back(stoi(tmp));
    
	sort(exp.begin(), exp.end());
	do {
		vector<long long> _nums = nums;
		vector<char> _exps = exps;
		for (int i = 0; i < exp.size(); ++i) {
			for (int j = 0; j < _exps.size(); ++j) {
				if (exp[i] == _exps[j]) {
					_nums[j] = calc(_nums[j], _nums[j+1], exp[i]);
					_nums.erase(_nums.begin() + j + 1);
					_exps.erase(_exps.begin() + j);
					j--;
				}
			}
		}
		answer = max(abs(_nums[0]), answer);
	} while (next_permutation(exp.begin(), exp.end()));

	return answer;
}