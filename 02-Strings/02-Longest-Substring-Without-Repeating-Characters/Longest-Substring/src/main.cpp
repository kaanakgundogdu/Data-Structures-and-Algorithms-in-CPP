#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int longest_substring(std::string &s){
	std::map<char, bool> my_map{};
	int max_subs = 0;
	int longest = 0;
	if (s.size() <= 1)
		return s.size();

	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i; j < s.size(); j++)
		{
			if (my_map[s[j]] == true) {
				if (longest > max_subs) {
					max_subs = longest;
				}
				my_map.clear();
				longest = 0;
				break;
			}
			else {
				my_map[s[j]] = true;
				longest++;
			}

			
		}
	}
	return max_subs;
}

int longest_substring_better(std::string& s) {
	if (s.size() <= 1)
		return s.size();

	std::map<char, int> my_map{};
	int max_subs = 0;
	int p0 = 0;
	int p1 = 0;

	for (p1 = 0; p1 < s.size(); p1++)
	{
		if (my_map.count(s[p1])>0) {
			if (my_map[s[p1]] >= p0) {
				p0 = my_map[s[p1]] + 1;
			}
		}
		my_map[s[p1]] = p1;
		max_subs = std::max(max_subs, p1 - p0 + 1);
	}
	return max_subs;
}



int main()
{
	std::string t1 = "au";
	std::cout << longest_substring_better(t1) << "\n";
    std::cout << "Hello World!\n";
}
