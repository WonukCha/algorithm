#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<utility>


using namespace std;

vector<bool> v1; // y에 관한 체크 배열   값 y
vector<bool> v2; // / 방향 체크 배열     값 x+y
vector<bool> v3;// \ 방향 체크 배열      값 x-y+n-1

// i == y
//cur == x 
int n;
int cnt;

void func(int cur)
{
	if (n == cur)
	{
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (v1[i] || v2[i + cur] || v3[cur - i + n - 1])
		{

		}
		else
		{
			v1[i] = true;
			v2[i + cur] = true;
			v3[cur - i + n - 1] = true;
			func(cur + 1);
			v1[i] = false;
			v2[i + cur] = false;
			v3[cur - i + n - 1] = false;
		}
	}

}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	v1.resize(n, false);
	v2.resize(2 * n - 1, false);
	v3.resize(2 * n - 1, false);

	func(0);
	cout << cnt;

	return 0;
}