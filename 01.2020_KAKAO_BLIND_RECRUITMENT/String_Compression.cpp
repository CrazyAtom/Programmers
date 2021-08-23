#include <string>
#include <vector>
#include <iostream>

using namespace std;

string compression(const string& in, const int& comp) {
    const int len = in.length();
    string result = "";
    string pattern = "";
    int count = 1;
    
    for (int i = 0; i < len/comp; ++i) {              
        const string current = in.substr(i*comp, comp);
        if (pattern == current) {
            count++;
            continue;
        }

        if (count > 1) {
            result += to_string(count) + pattern;
            count = 1;
        } else result += pattern;

        pattern = current;
    }

    if (count > 1) result += to_string(count) + pattern;
    else result += pattern;

    const int rem = len%comp;
    if (rem != 0) result += in.substr((len-rem), rem);
    
    return result;
}

int solution(string s) {
    const int len = s.length();
    if (len == 1) return 1;
    
    int answer = 1000;
	for (int word = 1; word <= len/2; ++word) {
        string comp_s = compression(s, word);
		answer = (comp_s.length() < answer) ? comp_s.length() : answer;
	}

    return answer;
}