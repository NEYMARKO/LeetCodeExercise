#include <string>
class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int orig_idx = t.length() - 1;
        int subs_idx = s.length() - 1;
        if (s.length() == 0)
        {
            return true;
        }
        while (orig_idx >= 0)
        {
            if (t[orig_idx] == s[subs_idx])
            {
                subs_idx--;
                if (subs_idx == -1)
                {
                    break;
                }
            }
            orig_idx--;
        }
        return subs_idx == -1;
    }
};