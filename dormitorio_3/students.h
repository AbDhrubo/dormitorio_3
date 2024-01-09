#pragma once
#include "Student.h"
#include<vector>

class students
{
private:
	vector<Student> arr;

public:
	void add_student(int ID, string name, string contact_no, string dept,
		string emergency_no, int loc, int _year, int late, bool meet, bool on_leave, bool visitor, int present);
	int remove_student(int ID);
	int student_entry(int ID);
	void student_exit(int ID);
	Student* find_student(int ID);
	void show_info(int i, vector <Location> &locco);

	Student& operator [](int n)
	{
		if (n < 0 || n >= arr.size())
		{
			cout << "Index out of bounds"; 
		}
			return arr[n];
	}
};

