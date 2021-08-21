#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int max_cnt_comb = 0;
map<string, int> comb_cnt;

void CombMenu(const string &order, const string &comb, const int &cnt)
{
    if (comb.size() == cnt) {
        comb_cnt[comb]++;
        max_cnt_comb = max(max_cnt_comb, comb_cnt[comb]);
    } else {
        for (int i = 0; i < order.size(); ++i)
            CombMenu(order.substr(i+1), comb+order[i], cnt);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (auto& order : orders) {
        sort(order.begin(), order.end());
	}

	for (const auto& cnt : course) {
		for (const auto& order : orders) {
			CombMenu(order, "", cnt);		
		}

		for (const auto& comb : comb_cnt) {
			if (comb.second >= 2 && comb.second == max_cnt_comb) {
				answer.push_back(comb.first);
			}
		}

		max_cnt_comb = 0;
		comb_cnt.clear();
	}

	sort(answer.begin(), answer.end());

    return answer;
}