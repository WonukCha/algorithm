#include<iostream>

using namespace std;

void print1(int C)
{
	bool IsOddNumber = true;
	for (int j = 0; j < C * 2 + 1; j++)
	{
		if (IsOddNumber)
			cout << '+';
		else
			cout << '-';

		IsOddNumber = !IsOddNumber;
	}
	cout << '\n';
}
void print2(int C)
{
	bool IsOddNumber = true;
	for (int j = 0; j < C * 2 + 1; j++)
	{
		if (IsOddNumber)
			cout << '|';
		else
			cout << '.';
		IsOddNumber = !IsOddNumber;
	}
	cout << '\n';
}
void print3(int C)
{
	bool IsOddNumber = true;
	cout << "..";
	for (int j = 2; j < C * 2 + 1; j++)
	{
		if (IsOddNumber)
			cout << '+';
		else
			cout << '-';

		IsOddNumber = !IsOddNumber;
	}
	cout << '\n';
}
void print4(int C)
{
	bool IsOddNumber = true;
	cout << "..";
	for (int j = 2; j < C * 2 + 1; j++)
	{
		if (IsOddNumber)
			cout << '|';
		else
			cout << '.';
		IsOddNumber = !IsOddNumber;
	}
	cout << '\n';
}



void solve(int R, int C)
{
	bool IsFarst = true;
	bool IsOddNumber = true;
	print3(C);
	print4(C);
	for (int i = 0; i < R-1; i++)
	{
		print1(C);
		print2(C);
	}
	print1(C);
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
		int R = 0;
		int C = 0;

		cin >> R;
		cin >> C;
		
		cout << "Case #" << curCase + 1 << ":\n";
		solve(R, C);
		++curCase;
	}
	return 0;
}