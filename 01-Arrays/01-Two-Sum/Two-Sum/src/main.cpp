#include <iostream>
#include <array>
#include <map>

template<std::size_t SIZE>
std::array<int, 2> two_sum(std::array<int, SIZE>& arr, const int target) {  
    std::map<int, int> search_map{};

    std::array<int, 2> answer{ NULL,NULL };

    for (int p0 = 0; p0 < SIZE; p0++) {

        int a = target - arr[p0];
        if (search_map.count(arr[p0])!=0) {
            return std::array<int, 2>{search_map[arr[p0]], p0};
        }
        else {
            search_map.insert({ a, p0 });
        }
    }

    return std::array<int, 2>{NULL, NULL};
}

template <std::size_t N>
std::ostream& operator<<(std::ostream& os, std::array<int, N> const& v1)
{
    //for_each(begin(v1), end(v1), [&os](int val) {os << val << " "; });
    std::cout << "[ ";
    for (int x : v1)
        std::cout << x << " ";
    std::cout << "]";
    return os;
}

int main()
{
    std::cout << "Hello World!\n";
    std::array<int, 5> a = { 1, 3, 7, 9, 2 };
    std::array<int, 3> b = { 3,2,3 };

    auto q= two_sum(b,6);

    if (q[0] == NULL && q[1] == NULL)
        std::cout << "Null" << std::endl;
    
    else 
        std::cout << q << std::endl;
        

    

    return 0;
}
