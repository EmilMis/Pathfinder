#include <iostream>
#include <vector>

#define BLOCK 1
#define FREE 0

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

using namespace std;

int m, n;
int maze[100][100];

int visited[100][100] = {};

pair<int, int> startpos;
pair<int, int> endpos;

int main(void) {

	cin >> m >> n;
	for (int i = 0; i < m; i++)for (int j = 0; j < n; j++)cin >> maze[i][j];

	cin >> startpos.first >> startpos.second;
	cin >> endpos.first >> endpos.second;

	vector<vector<int>> stack = { {startpos.first, startpos.second} };
	vector<vector<int>> newstack;
	while (1) {
		newstack = {};
		for (auto pos : stack){
			if (pos[0] == endpos.first && pos[1] == endpos.second) {
				for (int i = 2; i < pos.size(); i++) {
					switch (pos[i]) {
					case UP:
						--startpos.first;
						break;
					case DOWN:
						++startpos.first;
						break;
					case LEFT:
						--startpos.second;
						break;
					case RIGHT:
						++startpos.second;
						break;
					}
					maze[startpos.first][startpos.second] = 2;
				}
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {

						if (maze[i][j] == 2)cout << "\033[31m*\033[0m";
						else if (maze[i][j] == 1)cout << "#";
						else cout << " ";

					}cout << "\n";
				}
				exit(0); 
			}
			if (pos[0] < 0 || pos[0] >= m || pos[1] < 0 || pos[1] >= n || maze[pos[0]][pos[1]] || visited[pos[0]][pos[1]])continue;

			visited[pos[0]][pos[1]] = 1;

			vector<int> pos_1 = pos;
			vector<int> pos_2 = pos;
			vector<int> pos_3 = pos;
			vector<int> pos_4 = pos;

			++pos_1[0];
			--pos_2[0];

			++pos_3[1];
			--pos_4[1];

			pos_1.push_back(DOWN);
			pos_2.push_back(UP);
			pos_3.push_back(RIGHT);
			pos_4.push_back(LEFT);

			newstack.push_back(pos_1);
			newstack.push_back(pos_2);
			newstack.push_back(pos_3);
			newstack.push_back(pos_4);

		}
		stack = newstack;
	}
	cout << "no such path exists"
	return 0;
}
