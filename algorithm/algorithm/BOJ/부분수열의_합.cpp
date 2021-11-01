#include<iostream>

#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<utility>

using namespace std;
int n, s;
int cnt = 0;
int a[24];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i < (1 << n); i++){ 
		int tmp = i;
		int tot = 0;
		for (int j = 0; j < n; j++){
			if (tmp % 2 == 1)
			{
				tot += a[j];
			}
			tmp /= 2;
		}
		if (tot == s) cnt++;
	}
	cout << cnt;
}