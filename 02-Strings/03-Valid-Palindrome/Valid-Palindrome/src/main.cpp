#include <iostream>
#include <string>
#include <algorithm>

bool isNotAlphaNum(char c)
{
    return c == '\'' || !isalpha(c);
}
bool check_sub_pal(std::string& s,int left,int right) {
    while (left < right)
    {
        if (tolower(s[left]) != tolower(s[right]))
            return false;
        
        left++;
        right--;
    }

    return true;
}

bool is_palindrome(std::string& s) {
    //s.erase(std::remove_if(s.begin(), s.end(), isNotAlphaNum), s.end());
    if (s.size() <= 2)
        return true;

    std::string copy_str = s;
    std::reverse(copy_str.begin(), copy_str.end());

    if (copy_str == s)
        return true;

    int left = 0;
    int right = s.size() - 1;

    while (left<right)
    {
        if (tolower(s[left]) != tolower(s[right])) {
            return check_sub_pal(s, left + 1, right) || check_sub_pal(s, left, right - 1);
        }
        left++;
        right--;
    }
    return true;

}



int main(int argc, char* argv[])
{
    std::string s = "racecar";



    std::cout << is_palindrome(s) << std::endl;
    return 0;
}


