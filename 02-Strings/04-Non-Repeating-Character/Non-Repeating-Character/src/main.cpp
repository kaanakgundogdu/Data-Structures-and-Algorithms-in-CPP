#include <iostream>
#include <string>
#include <map>


char non_repeating_char(std::string &s) {

	std::map<char, int> chars_in_str;

	for (int i = 0; i < s.size(); i++)
	{
		if (chars_in_str.count(s[i]))
			chars_in_str[s[i]]++;
		else
		{
			chars_in_str[s[i]] = 1;
		}
	}

	for (auto it = chars_in_str.begin(); it != chars_in_str.end(); it++)
	{
		if (it->second==1)
		{
			return it->first;
		}
	}

	return NULL;

}

int main()
{
	std::string s = "aabbcddaa";

    std::cout << non_repeating_char(s) << "\n";
}
