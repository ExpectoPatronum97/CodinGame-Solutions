#include <iostream>
using namespace std;

int score(string word, int *vals)
{
    int points = 0;
    for (int i = 0; word[i]; i++)
        points += vals[word[i]-'a'];
    return points;
}
int main()
{
    int vals[26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    int n; cin >> n;
    string words[n], letters, word;
    for (int i = 0; i < n; i++)
        cin >> words[i];
    cin >> letters;

    int best = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0, ind;
        string letters_copy = letters;
        for (auto c: words[i])
        {
            if ((ind = letters_copy.find(c)) != -1)
            {
                letters_copy.erase(ind, 1);
                count++;
            }
        }
        if (count == words[i].length())
        {
            if (score(words[i], vals) > best)
                best = score(words[i], vals), word = words[i];
        }
    }
    cout << word << endl;
    return 0;
}

