
#pragma once
#include "Teacher.h"
#include<vector>

class Teachers
{
private:
	vector<Teacher> arr;
public:
	/*students() {
	}*/
	void add_Teacher(int i, string n, string cn, string em_cn, string _dept, int loc, T_Position p);
	int remove_Teacher(int ID);
	int Teacher_entry(int ID);
	void Teacher_exit(int ID);
	Teacher find_Teacher(int ID);
};