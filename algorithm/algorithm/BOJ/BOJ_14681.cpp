#include <iostream>

using namespace std;

enum eQuadrant
{
	Quadrant_1 = 1,
	Quadrant_2,
	Quadrant_3,
	Quadrant_4
};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int eResultQuadrant = Quadrant_1;
	int nX, nY;
	cin >> nX >> nY;

	if (nX > 0)
	{
		if (nY > 0)
		{
			eResultQuadrant = Quadrant_1;
		}
		else
		{
			eResultQuadrant = Quadrant_4;
		}
	}
	else
	{
		if (nY > 0)
		{
			eResultQuadrant = Quadrant_2;
		}
		else
		{
			eResultQuadrant = Quadrant_3;
		}
	}

	cout << eResultQuadrant;

	return 0;
}
