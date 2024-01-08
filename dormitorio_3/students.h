#pragma once
#include "Student.h"
#include<vector>

class students
{
private:
	vector<Student> arr;
public:
	/*students() {
	}*/
	void add_student(int ID, string name, string contact_no, string dept,
		string emergency_no, Location* loc, int _year);
	int remove_student(int ID);
	int student_entry(int ID);
	void student_exit(int ID);
	Student* find_student(int ID);
};

