#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<utility>
using namespace std;

int main(void)
{
	int nCount, nFixResultValue;
	cin >> nCount >> nFixResultValue;
	vector<int>vArr(nCount, 0);
	


	int nResultCount = 0;
	int nInput = 0;
	//입력
	for (int i = 0; i < vArr.size(); i++)
	{
		cin >> nInput;
		vArr[i] = nInput;
	}
	vector<bool>vCheck(nCount, 0);
	for (int i = vCheck.size(); i > 0; i--)
	{
		vCheck[i - 1] = true;
		do
		{
			int nResult = 0;
			for (int j = 0; j < nCount; j++)
			{
				if (vCheck[j] == true)
				{
					nResult += vArr[j];
				}
			}
			if (nResult == nFixResultValue)
			{
				nResultCount;
			}
		} while (next_permutation(vCheck.begin(), vCheck.end()));

	}
	
	//조합?, 탐색?
	

	cout << nResultCount;
	return 0;
}