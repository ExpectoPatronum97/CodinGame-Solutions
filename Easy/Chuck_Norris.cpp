#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string D2B(int number)
{
    string rez = "";
    do
    {
        if ( (number & 1) == 0 )
            rez += "0";
        else
            rez += "1";

        number >>= 1;
    }while ( number );
    for (int i = rez.size(); i < 7; i++)
        rez += "0";
    reverse(rez.begin(), rez.end());
    return rez;
}

int main()
{
    string MESSAGE;
    string binarno;
    string final;
    int nulacnt = 0;
    int jedancnt = 0;
    getline(cin, MESSAGE);
    for (int i = 0; i < MESSAGE.size(); i++)binarno += D2B(MESSAGE[i]);
    int i = 0;
    while (i < binarno.size())
    {
        while(binarno [i] == '1')
        {
            i++;
            jedancnt++;
        }
        while(binarno [i] == '0')
        {
            i++;
            nulacnt++;
        }
        if (jedancnt)
        {
            final += " 0 ";
            for (int temp = 0; temp < jedancnt; temp++)
                final += "0";
        }
        if (nulacnt)
        {
            final += " 00 ";
            for (int temp = 0; temp < nulacnt; temp++)
                final += "0";
        }
        nulacnt = 0;
        jedancnt = 0;
    }
    for (int i = 1; i < final.size(); i++)
         cout << final[i];
}
