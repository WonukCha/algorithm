#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	int n;

	cin >> n;
	vector<int>vInput(n, 0);
	vector<int>vResult(n, 0);

	// 입력
	for (int i = 0; i < n; i++)
	{
		cin >> vInput[i];
	}
	//첫번째 값 셋팅
	vResult[0] = 1;
	
	//영차영차 쌓아올리기
	for (int i = 1; i < n; i++)
	{
		int nMax = 1;
		for (int jj = i - 1; jj >= 0; jj--)
		{
			if (vInput[i] > vInput[jj])
			{
				if (nMax <= vResult[jj])
				{
					nMax = vResult[jj] + 1;
				}
			}
		}
		vResult[i] = nMax;
	}
	//가장 큰값 찾기
	int nResult = vResult[0];
	for (int i = 1; i < n; i++)
	{
		nResult = max(nResult, vResult[i]);
	}
	cout << nResult;
	return 0;
}