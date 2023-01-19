#include <iostream>
#include <array>
#include <vector>

template<std::size_t SIZE1, std::size_t SIZE2>
std::vector<int> check_common_elements(std::array<int, SIZE1>& arr1, std::array<int, SIZE2>& arr2) {
    int p0=0, p1 = 0;
    std::vector<int> commons;

    while (p0<SIZE1 && p1<SIZE2)
    {
        if (arr1[p0] == arr2[p1])
        {
            commons.push_back(arr1[p0]);
            p0++;
            p1++;
        }
        else
        {
            if (arr1[p0] > arr2[p1])
                p1++;
            else
                p0++;
        }
    }
    return commons;
}

void print_vec(const std::vector<int>& vec) {
    std::cout << "\n[";

    for (auto el : vec) {
        std::cout << el << " ";
    }
    std::cout <<"]\n";
}


int main()
{
    std::array<int, 6> arr1{1,3,4,6,7,9};
    std::array<int, 6> arr2{1,2,4,5,9,10};
    print_vec(check_common_elements(arr1, arr2));
    int a;
    std::cin>>a;
}
