#include <iostream>
#include <array>
#include <map>

void find_most_occuring_item(int *arr, int size) {

    std::map<int, int> occ;
    int max_occ = -1;
    int max_item = -1;
    if (size<1)
    {
        std::cout << max_item << " , " << max_occ << "\n";
        return;
    }
    for (int i = 0; i < size; i++)
    {
        if (occ.count(arr[i]) > 0) 
            occ[arr[i]]++;
        else
            occ[arr[i]] = 1;

        if (occ[arr[i]]> max_occ)
        {
            max_occ = occ[arr[i]];
            max_item = arr[i];
        }
    }

    std::cout << max_item <<" , "<<max_occ << "\n";

}

int main()
{
    int arr[1];
    find_most_occuring_item(arr, 0);
}
