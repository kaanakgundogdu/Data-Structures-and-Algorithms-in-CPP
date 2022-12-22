#include <iostream>

template<size_t SIZE1, size_t SIZE2>
bool check_rotation(const int(&arr1)[SIZE1], const int(&arr2)[SIZE2]) {
	int arr1_index = 0;
	int arr2_index = -1;
	if (SIZE1 != SIZE2)
		return false;

	for (int i = 0; i < SIZE2; i++)
	{
		if (arr1[arr1_index] == arr2[i])
		{
			arr2_index = i;
			break;
		}
	}
	if (arr2_index < 0)
		return false;

	for (int a = 0; a < SIZE1; a++)
	{
		int b = (arr2_index + a) % SIZE1;
		if (arr1[a] != arr2[b])
			return false;
	}

	return true;
}

int main()
{
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7 };
	int arr2[] = { 4, 5, 6, 7, 1, 2, 3 };
	std::cout << check_rotation(arr1, arr2) << "\n";
}
