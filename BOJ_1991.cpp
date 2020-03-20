#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
#include<utility>
#include<stack>
#include<string>
#include<map>
#include<set>

using namespace std;
#define Left_Node 0
#define Right_Node 1
char arrNode[27][2];

void dlr(char Node)
{
	if (Node == 0)
	{
		return;
	}

	cout << (char)(Node + 'A'-1);
	dlr(arrNode[Node][Left_Node]);
	dlr(arrNode[Node][Right_Node]);

}

void ldr(int Node)
{
	if (Node == 0)
	{
		return;
	}
	ldr(arrNode[Node][Left_Node]);
	cout << (char)(Node + 'A' - 1);
	ldr(arrNode[Node][Right_Node]);
}
void lrd(int Node)
{
	if (Node == 0)
	{
		return;
	}
	lrd(arrNode[Node][Left_Node]);
	lrd(arrNode[Node][Right_Node]);
	cout << (char)(Node + 'A' - 1);
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int nLine;
	cin >> nLine;
	for (int i = 0; i < nLine; i++)
	{
		char Par, lc, rc;
		cin >> Par >> lc >> rc;
		if (lc != '.')
			arrNode[Par - 'A' + 1][Left_Node]= lc - 'A' + 1;
		if (rc != '.')
			arrNode[Par - 'A' + 1][Right_Node]=rc - 'A' + 1;
	}
	dlr(1);
	cout << '\n';
	ldr(1);
	cout << '\n';
	lrd(1);
	cout << '\n';

	return 0;
}