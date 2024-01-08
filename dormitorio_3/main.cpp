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

using namespace std;

int main() 
{
	cout << "cool project" << endl;
	students s;
	Location loc(4, 5, 6);
	
	s.add_student(137, "dhrubo", "010011", "CSE", "02020", loc, 2);
	
    s.find_student(137).show_info();
}