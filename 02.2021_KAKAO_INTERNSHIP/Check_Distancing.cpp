#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAN_DIST  = 2;
const int MAX_ROW   = 5;
const int MAX_COL   = 5;

const int dx[4]     = { 0, 0, 1, -1};
const int dy[4]     = { 1, -1, 0, 0};

struct Item {
	pair<int, int> pos;
	int dist;
	Item(const int& row, const int& col, const int& score) : pos(row, col), dist(score) {};
};

bool checkBound(const int& row, const int& col) {
	return (0 <= row && row < MAX_ROW && 0 <= col && col < MAX_COL);
}

bool BFS(const int& row, const int& col, const vector<string>& room) {
	bool visited[5][5] = { false, };
	queue<Item> que;
	que.push(Item(row, col, 0));
	visited[row][col] = true;

	while (!que.empty()) {
		const Item current = que.front();
		que.pop();

		if (MAN_DIST <= current.dist) continue;

		// 상, 하, 좌, 우 체크
		for (int i = 0; i < 4; ++i) {
			const int cx = current.pos.first + dx[i];
			const int cy = current.pos.second + dy[i];
			if (!checkBound(cx, cy) || visited[cx][cy]) continue;
			if (room[cx][cy] == 'P') return false;
			if (room[cx][cy] == 'O') {
				que.push(Item(cx, cy, current.dist+1));
				visited[cx][cy] = true;
			}
		}
	}
	return true;
}

bool CheckRoom(vector<string> room) {
	for (int row = 0; row < room.size(); ++ row) {
		for (int col = 0; col < room[row].length(); ++col) {
			if (room[row][col] == 'P') {
                if (!BFS(row, col, room)) return false;
            }
		}
	}
	return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
	for (const auto& place : places) answer.push_back(CheckRoom(place) ? 1 : 0);
    return answer;
}