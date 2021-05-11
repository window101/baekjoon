#include <iostream>
#include <queue>
#define ABS(x) ((x) > 0 ? (x) : -(x))

using namespace std;

int N, L, R;
int ans = 0;
int visited[50][50];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int space[50][50];
	bool chk = true;
	int ch = 0;
	queue<pair<int, int> > q; // bfs
	queue<pair<int, int> > dq; // 연합 좌표

	cin >> N >> L >> R;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> space[y][x];
		}
	}

	while (chk) {
		++ch;
		//cout << ch << '\n';
		chk = false;
		int sum;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == ch) continue;
				sum = space[i][j];

				q.push({ j, i });
				dq.push({ j, i });
				visited[i][j] = ch;

				while (!q.empty()) { // bfs
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int x_tmp = x + dx[k];
						int y_tmp = y + dy[k];
						if (x_tmp < 0 || y_tmp < 0 || x_tmp >= N || y_tmp >= N || visited[y_tmp][x_tmp] == ch || ABS(space[y][x] - space[y_tmp][x_tmp]) < L || ABS(space[y][x] - space[y_tmp][x_tmp]) > R) {
							continue;
						}
						chk = true;

						q.push({ x_tmp, y_tmp });
						dq.push({ x_tmp, y_tmp });
						sum += space[y_tmp][x_tmp];
						visited[y_tmp][x_tmp] = ch;
					}
				}
				int avg = sum / dq.size();
				while (!dq.empty()) {
					space[dq.front().second][dq.front().first] = avg;
					dq.pop();
				}

			}
		}
	}
	cout << ch - 1 << '\n';
	return 0;
}