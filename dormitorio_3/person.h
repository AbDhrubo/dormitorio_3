#pragma once
#include<iostream>
using namespace std;
class person
{
private:
	string name;
	int id;
	string cont_no;
public:
	void set_name(string& _name) {
		name = _name;
	}
	void set_id(int& _id) {
		id = _id;
	}
	void set_cont(string& _cont) {
		cont_no = _cont;
	}
	string get_name() { return name; }
	string get_cont() { return cont_no; }
	int get_id() { return id; }
};

