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

#define ll long long

using namespace std;
int n;

ll t[3000000];
ll p[3000000];
ll d[3000000];

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

		cin >> n;

	int input = 0;
	for (size_t i = 0; i < n; i++)
	{
		cin >> input;
		t[i] = input;

		cin >> input;
		p[i] = input;
	}

	for (size_t i = 0; i < n; i++)
	{
		if (i > 0)
		{
			d[i] = max(d[i], d[i - 1]);
		}
		d[i + t[i]] = max(d[i] + p[i], d[i + t[i]]);
	}

	ll answer = 0;
	for (size_t i = 0; i < n + 1; i++)
	{
		answer = max(answer, d[i]);
	}

	cout << answer;
	return 0;
}
