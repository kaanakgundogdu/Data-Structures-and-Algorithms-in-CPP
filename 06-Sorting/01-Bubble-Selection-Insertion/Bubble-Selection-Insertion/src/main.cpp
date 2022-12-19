#include <iostream>
#include <vector>

void bubble_sort(std::vector<int> &vec) {
	std::cout << "\nBubble Sort\n";
	int n = vec.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-i; j++)
		{
			if(j+1<n)
				if(vec[j] > vec[j+1])
					std::swap(vec[j], vec[j + 1]);
		}
	}
}

void selection_sort(std::vector<int>& vec) {
	std::cout << "\nselection Sort\n";

	for (int i = 0; i < vec.size(); i++)
	{
		int min_index = i;
		for (int j = i; j < vec.size(); j++)
		{
			if (vec[j]<vec[min_index])
			{
				min_index = j;
			}
		}
		std::swap(vec[i], vec[min_index]);
	}
}


void insertion_sort(std::vector<int>& vec) {
	std::cout << "\ninsertion Sort\n";

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = i; j >-1; j--)
		{
			if (j-1>0)
			{
				if (vec[j - 1] > vec[j])
					std::swap(vec[j - 1], vec[j]);
			}
		}
	}
}

void insertion_sort_second_ver(std::vector<int>& vec) {

	std::cout << "\ninsertion Sort Vol 2\n";

	for (int i = 0; i < vec.size(); i++)
	{
		int temp = vec[i];
		int j = i - 1;
		while (j>0 && vec[i] <= vec[j])
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j+1] = temp;
	}
}

void print_vec(std::vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}

int main()
{
	std::vector<int> v= { 12,3,5,10,8,1 };

	print_vec(v);

	bubble_sort(v);
	print_vec(v);
	selection_sort(v);
	print_vec(v);
	insertion_sort(v);
	print_vec(v);
	insertion_sort_second_ver(v);
	print_vec(v);
    
}
