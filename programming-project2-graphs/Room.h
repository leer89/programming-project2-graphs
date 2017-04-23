#include <string>
using namespace std;

class Room
{
public:
    Room();
    Room(char newroom);
    char get_name() const;
    Room *get_adjacent_room(char direction) const;
    void link_room(char direction, Room *other);
    string get_available_directions();
private:
    char name;
    Room *north, *west, *south, *east;
};