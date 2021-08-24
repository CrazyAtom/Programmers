#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX_ROW	= 4;
const int MAX_COL	= 3;
const int dx[4]		= { 0, 0, 1, -1};
const int dy[4]		= { 1, -1, 0, 0};
int keypad[4][3]	= {-1,2,-1,-1,5,-1,-1,8,-1,-1,0,-1};

struct Number {
	pair<int, int> pos;
	int score;
	Number(const int& r, const int& c, const int& s) : pos(r, c), score(s) {}
};

bool checkBound(const int& row, const int& col) {
	return (0 <= row && row < MAX_ROW && 0 <= col && col < MAX_COL);
}

int BFS(const int& r, const int&c, const int& target, pair<int, int>& pos) {
	bool visited[MAX_ROW][MAX_COL] = {false,};
	queue<Number> que;
	que.push(Number(r, c, 0));
	visited[r][c] = true;

	while (!que.empty()) {
		const Number& current = que.front();
		que.pop();

		if (keypad[current.pos.first][current.pos.second] == target) {
			pos = current.pos;
			return current.score;
		}
		
		for (int i = 0; i < 4; ++i) {
            const int cx = current.pos.first + dx[i];
            const int cy = current.pos.second + dy[i];
            if (!checkBound(cx, cy) || visited[cx][cy] || keypad[cx][cy] == -1) continue;
            que.push(Number(cx, cy, current.score+1));
            visited[cx][cy] = true;
		}
	}
	return 0;
}

string orderHand(const int& number, pair<int, int>& posL, pair<int, int>& posR) {
    string result = "";
	switch (number)
	{
	case 1:
		posL = {0, 0}; result = "L"; break;
	case 4:
		posL = {1, 0}; result = "L"; break;
	case 7:
		posL = {2, 0}; result = "L"; break;
	case 3:
		posR = {0, 2}; result = "R"; break;
	case 6:
		posR = {1, 2}; result = "R"; break;
	case 9:
		posR = {2, 2}; result = "R"; break;
	default:
        result = ""; break;
	}
    return result;
}

string orderHand(const int& distL, const int& distR, const string& hand) {
	if (distR < distL) return "R";
	else if (distR > distL) return "L";
	else return (hand == "right") ? "R" : "L";
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

	pair<int, int> posL = {3, 0};
	pair<int, int> posR = {3, 2};
	for (const auto& number : numbers) {      
		string tmp = orderHand(number, posL, posR);
		if (!tmp.empty()) answer += tmp;
		else {
			pair<int, int> _posL, _posR;
			const int distL = BFS(posL.first, posL.second, number, _posL);
			const int distR = BFS(posR.first, posR.second, number, _posR);
			tmp = orderHand(distL, distR, hand);
			if (tmp == "R") posR = _posR;
			else posL = _posL;
			answer += tmp;
		}
	}

    return answer;
}