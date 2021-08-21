#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id)
{
	string answer = "";

	cout << "origin : " << new_id << endl;

	// step 1
	transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
	cout << "step 1 : " << new_id << endl;

	// step 2
	for (char c : new_id)
	{
		if (('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || strchr("-_.", c))
			answer += c;
	}
	new_id = answer;
	cout << "step 2 : " << new_id << endl;

	// step 3
	answer.clear();
	for (char c : new_id)
	{
		if (!answer.empty() && '.' == answer.back() && '.' == c)
			continue;
		answer += c;
	}
	cout << "step 3 : " << answer << endl;

	// step 4
	if ('.' == answer.front())
		answer.erase(answer.begin());
	if ('.' == answer.back())
		answer.pop_back();
	cout << "step 4 : " << answer << endl;

	// step 5
	if (answer.empty())
		answer = "a";
	cout << "step 5 : " << answer << endl;

	// step 6
	if (answer.length() >= 16)
		answer = answer.substr(0, 15);
	if ('.' == answer.back())
		answer.pop_back();
	cout << "step 6 : " << answer << endl;

	// step 7
	while (answer.length() <= 2)
		answer += answer.back();
	cout << "step 7 : " << answer << endl;

	return answer;
}