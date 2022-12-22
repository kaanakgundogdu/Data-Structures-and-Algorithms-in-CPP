#include <iostream>
#include <string>
#include <vector>


class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string answer = "";
        if (strs.size() < 1)
            return answer;

        for (int i = 0; i < strs[0].size(); i++)
        {
            for(auto s: strs)
            {
                if (i > s.size()-1 || s[i] != strs[0][i])
                    return answer;
            }
            answer += strs[0][i];
        }

        return answer;
    }
};


int main()
{
    std::vector<std::string> strs = { "flower", "flow", "flight" };
    Solution s;
    

    std::cout << s.longestCommonPrefix(strs) << "\n";
}
