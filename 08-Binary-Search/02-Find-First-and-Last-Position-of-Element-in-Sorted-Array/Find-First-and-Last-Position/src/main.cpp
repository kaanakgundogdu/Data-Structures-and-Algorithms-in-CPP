#include <iostream>
#include <vector>
#include <array>
#include <cmath>

int binary_search(std::vector<int>& vec, int left_p,int right_p, int target) {

    int mid_p = std::floor((left_p + right_p) / 2);

    if (left_p>right_p)
        return -1;

    if (target == vec[mid_p])
        return mid_p;

    else if (target > vec[mid_p]) {
        int new_left_pivot = mid_p+1;
        int new_right_pivot = right_p;
        return binary_search(vec, new_left_pivot, new_right_pivot, target);
    }
    else {
        int new_left_pivot = left_p;
        int new_right_pivot = mid_p-1;
        return binary_search(vec, new_left_pivot, new_right_pivot, target);
    }
}


std::array<int,2> search_range(std::vector<int>& vec, int target) {
    if (vec.size() == 0)
        return std::array<int, 2> { -1, -1};

    int first_position = binary_search(vec, 0, vec.size() - 1, target);
    if (first_position==-1)
        return std::array<int, 2> { -1, -1};

    int start_pos = first_position;
    int end_pos = first_position;
    int firstpos_holder = start_pos;
    int endpos_holder = end_pos;

    while (start_pos != -1)
    {
        firstpos_holder = start_pos;
        start_pos = binary_search(vec, 0, start_pos - 1, target);
    }
    start_pos = firstpos_holder;

    while (end_pos != -1)
    {
        endpos_holder = end_pos;
        end_pos = binary_search(vec, end_pos+1, vec.size() - 1, target);
    }
    end_pos = endpos_holder;
    return std::array<int, 2>{start_pos, end_pos};
}


int main()
{
    std::vector<int> t1 = { 1,3,3,5,5,5,8,9 };
    std::array<int, 2> a = search_range(t1, 5);
    for (size_t i = 0; i < 2; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Hello World!\n";
   
}
