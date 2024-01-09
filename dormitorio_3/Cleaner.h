#pragma once
#include "Staff.h"

enum class Block { HB1, HB2, HB3 };

class Cleaner :public Staff
{
private:
    int floor;
    int target = 0;
    int completed = 0;
    Block block;

public:
    Cleaner(int i, string n, string cn, string t, int d, int f, Block b) :Staff(i, n, cn, t, d), floor(f), block(b) {}

    void set_floor(int f)
    {
        floor = f;
    }
    void set_target(int t)
    {
        target = t;
    }
    void set_completed(int c)
    {
        completed = c;
    }
    void set_block(Block b)
    {
        block = b;
    }
    int get_floor()
    {
        return floor;
    }
    int get_target()
    {
        return target;
    }
    int get_completed()
    {
        return completed;
    }
    string get_block()
    {
        if (block == Block::HB1)
            return string("HB1");
        else if (block == Block::HB2)
            return string("HB2");
        else if (block == Block::HB3)
            return string("HB3");
    }
    void show_info() override;
};