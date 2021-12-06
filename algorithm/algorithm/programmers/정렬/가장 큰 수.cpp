#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
#include<utility>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<tuple>

using namespace std;
//TODO : 다시 풀어보쟈..
bool cmp(string str1, string str2)
{
	string merge1 = str1 + str2;
	string merge2 = str2 + str1;
	int result1 = stoi(merge1);
	int result2 = stoi(merge2);

	return result1 > result2;
}


string solution(vector<int> numbers) {
	string answer = "";

	vector<string> v;
	v.resize(numbers.size());

	do
	{
		for (unsigned int i = 0; i < numbers.size(); i++)
		{
			v[i] = to_string(numbers[i]);
		}

		sort(v.begin(), v.end(), cmp);
		if (v[0][0] == '0')
		{
			answer = "0";
			break;
		}

		for (unsigned int i = 0; i < v.size(); i++)
		{
			answer += v[i];
		}

	} while (false);

	return answer;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	solution({ 1000, 1000, 1000 });
	solution({ 6, 10, 2 });
	solution({ 3, 30, 34, 5, 9 });

	return 0;
}
