#include <string>
#include <vector>
#include <iostream>

using namespace std;

int splitCount(const string& in) {
	int check = 0;
	for (int i = 0; i < in.length(); ++i) {
		if (in[i] == '(') check++;
		else check--;

		if (check == 0) return i + 1;
	}
}

bool validBracket(const string& in) {
	int check = 0;
	for (int i = 0; i < in.length(); ++i) {
		if (in[i] == '(') check++;
		else check--;

		if (check < 0) return false;	// 올바른 괄호 문자열 조건을 만족 하려면 '(' 부터 시작이므로 -가 나올수 없음
	}
	return true;
}

string conversionBracket(const string& in) {
	string result;
	for (int i = 1; i < in.length() -1; ++i) {
		if (in[i] == '(') result += ')';
		else result += '(';
	}
	return result;
}

void conversionString(string& out, const string& in) {
    string u, v;
    const int len = in.length();   
    const int split = splitCount(in);
    u = in.substr(0, split);
    if (split < len) v = in.substr(split, len-split);

	if (validBracket(u)) out += u;
	else {
		out += '(';
		if (!v.empty()) {
			conversionString(out, v);
			v.clear();
		}
		out += ')';
		out += conversionBracket(u);
	}
	if (!v.empty()) {
		conversionString(out, v);
	}
}

string solution(string p) {
    string answer = "";
    
    if (p.empty()) return answer;
	conversionString(answer, p);
    
    return answer;
}