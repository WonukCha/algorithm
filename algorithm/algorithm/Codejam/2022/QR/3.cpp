#include <iostream>
#include <algorithm>

using namespace std;


unsigned long long resultValue;
unsigned long long currentValue;
unsigned long long diceCount;
unsigned long long diceValue[100001];
void solve(int caseIndex)
{
	cin >> diceCount;
	for (int i = 0; i < diceCount; i++)
	{
		cin >> diceValue[i];
	}

	sort(diceValue, diceValue + diceCount);
	currentValue = 1;
	for(unsigned int i = 0;i< diceCount;i++)
	{
		if (diceValue[i] >= currentValue)
		{
			resultValue = currentValue;
			currentValue++;
		}
	}
	cout << "Case #" << caseIndex << ": " << resultValue << "\n";
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