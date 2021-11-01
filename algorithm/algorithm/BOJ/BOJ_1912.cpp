#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> vInput(n);
	vector<int> vResult(n);
	int nInput;
	for (int i = 0; i < n; i++)
	{
		cin >> vInput[i];
	}
	vResult[0] = vInput[0];

	for (int i = 1; i < n; i++)
	{
		if (vInput[i] < vResult[i - 1] + vInput[i])
		{
			vResult[i] = vResult[i - 1] + vInput[i];
		}
		else
		{
			vResult[i] = vInput[i];
		}
	}
	int nResult = vResult[0];
	for (int i = 1; i < n; i++)
	{
		nResult = max(nResult, vResult[i]);
	}

	cout << nResult;
	return 0;
}