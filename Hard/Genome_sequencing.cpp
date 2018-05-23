#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string lap(string a, string b)
{
    string res = a;
    if (a.find(b) == -1)
    {
        int len = min(a.length(), b.length());
        bool found = false;
        while(len && !found)
        {
            if (a.substr(a.length() - len) == b.substr(0, len))
            {
                res = a + b.substr(len);
                found = true;
            }
            len--;
        }
        if (!found) res = res + b;
    }

    return res;
}

string superstring(vector<string> words)
{
    string res = "";
    for (auto word: words)
        res = lap(res, word);
    return res;
}

int main()
{
    int n; cin >> n;
    vector<string> words;
    while (n--)
    {
        string temp; cin >> temp;
        words.push_back(temp);
    }

    sort(words.begin(), words.end());
    int shortest = 1<<30;

    do
    {
        string temp = superstring(words);
        if (temp.length() < shortest)
        {
            shortest = temp.length();
        }
    }
    while (next_permutation(words.begin(), words.end()));
    cout << shortest << endl;
    return 0;
}
