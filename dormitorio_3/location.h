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
    int get_count();
    void update_clean_status();
    bool get_clean_status();
    void print_Location();
    void print_Location_info();
    void set_clean_status(int i);
    void set_count(int i);
    virtual ~Location();

protected:

private:
    int room_no;
    int block_no;
    int floor_no;
    bool clean = false;
    int count = 0;
};

#endif // Location_H