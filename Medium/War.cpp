#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;

#define PLAYER_ONE 1
#define PLAYER_TWO 2

string to_str(int val)
{
    ostringstream str;
    str << val;
    return str.str();
}

class Game
{
private:
    int rounds;
    int winner; // 0 - draw
    queue<int> player1;
    queue<int> player2;
    queue<int> pile1;
    queue<int> pile2;
    int getCard(queue<int>* source);
    void collect(queue<int>* dest);
    void battle();
    void war();
public:
    Game() {rounds = 0;};
    int addCard(string, int dest);
    void play();
    bool over();
    string result();

};

int Game::addCard(string card, int dest)
{
    int value;
    if (card.length() == 3)
        value = 10;
    else switch(card[0])
    {
        case 'J' : value = 12; break;
        case 'Q' : value = 13; break;
        case 'K' : value = 14; break;
        case 'A' : value = 15; break;
        default  : value = card[0] - '0';
    }
    if (dest == PLAYER_ONE)
        player1.push(value);
    else
        player2.push(value);
}
void Game::play()
{
    rounds++;
    battle();
}

bool Game::over()
{
    return player1.empty() || player2.empty();
}

string Game::result()
{
    if (winner == 0) return "PAT";
    return (!player1.size() ? "2 " : "1 ") + to_str(rounds);
}
///////////////////////////////////////////////////////

int Game::getCard(queue<int>* dest)
{
    int val = dest->front();
    dest->pop();

    if (dest == &player1)
        pile1.push(val);
    else
        pile2.push(val);

    return val;
}

void Game::collect(queue<int>* dest)
{
    while (!pile1.empty())
    {
        dest->push(pile1.front());
        pile1.pop();
    }

    while (!pile2.empty())
    {
        dest->push(pile2.front());
        pile2.pop();
    }
}

void Game::battle()
{
    int x = getCard(&player1);
    int y = getCard(&player2);

    if (x > y)
        collect(&player1);
    else if (x < y)
        collect(&player2);
    else
        war();
}

void Game::war()
{
    if (player1.size() < 3 || player2.size() < 3)
    {
        winner = 0; // pat;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        getCard(&player1);
        getCard(&player2);
    }
    battle();
}

int main()
{
    Game game;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string input; cin >> input;
        game.addCard(input, PLAYER_ONE);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string input; cin >> input;
        game.addCard(input, PLAYER_TWO);
    }

    while (!game.over())
        game.play();

    cout << game.result() << endl;
}
