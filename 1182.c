#include <iostream>
using namespace std;
int n, ret;
int arr[20];
int cnt;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> ret;
	for (int i = 0; i < n; i++) { cin >> arr[i]; }
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j) ) {
				sum += arr[j];
			}
		}
		if (sum == ret) { ++cnt; }
	}
	cout << cnt << '\n';
	return 0;
}