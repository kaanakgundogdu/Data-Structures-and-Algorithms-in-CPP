#include <iostream>
#include <vector>
#include <array>
#include <queue>


void print_vec(std::vector<std::vector<int>>& vec);

std::vector<std::vector<int>> mine_sweeper(std::vector<std::vector<int>>& mines, int row_count, int column_count,int clicked_x,int clicked_y) {

	print_vec(mines);

	std::queue<std::vector<int>> q;
	if (mines[clicked_x][clicked_y]==0)
	{
		std::vector<int> x = { clicked_x, clicked_y };
		q.push(x);
		mines[clicked_x][clicked_y] = -2;
	}
	else
		return mines;

	while (!q.empty())
	{

		std::vector<int> a = q.front();
		q.pop();
		int current_i = a[0];
		int current_j = a[1];

		for (int i = current_i-1; i < current_i +2; i++)
		{
			for (int j = current_j - 1; j < current_j + 2; j++) {
				if (i > -1 && i<row_count && j>-1 && j < column_count ) {
					if (mines[i][j] == 0)
					{
						mines[i][j] = -2;
						std::vector<int> x = { i, j };
						q.push(x);
					}
					
				}
			}
		}
	}

	print_vec(mines);
	return mines;
}

void print_vec(std::vector<std::vector<int>>& vec) {
	std::cout << "\n";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << "    ";
		for (int j = 0; j < vec[i].size(); j++)
		{
			std::cout << vec[i][j] << "   ";
		}
		std::cout << "\n";
	}
}

int main()
{
	std::vector<std::vector<int>> mines = { {-1,1,0,0},
											{1,1,0,0},
											{0,0,1,1},
											{0,0,1,-1}};

	mine_sweeper(mines, 4, 4,1,2);
}