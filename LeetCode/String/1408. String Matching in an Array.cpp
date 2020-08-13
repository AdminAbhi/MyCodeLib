class Solution {
public:
    static bool compFunc(const string &a, const string &b)
    {
        return a.size() < b.size();
    }
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), compFunc);
        vector<string> res;
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = i + 1; j < words.size(); j++)
            {
                if(words[j].find(words[i]) != -1)
                {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};
