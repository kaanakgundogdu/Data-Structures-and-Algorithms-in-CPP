#include <iostream>
#include <string>
#include <stack>
#include <map>


bool is_valid(std::string &s) {
    std::map<char, char> pars = { {'(',')' },{'{','}' },{'[',']' }};
    std::stack<char> chars;

    for (int i = 0; i < s.size(); i++)
    {
        if (pars.count(s[i])>0) {
            chars.push(s[i]);
        }
        else{
            if (chars.size() == 0)
                return false;
            char left_b = chars.top();
            char correct_b = pars[left_b];
            if (s[i] == correct_b)
                chars.pop();
            else
                return false;
        }
    }
    return chars.size() == 0;

}

int main()
{
    std::string s = "()";
    std::cout << is_valid(s);
}
