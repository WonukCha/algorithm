#include<iostream>
#include <queue>
#include <Windows.h>

using namespace std;


bool arrbMap[502][502];
int nSizeY, nSizeX;
queue<pair<int, int>>q;


void SerchMap(int y, int x)
{
	//위검사
	if (y != 0)
	{
		if (arrbMap[y - 1][x])
		{
			q.push(make_pair(y - 1, x));
			arrbMap[y - 1][x] = false;
		}
	}
	//아래검사
	if (y != nSizeY)
	{
		if (arrbMap[y + 1][x])
		{
			q.push(make_pair(y + 1, x));
			arrbMap[y + 1][x] = false;

		}
	}
	//왼쪽검사
	if (x != 0)
	{
		if (arrbMap[y][x - 1])
		{
			q.push(make_pair(y, x - 1));
			arrbMap[y][x - 1] = false;
		}
	}
	//오른쪽검사
	if (x != nSizeX)
	{
		if (arrbMap[y][x + 1])
		{
			q.push(make_pair(y, x + 1));
			arrbMap[y][x + 1] = false;
		}
	}

}
int BFS(int y, int x, int &nSize)
{
	arrbMap[y][x] = false;

	while (!q.empty())
	{
		pair<int, int> p;
		p = q.front();
		q.pop();
		nSize++;

		SerchMap(p.first, p.second);
	}
	return nSize;
}


//(y,x)
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int nMaxRectSize = 0;
	int nCount = 0;


	cin >> nSizeY >> nSizeX;

	for (int y = 0; y < nSizeY; y++)
	{
		for (int x = 0; x < nSizeX; x++)
		{
			cin >> arrbMap[y][x];
		}
	}
	DWORD start = GetTickCount();

	for (int y = 0; y < nSizeY; y++)
	{
		for (int x = 0; x < nSizeX; x++)
		{
			if (arrbMap[y][x])
			{
				q.push(make_pair(y, x));
				int size = 0;
				BFS(y, x, size);
				if (size > nMaxRectSize)
				{
					nMaxRectSize = size;
				}
				nCount++;
			}
		}
	}
	cout << nCount << '\n' << nMaxRectSize << '\n';

	DWORD end = GetTickCount();
	std::cout << end - start << "ms";
	return 0;
}