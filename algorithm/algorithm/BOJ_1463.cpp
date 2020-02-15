#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<utility>


using namespace std;

int main(void)
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	
	int nCount;
	cin >> nCount;

	if (nCount <= 3)
	{
		switch (nCount)
		{
		case 1:
			cout << 0;
			break;
		case 2:
			cout << 1;
			break;
		case 3:
			cout << 1;
			break;
		}
	}
	else
	{
		vector<int> v(nCount + 1);
		v[0] = 0;
		v[1] = 0;
		v[2] = 1;
		v[3] = 1;

		for (int i = 4; i <= nCount; i++)
		{
			int nMin = v[i - 1]+1;
			v[i] = nMin;
			if (i % 2 == 0)
			{
				if (nMin > v[i / 2]+1)
				{
					nMin = v[i / 2] + 1;
					v[i] = nMin;
				}
				else
				{
					v[i] = nMin;
				}
			}
			if(i % 3 == 0)
			{
				if (nMin > v[i / 3] + 1)
				{
					nMin = v[i / 3] + 1;
					v[i] = nMin;
				}
				else
				{
					v[i] = nMin;
				}
			}
		}
		cout << v[nCount];
	}
	return 0;
}
