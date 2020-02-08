#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<utility>


using namespace std;

typedef long long ll;

int result;
void fnc(int a, int b, int c)
{
	if (a == 1)
	{
		return;
	}

	int temp = a / 2;
	int nemo = temp*temp;

	if (b >= a / 2 && c >= a / 2)
	{
		//down, right
		result += nemo * 3;
		return fnc(a / 2, b - temp, c - temp);
	}
	else if (b < a / 2 && c >= a / 2)
	{
		//up right
		result += nemo * 1;
		return fnc(a / 2, b, c - temp);

	}
	else if (b >= a / 2 && c < a / 2)
	{
		//down lift
		result += nemo * 2;
		return fnc(a / 2, b - temp, c);

	}
	else if (b < a / 2 && c < a / 2)
	{
		//up lift
		result;
		return fnc(a / 2, b, c);

	}
}


int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int size, r, c;
	cin >> size;
	cin >> r >> c;

	size = 1 << size;
	fnc(size, r, c);

	cout << result;
}