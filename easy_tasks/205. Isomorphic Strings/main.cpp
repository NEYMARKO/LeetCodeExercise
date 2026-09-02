#include <unordered_map>
#include <unordered_set>
#include <string>
class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        if (s.length() != t.length())
        {
            return false;
        }
        std::unordered_map<char, char> character_mapping;
        std::unordered_set<char> used_mappings;
        for (int i = 0; i < s.length(); i++)
        {
            auto mapping = character_mapping.find(s[i]);
            // see if this character from string `s` has already been mapped to some other character
            if (mapping != character_mapping.end())
            {
                // if current character from string `s` has already been mapped to character from string `t`, check if it is the same as current character
                if (mapping->second != t[i]) // shouldn't combine with condition above because else branch should only depend on whether mapping exists
                                            // and not on the similarity between mapped value and t[i]
                {
                    return false;
                }
            }
            // no mapping has been found for current character from string `s`
            else
            {
                // check if any character has been mapped to the current character from string `t`
                auto set_find_result = used_mappings.find(t[i]); 
                if (set_find_result == used_mappings.end())
                {
                    used_mappings.insert(t[i]);
                }
                // if this character from string `t` has already been mapped to some character in string `s`, it can't get mapped to current character from string `s` aswell
                else 
                {
                    return false;
                }
                // add mapping
                character_mapping.insert({s[i], t[i]});
            }
        }
        return true;
    }
};


// EXAMPLE: "paper" → "title"
// p → t
// a → i
// e → l
// r → e


// EXAMPLE: "badc" → "baba"
// b → b
// a → a
// d → b  ❌ b is already used by b