#include <iostream>
#include <vector>

#define limit 100
#define block '#'
#define pos pair<int, int>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define UP_CH '^'
#define DOWN_CH 'v'
#define LEFT_CH '<'
#define RIGHT_CH '>'

using namespace std;

int maze[limit][limit] = {};
int n, m;

int startx, starty;
int endx, endy;

int visited[limit][limit] = {};

char ch[4] = {UP_CH, DOWN_CH, LEFT_CH, RIGHT_CH};

//recursive function...
void find(pos current, pos desired, vector<int> path) {

	//to prevent stack overflow...
	if (visited[current.first][current.second])return;
	visited[current.first][current.second] = 1;

	if (current.first < 0 || current.first >= n || current.second < 0 || current.second >= m)return;
	if (maze[current.first][current.second])return;

	if (current == desired) {
		//we found it!
		
		for (auto dir : path) {
			maze[startx][starty] = ch[dir];
			switch (dir) {
			case UP:
				startx--;
				break;
			case DOWN:
				startx++;
				break;
			case LEFT:
				starty--;
				break;
			case RIGHT:
				starty++;
				break;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				switch (maze[i][j]) {
				case 1:
					cout << '#';
					break;
				case 0:
					cout << '.';
					break;
				default:
					cout << char(maze[i][j]);
				}
			}
			cout << "\n";
		}
		exit(0);
	}

	//DOWN...
	vector<int> copyDOWN = path;
	copyDOWN.push_back(DOWN);
	find({ current.first + 1, current.second }, desired, copyDOWN);

	//RIGHT...
	vector<int> copyRIGHT = path;
	copyRIGHT.push_back(RIGHT);
	find({ current.first, current.second + 1 }, desired, copyRIGHT);

	//UP...
	vector<int> copyUP = path;
	copyUP.push_back(UP);
	find({ current.first - 1, current.second }, desired, copyUP);

	//LEFT...
	vector<int> copyLEFT = path;
	copyLEFT.push_back(LEFT);
	find({ current.first, current.second - 1 }, desired, copyLEFT);
}

int main(void) {

	//get user input...
	cout << "enter dimensions > ";
	cin >> n >> m;

	cout << "enter maze...\n";
	char in;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> in;
			maze[i][j] = (in == block ? 1:0);
		}
	}

	cout << "enter start pos > ";
	cin >> startx >> starty;
	startx--; starty--;

	cout << "enter end pos > ";
	cin >> endx >> endy;
	endx--; endy--;

	find({ startx, starty }, { endy, endx }, {});
	cout << "no such path exists...";
}
