#include <iostream>
#include <vector>

using namespace std;

vector<int> odredi(vector<int> trenutni)
{
    int sz = trenutni.size();
    vector<int> new_vector;
    for (int i = 0; i < sz; i++)
    {
        int j = i+1, counter = 1;
        while (j < sz && trenutni[i] == trenutni[j])
        {
            counter++;
            j++;
            i++;
        }
        new_vector.push_back(counter);
        new_vector.push_back(trenutni[i]);
    }
    return new_vector;
}
int main()
{
    int R, L;
    cin >> R >> L;

    vector<int> elems;
    elems.push_back(R);
    for (int i = 1; i < L; i++) elems = odredi(elems);

    int sz = elems.size();
    for (int i = 0; i < sz; i++)
        cout << elems[i] << (i==sz-1?"\n":" ");
    return 0;
}
