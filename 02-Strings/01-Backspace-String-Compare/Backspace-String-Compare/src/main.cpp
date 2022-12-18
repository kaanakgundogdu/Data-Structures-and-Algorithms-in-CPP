#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


bool is_equal(std::string &s1,std::string &s2) {
    
    std::vector<char> string_first{};
    std::vector<char> string_second{};
    char bs = '#';

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == bs ) {
            if (string_first.size() > 0)
                string_first.pop_back();
        }
        else 
            string_first.push_back(s1[i]);
    }

    for (int i = 0; i < s2.length(); i++)
    {
        if (s2[i] == bs) {
            if(string_second.size()>0)
                string_second.pop_back();
        }
        else
            string_second.push_back(s2[i]);
    }

    if (string_first == string_second)
        return true;

    return false;

}



int main()
{
    std::string a = "bxj##tw";
    std::string b = "bxj##tw";


    std::cout << is_equal(a,b) << "\n";

    std::cout << "Hello World!\n";
}





/*
bool is_equal_optimal(std::string& s, std::string& t) {

    int point_1 = s.length() -1;
    int point_2 = t.length() -1;

    while (point_1>-1 || point_2>-1)
    {

        if (s[point_1]=='#' || t[point_2] == '#') {
            if (s[point_1] == '#') {
                int counter = 2;
                while (counter>0)
                {
                    point_1--;
                    if (point_1 < 0)
                        break;


                    counter--;
                    if (s[point_1] == '#') {
                        counter+=2;
                    }
                }
            }
            if (t[point_2] == '#') {
                int counter = 2;
                while (counter > 0)
                {
                    point_2--;
                    if (point_2 < 0)
                        break;

                    counter--;
                    if (t[point_2] == '#') {
                        counter += 2;
                    }
                }
            }

        }
        else {
            if (point_1 < 0 && point_2 < 0)
                break;
            if (point_1 < 0 || point_2 < 0)
                return false;
            if (s[point_1] != t[point_2])
                return false;

            point_1--;
            point_2--;
        }

    }

    return true;
}
*/