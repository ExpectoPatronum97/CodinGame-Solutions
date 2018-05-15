#include <iostream>
#include <string>

using namespace std;

int main()
{
    int L;
    int H;
    string T;
    cin >> L; cin.ignore();
    cin >> H; cin.ignore();
    getline(cin, T);
    for (int i = 0; i < H; i++)
    {
        string ROW;
        getline(cin, ROW);

        for (char c : T)
        {
            int index = 26; // question mark
            if (c >= 'a' && c <='z')
                index = c - 'a';
            else if (c >= 'A' && c <= 'Z')
                index = c - 'A';
            cout << ROW.substr(L * index, L);
        }
        cout << endl;
    }
}
