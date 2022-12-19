#include <iostream>
#include <vector>

int partition(std::vector<int>& vec, int start, int end) {
    int new_pivot = end;
    int check_index = start;

    for (int i = start; i < end; i++)
    {
        if (vec[i] < vec[new_pivot])
        {
            std::swap(vec[i], vec[check_index]);
            check_index++;
        }
    }
    std::swap(vec[check_index], vec[new_pivot]);
    return check_index;

}

void quick_select(std::vector<int>& vec, int start_p, int end_p, int k) {

    if (start_p < end_p)
    {
        int pivot = partition(vec, start_p, end_p);
        if (k == pivot)
            return;
        else if (k > pivot)
            quick_select(vec, pivot + 1, end_p, k);
        else
            quick_select(vec, start_p, pivot - 1, k);

    }
}

int findKthLargest(std::vector<int>& nums, int k) {
	int id = nums.size() - k;
    quick_select(nums, 0, nums.size() - 1, id);
	return nums[nums.size() - k];
}

int main()
{
	std::vector<int> vec = { 3,2,1,5,6,4 };
	std::cout << findKthLargest(vec, 2) << "\n";
}
