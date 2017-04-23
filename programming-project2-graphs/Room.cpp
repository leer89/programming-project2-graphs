#include <string>
#include <cstdlib>
#include "Room.h"
using namespace std;

Room::Room() : name(' '), north(NULL),south(NULL),east(NULL),west(NULL){}

Room::Room(char newroom) : name(newroom), north(NULL),south(NULL),east(NULL),west(NULL){}

char Room::get_name() const
{
    return name;
}

Room* Room::get_adjacent_room(char direction) const
{
    switch(direction)
    {
        case 'N': return north;
        case 'S': return south;
        case 'E': return east;
        case 'W': return west;
    }
    return NULL;
}

void Room::link_room(char direction, Room *other) 
{
    switch(direction)
    {
        case 'N':
            north = other;
            break;
        case 'S': 
            south = other;
            break;
        case 'E': 
            east = other;
            break;
        case 'W': 
            west = other;
            break;
    }
}

string Room::get_available_directions()
{
    string directions = "";
    if(north != NULL) directions += " North(N)";
    if(south != NULL) directions += " South(S)";
    if(east != NULL) directions += " East(E)";
    if(west != NULL) directions += " West(W)";

    return directions;
}

