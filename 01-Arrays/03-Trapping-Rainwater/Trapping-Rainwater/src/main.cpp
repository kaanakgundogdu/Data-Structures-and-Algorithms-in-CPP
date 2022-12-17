#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int calculate_rainwater_bad_code(std::vector<int> &vec) {
	int sum = 0;
	int max_left = 0;
	int max_right = 0;


	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = i; j < vec.size(); j++)
		{
			if (vec[j] > max_right)
				max_right = vec[j];
		}

		for (int j = i; j >=0; j--)
		{
			if (vec[j] > max_left)
				max_left = vec[j];
		}

		int cur_val = std::min(max_left, max_right) - vec[i];
		if (cur_val > 0)
			sum += cur_val;
		max_right = 0;
		max_left = 0;
	}
	return sum;
}

int calculate_rainwater_optimal(std::vector<int> height) {
	int sum = 0;

	int max_left = 0;
	int max_right = 0;
	int right_point = height.size() - 1;
	int left_point = 0;


	while (left_point < right_point) {
		if (height[left_point] < height[right_point]) {
			if (height[left_point] > max_left)
				max_left = height[left_point];
			else
				sum += max_left - height[left_point];

			left_point++;
		}
		else {
			if (height[right_point] > max_right)
				max_right = height[right_point];
			else
				sum += max_right - height[right_point];

			right_point--;
		}
	}

	return sum;
}


int main()
{

	std::vector<int> test1{ 0,1,0,2,1,0,3,1,0,1,2 };
	std::vector<int> test2{};
	std::vector<int> test3{5};
	std::vector<int> test4{ 5,0,3,0,0,0,2,3,4,2,1};


	std::cout<< calculate_rainwater_optimal(test1)<<"\n";
	std::cout << calculate_rainwater_optimal(test2) << "\n";
	std::cout << calculate_rainwater_optimal(test3) << "\n";
	std::cout << calculate_rainwater_optimal(test4) << "\n";


    std::cout << "Hello World!\n";
}
