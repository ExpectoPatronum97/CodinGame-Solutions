#include <iostream>
using namespace std;

struct Trie
{
    struct Trie* children[10];
    Trie()
    {
        for (int i = 0; i < 10; i++)
            this->children[i] = NULL;
    }
    ~Trie()
    {
        for (int i = 0; i < 10; i++)
            delete this->children[i];
    }
};

int main()
{
    // solution: number of nodes in a trie
    Trie *root = new Trie;
    int n, result = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string number;
        cin >> number;

        Trie* temp = root;
        for (char c : number)
        {
            if (temp->children[c-'0'] == NULL)
            {
                temp->children[c-'0'] = new Trie;
                result++;
            }
            temp = temp->children[c-'0'];
        }
    }
    delete root;
    cout << result << endl;
    return 0;
}
