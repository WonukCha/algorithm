#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<utility>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <hash_map>

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


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<string> v1 = { "leo", "kiki", "eden" };
	vector<string> v2 = {  "kiki", "eden" };

	

	cout << solution(v1, v2);
}

