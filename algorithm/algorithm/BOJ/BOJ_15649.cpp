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
	int n, m;
	cin >> n >> m;

	int size = 0;
	vector<bool> arrCheckNum(n,false);
	vector<int> arrOutputNum(m,-1);
	for (int i = 0; i < n; i++)
	{
		arrCheckNum[i] = true;
		arrOutputNum[0] = i;
	}
}