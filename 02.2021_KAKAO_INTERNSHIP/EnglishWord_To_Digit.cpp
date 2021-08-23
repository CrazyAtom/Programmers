#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> dicNumber;

void initDicNumber() {
	dicNumber["zero"] = "0";
	dicNumber["one"] = "1";
	dicNumber["two"] = "2";
	dicNumber["three"] = "3";
	dicNumber["four"] = "4";
	dicNumber["five"] = "5";
	dicNumber["six"] = "6";
	dicNumber["seven"] = "7";
	dicNumber["eight"] = "8";
	dicNumber["nine"] = "9";
}

int makeDigit(const string& in) {
	string result = "";
	string tmp = "";
	for (int i = 0; i < in.length(); ++i) {
		if (isdigit(in[i])) result += in[i];
		else {
			tmp += in[i];
			if (!dicNumber[tmp].empty()) {
				result += dicNumber[tmp];
				tmp.clear();
			}
		}
	}
	return stoi(result);
}

int solution(string s) {  
	initDicNumber();
	int answer = makeDigit(s);
    return answer;
}