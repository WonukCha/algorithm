#include<iostream>

using namespace std;

unsigned long long cartridge;
unsigned long long curSum;

void solve(int index)
{
	unsigned long long minCartridge[4] = { 4294967295,4294967295,4294967295,4294967295 };
	for (int printIndex = 0; printIndex < 3; printIndex++)
	{
		for (int colorIndex = 0; colorIndex < 4; colorIndex++)
		{
			cin >> cartridge;
			if (minCartridge[colorIndex] > cartridge)
			{
				minCartridge[colorIndex] = cartridge;
			}
		}
	}
	unsigned long long result[4] = { 0,0,0,0 };
	curSum = 0;
	for (int i = 0; i < 4; i++)
	{
		if (1000000 - curSum >= minCartridge[i])
		{
			result[i] = minCartridge[i];
			curSum += result[i];
		}
		else if (1000000 > curSum)
		{
			result[i] = 1000000 - curSum;
			curSum += result[i];
		}
		else
		{
			result[i] = 0;
		}
	}
	cout << "Case #" << index << ":";
	if (1000000 > curSum)
	{
		cout << " IMPOSSIBLE";
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			cout << " " << result[i];
		}
	}
	cout << "\n";
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testCaseCount = 0;
	int curCase = 0;

	cin >> testCaseCount;

	while (curCase < testCaseCount)
	{
		solve(curCase + 1);
		++curCase;
	}
	return 0;
}