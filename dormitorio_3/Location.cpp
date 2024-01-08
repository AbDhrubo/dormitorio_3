#include "Location.h"

//Location::Location()
//{
//    //ctor
//}
Location::Location(int _roomno, int _blockno, int _floorno) :room_no(_roomno), block_no(_blockno), floor_no(_floorno)
{

}

Location::~Location()
{

}
int Location::get_roomno()
{
    return room_no;
}

int Location::get_blockno()
{
    return block_no;
}

int Location::get_floorno()
{
    return floor_no;
}

void Location :: print_Location() {
    cout << "Room: " << room_no << ", Floor: " << floor_no << ", Block: " << block_no << endl;
}

void Location::update_clean_status() {
    clean = clean ^ 1;
}

bool Location::get_clean_status() {
    return clean;
}