#include <iostream>
#include <vector>
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


int main()
{
    std::vector<int> t1 = { 1,2,3,4,5,6,7,8 };
    std::cout << binary_search(t1,0,t1.size()-1,4)<< "\n";
    std::cout << "Hello World!\n";
}
