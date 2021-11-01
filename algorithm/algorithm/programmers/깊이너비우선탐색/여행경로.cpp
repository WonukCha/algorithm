#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
struct MyStruct
{
	string str;
	vector<bool>check;
	queue<string> q;
	int depth;
};

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	sort(tickets.begin(), tickets.end());

	vector<bool> check(tickets.size());
	queue<MyStruct> q;
	for (int i = 0; i < tickets.size(); i++)
	{
		if (tickets[i][0] == "ICN")
		{
			MyStruct cur;
			cur.str = tickets[i][1];
			cur.check = check;
			cur.check[i] = true;
			cur.depth = 0;
			cur.q.push(tickets[i][0]);
			cur.q.push(tickets[i][1]);
			q.push(cur);
		}
	}

	while (!q.empty())
	{
		MyStruct cur;
		cur = q.front(); q.pop();

		if (cur.depth == tickets.size() - 1)
		{
			while (!cur.q.empty())
			{
				string str;
				str = cur.q.front(); cur.q.pop();
				answer.push_back(str);
			}
			break;
		}

		for (int i = 0; i < tickets.size(); i++)
		{
			if (cur.check[i] == false)
			{
				if (cur.str == tickets[i][0])
				{
					MyStruct next;
					next.str = tickets[i][1];
					next.check = cur.check;
					next.check[i] = true;
					next.depth = cur.depth + 1;
					next.q = cur.q;
					next.q.push(tickets[i][1]);
					q.push(next);
				}
			}
		}
	}
	return answer;
}

int main(void)
{
	solution({ {"ICN", "JFK"},{"HND", "IAD"},{"JFK", "HND"} });
	return 0;
}