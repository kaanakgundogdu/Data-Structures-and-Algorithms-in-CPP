#include <iostream>
#include <queue>

#define ROW 4
#define COL 4

int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };

bool isValid(bool vis[][COL], int row, int col)
{
	if (row < 0 || col < 0
		|| row >= ROW || col >= COL)
		return false;
	if (vis[row][col])
		return false;
	return true;
}

void BFS(int grid[][COL], bool vis[][COL], int row, int col)
{
	std::queue<std::pair<int, int> > q;
	q.push({ row, col });
	vis[row][col] = true;

	while (!q.empty()) {

		std::pair<int, int> cell = q.front();
		int x = cell.first;
		int y = cell.second;
		std::cout << grid[x][y] << " ";
		q.pop();
		for (int i = 0; i < 4; i++) {

			int adjx = x + dRow[i];
			int adjy = y + dCol[i];

			if (isValid(vis, adjx, adjy)) {
				q.push({ adjx, adjy });
				vis[adjx][adjy] = true;
			}
		}
	}
}

int main()
{
	int grid[ROW][COL] = { { 1, 2, 3, 4 },
						   { 5, 6, 7, 8 },
						   { 9, 10, 11, 12 },
						   { 13, 14, 15, 16 } };

	bool vis[ROW][COL];
	memset(vis, false, sizeof vis);
	BFS(grid, vis, 0, 0);
	return 0;
}
