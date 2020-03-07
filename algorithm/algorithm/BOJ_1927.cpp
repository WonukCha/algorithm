#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

template<class _Ty = void>
struct Notless
	: public binary_function<_Ty, _Ty, bool>
{	// functor for operator<
	bool operator()(const _Ty& _Left, const _Ty& _Right) const
	{	// apply operator< to operands
		return (_Left > _Right);
		//¿©±â ¹Ù²Þ
	}
};

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	priority_queue<int, vector<int>, Notless<int>> pq;
	int nCount;
	cin >> nCount;
	int nInput;
	for (int i = 0; i < nCount;i++)
	{
		cin >> nInput;
		if (nInput == 0)
		{
			if (pq.empty())
			{
				cout << "0\n";
			}
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(nInput);
		}
	}
	return 0;
}