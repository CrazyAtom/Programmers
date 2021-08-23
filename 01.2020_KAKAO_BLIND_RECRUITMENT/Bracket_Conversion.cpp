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
	return (check == 0);
}

string conversionBracket(const string& in) {
	string result;
	for (int i = 1; i < in.length() -1; ++i) {
		if (in[i] == '(') result += ')';
		else result += '(';
	}
	return result;
}

string conversionString(const string& in) {
    if (in.empty()) return in;
    if (validBracket(in)) return in;
    
    const int split = splitCount(in);
    string u = in.substr(0, split);
    string v = in.substr(split);

	if (validBracket(u)) return (u + conversionString(v));
	else return '(' + conversionString(v) + ')' + conversionBracket(u);
}

string solution(string p) {
    string answer = "";
        
	answer = conversionString(p);
    
    return answer;
}