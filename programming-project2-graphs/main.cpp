#include <iostream>
#include <stdlib.h>
#include "Room.h"
using namespace std;

int main() {
    typedef Room* RoomPtr;
    RoomPtr a,b,c,d,e,f,g,h,i,j,k,l;
    a = new Room('A');
    b = new Room('B');
    c = new Room('C');
    d = new Room('D');
    e = new Room('E');
    f = new Room('F');
    g = new Room('G');
    h = new Room('H');
    i = new Room('I');
    j = new Room('J');
    k = new Room('K');
    l = new Room('L');

    a->link_room('E', b); b->link_room('W', a);
    a->link_room('S', e); e->link_room('N', a);
    e->link_room('S', i); i->link_room('N', e);
    i->link_room('E', j); j->link_room('W', i);
    b->link_room('S', f); f->link_room('N', b);
    f->link_room('E', g); g->link_room('W', f);
    g->link_room('N', c); c->link_room('S', g);
    c->link_room('E', d); d->link_room('W', c);
    g->link_room('S', k); k->link_room('N', g);
    g->link_room('E', h); h->link_room('W', g);
    h->link_room('S', l); l->link_room('N', h);

    RoomPtr curr = a;
    char new_direction;
    do
    {
        cout << "You are in room " << curr->get_name() << " and can go " << curr->get_available_directions() << " or (q)uit. " << endl;

        cin >> new_direction;
        new_direction = new_direction;
        if(new_direction == 'Q')
        {
            exit(1);
        }

        RoomPtr next_room = curr->get_adjacent_room(new_direction);
        if(next_room == NULL)
            cout << "Invalid selection." << endl;
        else
            curr = next_room;
    }while(curr->get_name() != 'L');
    cout << "Reached the end of maze." << endl;
    
    return 0;
}