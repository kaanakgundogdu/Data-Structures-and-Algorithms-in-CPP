#include <iostream>
#include <vector>
#include <array>

void print_vec(std::vector<std::vector<int>>& vec);

void mine_sweeper(std::vector<std::vector<int>>& bombs, int row_count, int column_count) {

    std::vector<std::vector<int>> mines(row_count, std::vector<int>(column_count));
	print_vec(mines);
	for (int i = 0; i < bombs.size(); i++)
	{
		int row_b = bombs[i][0];
		int col_b = bombs[i][1];
		mines[row_b][col_b] = -1;

		for (int a = row_b - 1; a < row_b+2; a++)
		{
			for (int b = col_b - 1; b < col_b + 2; b++) {
				if (a>-1 && a<row_count  && b>-1 && b<column_count && mines[a][b] !=-1 )
				{
					mines[a][b] += 1;
				}
			}
		}

	}
	print_vec(mines);
}

void print_vec(std::vector<std::vector<int>>& vec){
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
    std::vector< std::vector<int>> bombs = { {0,0},{0,1} };
    mine_sweeper(bombs,3,4);
}
