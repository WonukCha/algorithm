#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<stack>
#include<queue>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int level,temp;
	bool bDirection;


	cin >> temp;
	if (temp == 1)
	{
		bDirection = true;
		level = 2;
	}
	else if (temp == 8)
	{
		bDirection = false;
		level = 7;
	}
	else
	{
		cout << "mixed";
		return 0;
	}

	for (int i = 1; i < 8; i++)
	{
		cin >> temp;
		if (bDirection)
		{
			if (temp != level)
			{
				cout << "mixed";
				return 0;
			}
		}
		else
		{

		}

	}

	return 0;
}