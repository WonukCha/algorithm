#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> m;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	for (auto k : participant)
	{
		m[k]++;
	}
	for (auto i : completion)
	{
		m[i]--;
	}

	for (auto j : m)
	{
		if (j.second > 0)
		{
			answer = j.first;
		}
	}
	return answer;
}
int main(void)
{
	solution({ "leo", "kiki", "eden" }, { "eden", "kiki" });
	
	return 0;
}