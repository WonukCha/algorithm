#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<utility>

using namespace std;
enum color
{
	R = 0,
	G,
	B 
};
#define R 0
#define G 1
#define B 2

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> vInput(n, vector<int>(3));
	vector<vector<int>> vResult(n, vector<int>(3, 2147483647));
	int nInputR;
	int nInputG;
	int nInputB;

	for (int i = 0; i < n; i++)
	{
		cin >> nInputR;
		cin >> nInputG;
		cin >> nInputB;

		vInput[i][R] = nInputR;
		vInput[i][G] = nInputG;
		vInput[i][B] = nInputB;
	}

	vResult[0][R] = vInput[0][R];
	vResult[0][G] = vInput[0][G];
	vResult[0][B] = vInput[0][B];


	for (int i = 1; i < n; i++)
	{
		for (int jj = 0; jj < 3; jj++)
		{
			if (jj != R)
			{
				if (vResult[i - 1][jj] + vInput[i][R] < vResult[i][R])
				{
					vResult[i][R] = vResult[i - 1][jj] + vInput[i][R];
				}
			}
			if (jj != B)
			{
				if (vResult[i - 1][jj] + vInput[i][B] < vResult[i][B])
				{
					vResult[i][B] = vResult[i - 1][jj] + vInput[i][B];
				}
			}
			if (jj != G)
			{
				if (vResult[i - 1][jj] + vInput[i][G] < vResult[i][G])
				{
					vResult[i][G] = vResult[i - 1][jj] + vInput[i][G];
				}
			}
		}
	}

	int nResult = 2147483647;
	for (int i = 0; i < 3; i++)
	{
		if (nResult > vResult[n - 1][i])
		{
			nResult = vResult[n - 1][i];
		}
	}
	cout << nResult;

	return 0;
}