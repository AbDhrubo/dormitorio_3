#include<iostream>
#include "Cleaner.h"
#include "Cook.h"
#include "Guard.h"
#include "Location.h"
#include "Person.h"
#include "Resident.h"
#include "Staff.h"
#include "Student.h"
#include "Supervisor.h"
#include "Supplier.h"
#include "Teacher.h"
#include "students.h"
#include "cooks.h"

using namespace std;

int main() 
{
	cout << "cool project" << endl;
	students s;
	Location loc(4, 5, 6);
	
	s.add_student(137, "dhrubo", "010011", "CSE", "02020", loc, 2);
	
    s.find_student(137).show_info();

	cooks c;
	Position p = Position::Head;
	Meal m = Meal::Breakfast;
	c.add_cook(135, "Sad man", "012383", 700, 180, p, m);

	c.find_cook(135).show_info();
	//c.find_cook(136).show_info();
}