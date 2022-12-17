#include <iostream>
#include <vector>
#include <algorithm>


int calc_container(std::vector<int> &vec) {

    int w = 0;
    int h = 0;
    int max_area = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i+1; j < vec.size(); j++)
        {
            h = std::min(vec[i], vec[j]);
            w = j - i;
            int area = w * h;
            max_area=std::max(max_area, area);
        }
    }
    return max_area;
}

int calc_better(std::vector<int>& vec) {
    int w = 0;
    int h = 0;
    int max_area = 0;
    int p0 = 0;
    int p1 = vec.size() - 1;


    for (int i = 0; i < vec.size(); i++) {

        h = std::min(vec[p0], vec[p1]);
        w = p1 - p0;
        int area = w * h;
        max_area = std::max(max_area, area);

        if (vec[p0] < vec[p1]) {
            p0++;
        }else{
            p1--;
        }
    }

    return max_area;
}

int main()
{
    std::vector<int> a{ 1,8,6,2,9,4 };
    std::vector<int> b{ 7,1,2,3,9};
    std::vector<int> c{ 4 };

    //std::cout << calc_container(a) << "\n";
    //std::cout << calc_container(b) << "\n";

    std::cout << calc_better(a) << "\n";
    std::cout << calc_better(c) << "\n";

    std::cout << "Hello World!\n";
}
