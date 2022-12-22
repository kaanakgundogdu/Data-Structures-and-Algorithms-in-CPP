#include <iostream>
#include <array>


bool one_away_strings(std::string& s1, std::string& s2) {
	int size1 = s1.size();
	int size2 = s2.size();

	if (size1 -size2 > 1 || size2- size1  > 1) {
		return false;
	}
		
	if (s1.size() == s2.size())
	{
		int diff = 0;
		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] !=s2[i])
			{
				diff++;
				if (diff > 1)
					return false;
			}
		}

	}
	else
	{
		int diff = 0;
		int p0 = 0, p1 = 0;

		while (p0<s1.size() && p1<s2.size())
		{
			if (s1[p0] != s2[p1])
			{
				if (s1.size() > s2.size())
					p0++;
				else
					p1++;
				diff++;
				if (diff > 1)
					return false;
			}
			else
			{
				p0++;
				p1++;
			}
		}

		for (int i = 0; i < s1.size(); i++)
		{

		}
	}

	return true;

}

int main()
{
	std::string s1 = "abfdce";
	std::string s2 = "abfde";
	std::cout << one_away_strings(s1,s2) <<"\n";
}
