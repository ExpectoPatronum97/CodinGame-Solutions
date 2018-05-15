#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    int n, q;
    map<string, string> table;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        string ext, type;
        cin >> ext >> type;
        transform(ext.begin(), ext.end(), ext.begin(), ::toupper);
        table[ext] = type;
    }
    for (int i = 0; i < q; i++)
    {
        string input;
        cin >> input;

        int dot_index = input.rfind('.');

        string temp = input.substr(dot_index+1, input.size());
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);

        if (dot_index != -1)
        {
            auto it = table.find(temp);
            if (it != table.end())
                cout << it->second << endl;
            else
                cout << "UNKNOWN" << endl;
        }
        else cout << "UNKNOWN" << endl;
    }
}
