#pragma once
#ifndef Location_H
#define Location_H
#include<iostream>
using namespace std;

class Location {
public:
    //Location();
    Location(int _roomno, int _blockno, int _floorno);
    int get_roomno();
    int get_blockno();
    int get_floorno();
    void print_Location();
    virtual ~Location();

protected:

private:
    int room_no;
    int block_no;
    int floor_no;

};

#endif // Location_H