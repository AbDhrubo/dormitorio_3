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

int Location::get_count()
{
    return count;
}

void Location :: print_Location() {
    cout << "Room: " << floor_no << 0 << room_no << ", Floor: " << floor_no << ", Block: " << block_no << endl;
}

void Location::print_Location_info()
{
    cout << "Status: " << clean << "Total Resident: " << count << " ";
    print_Location();
}

void Location::update_clean_status() {
    clean = clean ^ 1;
}

bool Location::get_clean_status() {
    return clean;
}

void Location::set_clean_status(int i)
{
    if (i) clean = true;
    else clean = false;
}

void Location::set_count(int i)
{
    count = i;
}