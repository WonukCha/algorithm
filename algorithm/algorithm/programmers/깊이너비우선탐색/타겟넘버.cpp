#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


int solution(vector<int> numbers, int target) {
	int answer = 0;
	stack<pair<int, int>> s;

	s.push(pair<int, int>(numbers[0] * 1, 0));
	s.push(pair<int, int>(numbers[0] * -1, 0));

	while (!s.empty())
	{
		pair<int, int> cur;
		cur = s.top(); s.pop();
		int value = cur.first;
		int index = cur.second;


		if (index == numbers.size() - 1)
		{
			if (target == value)
				answer++;
		}
		else
		{
			int nextValuePlus = value + numbers[index + 1];
			int nextValueMinus = value - numbers[index + 1];
			int nextIndex = index + 1;
			s.push(pair<int, int>(nextValuePlus, nextIndex));
			s.push(pair<int, int>(nextValueMinus, nextIndex));
		}

	}
	return answer;
}

int main(void)
{
	solution({ 1, 1, 1, 1, 1 },3);

	return 0;
}