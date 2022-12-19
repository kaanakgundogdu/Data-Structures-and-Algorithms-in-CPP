#include <iostream>
#include <vector>
#include <cmath>

void merge_sort(std::vector<int>& vec);
void merge_arrays(std::vector<int>& vec,std::vector<int> &left, std::vector<int> &right);
void printArray(std::vector<int>& vec);

int main()
{
	std::vector<int> vec = { 12, 11, 13, 5, 6, 7 };

	std::cout << "Given array is";
	printArray(vec);

	merge_sort(vec);

	std::cout << "\nSorted array is";
	printArray(vec);
	std::cout << "Hello World!\n";
}

void printArray(std::vector<int>& vec)
{
	std::cout << "\n";
	for (auto i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << "\n";
}

void merge_sort(std::vector<int> &vec) {
	if (vec.size() == 1) 
		return;

	std::vector<int> left;
	std::vector<int> right;

	int mid_p = std::floor(vec.size() / 2);

	for (int i = 0; i < mid_p; i++)
		left.push_back(vec[i]);

	for (int i = vec.size()-1; i >= mid_p; i--)
		right.push_back(vec[i]);

	merge_sort(left);
	merge_sort(right);
	merge_arrays(vec,left, right);
}

void merge_arrays(std::vector<int> &vec,std::vector<int> &left, std::vector<int> &right) {
	
	int left_index = 0;
	int right_index = 0;
	int main_vector_index = 0;

	while (left_index< left.size() && right_index < right.size())
	{
		if (left[left_index] < right[right_index])
		{
			vec[main_vector_index]=left[left_index];
			left_index++;
		}
		else 
		{
			vec[main_vector_index] = right[right_index];
			right_index++;
		}
		main_vector_index++;
	}
	//For remainings
	while (left_index < left.size()) {
		vec[main_vector_index] = left[left_index];
		left_index++;
		main_vector_index++;
	}
	while (right_index < right.size()) {
		vec[main_vector_index] = right[right_index];
		right_index++;
		main_vector_index++;
	}
}




