#include <string>
#include <vector>
#include <stack>

using namespace std;

struct MyStruct
{
	string str;
	int depth;
	vector<bool>check;
};
bool comper(string str1, string str2)
{
	bool result = true;
	int count = 0;
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] != str2[i])
		{
			count++;
			if (count > 1)
			{
				result = false;
				break;
			}

		}
	}
	return result;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;

	vector<bool> check(words.size());
	stack<MyStruct> s;
	MyStruct st;
	st.str = begin;
	st.depth = 0;
	st.check = check;
	s.push(st);

	while (!s.empty())
	{
		MyStruct cur;
		cur = s.top(); s.pop();

		if (cur.str == target)
		{
			answer = cur.depth;
			break;
		}

		for (int i = 0; i < cur.check.size(); i++)
		{
			if (cur.check[i] == false)
			{
				if (comper(cur.str, words[i]))
				{
					MyStruct next;
					next.depth = cur.depth + 1;
					next.check = cur.check;
					next.check[i] = true;
					next.str = words[i];
					s.push(next);
				}

			}
		}

	}
	return answer;
}

int main(void)
{
	solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
	return 0;
}