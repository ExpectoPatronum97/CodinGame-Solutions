#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int seats, daily_rides, N;
    cin >> seats >> daily_rides >> N;

    struct Group {int count, next_group, money;};
    vector<Group> people;

    for (int i = 0; i < N; i++)
    {
        int Pi; cin >> Pi;
        people.push_back({Pi,-1,0});
    }

    long long money = 0;
    int curr_group = 0;

    while(daily_rides--)
    {
        if (people[curr_group].next_group != -1)
        {
            money += people[curr_group].money;
            curr_group = people[curr_group].next_group;
        }
        else
        {
            int new_money = 0;
            int start_index = curr_group;
            int seats_left = seats;

            while (seats_left >= people[curr_group].count)
            {
                seats_left -= people[curr_group].count;
                new_money += people[curr_group].count;
                curr_group = (++curr_group) % N;
                if (start_index == curr_group) break;
            }
            people[start_index].next_group = curr_group;
            people[start_index].money = new_money;
            money += new_money;
        }
    }
    cout << money << endl;
    return 0;
}
