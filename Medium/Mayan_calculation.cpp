#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Mayan
{
private:
    int height;
    int length;
    map<string, int> dict;
public:
    Mayan(vector<string>, int, int);
    string encode( long long );
    long long decode( string );
    void print( long long );
};

Mayan::Mayan(vector<string> numerals, int H, int L)
{
    height = H;
    length = L;
    int size = H*L;

    for (int i = 0; i < 20; i++)
    {
        string temp = "";
        for (int j = 0; j < height; j++)
        {
            temp = temp + numerals[j].substr(i*length, length);
        }
        dict[temp] = i;
    }
}

string Mayan::encode(long long num)
{
    string res = "";
    do
    {
        int x = num % 20;
        for (auto it : dict)
            if (it.second == x)
            {
                res = it.first + res;
                break;
            }
        num /= 20;
    } while (num);

    return res;
}

long long Mayan::decode(string num)
{
    long long result = 0, size = length * height;
    int digits = num.length() / (size);

    for (int i = 0; i < digits; i++)
    {
        string temp = num.substr(i*size, size);
        result = result * 20 + dict[temp];
    }

    return result;
}

void Mayan::print(long long num)
{
    string temp = encode(num);
    for (int i = 0; i < temp.length(); i+=length)
    {
        cout << temp.substr(i, length) << endl;
    }
}
int main()
{
    int L, H; cin >> L >> H;
    vector<string> numerals;
    string num1 = "", num2 = "";

    for (int i = 0; i < H; i++)
    {
        string numeral; cin >> numeral;
        numerals.push_back(numeral);
    }


    Mayan mayan = Mayan(numerals, H, L);

    int S1; cin >> S1;
    for (int i = 0; i < S1; i++)
    {
        string num1Line; cin >> num1Line;
        num1 += num1Line;
    }

    int S2; cin >> S2;
    for (int i = 0; i < S2; i++)
    {
        string num2Line; cin >> num2Line;
        num2 += num2Line;
    }

    char operation;
    cin >> operation; cin.ignore();
    switch (operation)
    {
        case '+':
            mayan.print(mayan.decode(num1) + mayan.decode(num2));
            break;
        case '-':
            mayan.print(mayan.decode(num1) - mayan.decode(num2));
            break;
        case '*':
            mayan.print(mayan.decode(num1) * mayan.decode(num2));
            break;
        case '/':
            mayan.print(mayan.decode(num1) / mayan.decode(num2));
            break;

    }
    return 0;
}
