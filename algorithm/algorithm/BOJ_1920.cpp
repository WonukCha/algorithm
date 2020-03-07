#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int>v1;

bool SerchNumber(int num)
{
	int nTargetNum = num;
	int nCurrentNum = -1;
	int nStartIndex = 0;
	int nEndIndex = v1.size() - 1;
	int nCurrentIndex = 0;
	bool bResult = 0;
	while (true)
	{
		if (nStartIndex >nEndIndex)
		{
			break;
		}
		nCurrentIndex = nStartIndex + ((nEndIndex - nStartIndex) / 2);
		nCurrentNum = v1[nCurrentIndex];
		if (nCurrentNum == nTargetNum)
		{
			bResult = true;
			break;
		}
		else if (nCurrentNum < nTargetNum)
		{
			nStartIndex = nCurrentIndex + 1;
		}
		else
		{
			nEndIndex = nCurrentIndex - 1;
		}

		
	}
	return bResult;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int nCount1;
	cin >> nCount1;
	v1.resize(nCount1);
	for (int i = 0; i < nCount1; i++)
	{
		cin >> v1[i];
	}
	sort(v1.begin(), v1.end());
	int nCount2;
	cin >> nCount2;
	int nTarget;
	for (int i = 0; i < nCount2; i++)
	{
		cin >> nTarget;
		cout << SerchNumber(nTarget) << '\n';
	}

	return 0;
}