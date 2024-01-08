#include "Supplier.h"
void Supplier::show_info() 
{
    cout << "ID: " << id << endl
        << "Name: " << name << endl
        << "Contact No: +88" << cont_no << endl
        << "Job: " << get_type() << endl << endl;
}