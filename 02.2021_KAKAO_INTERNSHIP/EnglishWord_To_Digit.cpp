#include <string>
#include <vector>
#include <map>
#include <regex>

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
	initDicNumber();
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
	int answer = 0;
    // answer = makeDigit(s);
    
    s = regex_replace(s, regex("zero"), "0");
	s = regex_replace(s, regex("one"), "1");
	s = regex_replace(s, regex("two"), "2");
	s = regex_replace(s, regex("three"), "3");
	s = regex_replace(s, regex("four"), "4");
	s = regex_replace(s, regex("five"), "5");
	s = regex_replace(s, regex("six"), "6");
	s = regex_replace(s, regex("seven"), "7");
	s = regex_replace(s, regex("eight"), "8");
	s = regex_replace(s, regex("nine"), "9");
    answer = stoi(s);
    
    return answer;
}