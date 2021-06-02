#include <iostream>
#include <iomanip>
#include <list>
#include <algorithm>
#include <cctype>
#include <cassert>
#include <cstring>
#include <string>

using namespace std;

void ruler()
{
    for (int i = 0; i < 30; i++)
        cout << "-";
    cout << endl;
}

class Song
{

public:
    Song() = default;

    Song(string str, string str1, int num)
        : name{str}, singer{str1}, ranking{num}
    {
    }

    void einlesen(istream &is)
    {
        cout << "The name of the song: " << endl;
        int count = 1;
        while (count != 3)
        {
            getline(is, name);
            count++;
        }
        cout << endl;
        cout << "The singer/band: " << endl;
        getline(is, singer);
        cout << endl;
        cout << "The ranking(1-5): " << endl;
        is >> ranking;
        if (ranking < 1 || ranking > 5)
        {
            cerr << "Ranking must be between 1-5 . " << ranking << " is not permitted!" << endl;
        }
    }

    void ausgeben(ostream &os) const
    {
        os << setw(30) << left << name << setw(25) << left << singer << setw(25) << right << ranking << endl;
    }

    bool operator<(const Song &rhs) const
    {
        return (this->name < rhs.name);
    }

    bool operator==(const Song &rhs) const
    {
        return (this->name == rhs.name);
    }

private:
    string name;
    string singer;
    int ranking;
};

ostream &operator<<(ostream &os, const Song &s)
{
    s.ausgeben(os);
    return os;
}

istream &operator>>(istream &is, Song &s)
{
    s.einlesen(is);
    return is;
}

void display(list<Song> &l)
{
    ruler();
    auto it = l.begin();
    while (it != l.end())
        cout << *(it++) << endl;
    ruler();
}

void add_song(list<Song>::iterator it, list<Song> &l)
{
    Song temp;
    cin >> temp;
    l.insert(it, temp);
}

void erase_song(list<Song>::iterator it, list<Song> &l)
{
    l.erase(--it);
}

int main()
{

    list<Song> l;

    Song s1("Old Town Road", "Lil Nas X", 5);
    Song s2("Guelpembe", "Baris Manco", 5);
    Song s3("Somewhere I Belong", "Linkin Park", 5);
    Song s4("Belalim", "Sezen Aksu", 5);
    Song s5("Elfida", "Haluk Levent", 5);

    l = {s1, s2, s3, s4, s5};

    char ch[20], c;
    list<Song>::iterator it = l.begin();

    list<Song>::iterator it1 = l.end();
    it1--;

    do
    {

        cout << "What do you want to do?" << endl
             << endl
             << "F: Play first song" << endl
             << "N: Play next song" << endl
             << "P: Play previous song" << endl
             << "A: Add and play a new song at current location" << endl
             << "E: Erase the song at your current location" << endl
             << "L: List the current playlist" << endl
             << endl;

        cin >> ch;

        if (strlen(ch) == 1)
        {
            c = ch[0];
            c = toupper(c);

            switch (c)
            {
            case 'F':
                cout << *it << endl;
                break;
            case 'N':
                if (it == it1)
                {
                    it = l.begin();
                    cout << *it << endl;
                }
                else
                    cout << *(++it) << endl;
                break;
            case 'P':
                if (it == l.begin())
                    it = l.end();
                cout << *(--it) << endl;
                break;
            case 'A':
                add_song(it, l);
                break;
            case 'E':
                erase_song(it, l);
                break;
            case 'L':
                display(l);
                break;
            case 'Q':
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "This character isn't permitted!" << endl;
                break;
            }
        }
        else
            cout << "Invalid input" << endl;

    } while (c != 'Q');

    return 0;
}