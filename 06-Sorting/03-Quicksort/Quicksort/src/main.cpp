#include <iostream>
#include <vector>

int partition(std::vector<int>& vec, int start, int end) {

	int pivot = end;
	int j = start;
	for (int i = start; i < end; ++i) {
		if (vec[i] < vec[pivot]) {
			std::swap(vec[i], vec[j]);
			++j;
		}
	}
	std::swap(vec[j], vec[pivot]);
	return j;
}

void quicksort(std::vector<int>& vec, int start, int end) {

	if (start < end) {
		int pivot = partition(vec, start, end);
		quicksort(vec, start, pivot - 1);
		quicksort(vec, pivot + 1, end);
	}

}

void print_vector(std::vector<int> vec) {
	std::cout << "\n";
	for (int i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << "\n\n";
}

int main()
{
    std::vector<int> v = { 1 , 10 , 11 , 9 , 14 , 3 , 2 , 20 , 19 };
	print_vector(v);
	quicksort(v, 0, v.size() - 1);
	print_vector(v);
}
